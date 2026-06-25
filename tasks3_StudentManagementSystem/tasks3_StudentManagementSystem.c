#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    struct Student s;
    FILE *fp, *temp;
    int choice, roll, found;

    while(1)
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                fp = fopen("student.txt", "a");

                printf("Enter Roll No: ");
                scanf("%d", &s.roll);

                printf("Enter Name: ");
                scanf("%s", s.name);

                printf("Enter Marks: ");
                scanf("%f", &s.marks);

                fprintf(fp, "%d %s %.2f\n",
                        s.roll, s.name, s.marks);

                fclose(fp);
                printf("Student Added Successfully!\n");
                break;

            case 2:
                fp = fopen("student.txt", "r");

                printf("\nRoll\tName\tMarks\n");

                while(fscanf(fp, "%d %s %f",
                             &s.roll,
                             s.name,
                             &s.marks) != EOF)
                {
                    printf("%d\t%s\t%.2f\n",
                           s.roll,
                           s.name,
                           s.marks);
                }

                fclose(fp);
                break;

            case 3:
                fp = fopen("student.txt", "r");

                printf("Enter Roll No to Search: ");
                scanf("%d", &roll);

                found = 0;

                while(fscanf(fp, "%d %s %f",
                             &s.roll,
                             s.name,
                             &s.marks) != EOF)
                {
                    if(s.roll == roll)
                    {
                        printf("\nRecord Found\n");
                        printf("Roll No: %d\n", s.roll);
                        printf("Name: %s\n", s.name);
                        printf("Marks: %.2f\n", s.marks);
                        found = 1;
                    }
                }

                if(found == 0)
                    printf("Record Not Found!\n");

                fclose(fp);
                break;

            case 4:
                fp = fopen("student.txt", "r");
                temp = fopen("temp.txt", "w");

                printf("Enter Roll No to Update: ");
                scanf("%d", &roll);

                found = 0;

                while(fscanf(fp, "%d %s %f",
                             &s.roll,
                             s.name,
                             &s.marks) != EOF)
                {
                    if(s.roll == roll)
                    {
                        printf("Enter New Name: ");
                        scanf("%s", s.name);

                        printf("Enter New Marks: ");
                        scanf("%f", &s.marks);

                        found = 1;
                    }

                    fprintf(temp, "%d %s %.2f\n",
                            s.roll, s.name, s.marks);
                }

                fclose(fp);
                fclose(temp);

                remove("student.txt");
                rename("temp.txt", "student.txt");

                if(found)
                    printf("Record Updated Successfully!\n");
                else
                    printf("Record Not Found!\n");

                break;

            case 5:
                fp = fopen("student.txt", "r");
                temp = fopen("temp.txt", "w");

                printf("Enter Roll No to Delete: ");
                scanf("%d", &roll);

                found = 0;

                while(fscanf(fp, "%d %s %f",
                             &s.roll,
                             s.name,
                             &s.marks) != EOF)
                {
                    if(s.roll == roll)
                    {
                        found = 1;
                        continue;
                    }

                    fprintf(temp, "%d %s %.2f\n",
                            s.roll, s.name, s.marks);
                }

                fclose(fp);
                fclose(temp);

                remove("student.txt");
                rename("temp.txt", "student.txt");

                if(found)
                    printf("Record Deleted Successfully!\n");
                else
                    printf("Record Not Found!\n");

                break;

            case 6:
                printf("Thank You!\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}