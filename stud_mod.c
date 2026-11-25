#include"student.h"
void stud_mod(SLL **ptr)
{

        if(*ptr==0)
        {
                printf("No student records found\n");
                return;
        }

        int roll,c=0;
        char name[50],op;
        float percent;
        SLL *search=*ptr;
        SLL *prev=0;


        printf("R/r : Search by roll number\n");
        printf("N/n : Search by name\n");
        printf("P/p : Search by percentage\n");
        scanf(" %c", &op);
        op=tolower(op);
        if(op=='r')
        {
                printf("Enter the roll number to search:\n");
                scanf("%d",&roll);
                while(search)
                {
                        if(search->rollno==roll)
                        {
                                printf("%d %s %f\n",search->rollno,search->name,search->percentage);
                        printf("Enter the updated name and percentage\n");
                        scanf("%s %f", search->name,&search->percentage);
                        break;
                        }
                        search=search->next;
                }
                //free(search);
        }

        else if(op=='n')
        {
                printf("Enter the name to search:\n");
                scanf("%s",name);
                while(search)
                {
                        if(strcmp(name,search->name)==0)
                        {
                                c++;
                                printf("%d %s %f\n",search->rollno,search->name,search->percentage);
                        }
                        search=search->next;
                }
                search=*ptr;
                if(c<1)
                        {
                                printf("Enter the updated name and percentage\n");
                                scanf("%s %f",search->name,&search->percentage);
                        }
                if(c>=1)
                {
                        printf("Enter the roll number to modify the record\n");
                        scanf("%d",&search->rollno);
                        printf("Enter the updated name\n");
                        scanf("%s",search->name);
                }


        }

        else if(op=='p')
        {
                c=0;
                search=*ptr;
                printf("Enter the percentage to search from 1.00 to 100.00:\n");
                scanf("%2f",&percent);
                while(search)
                {
                        if(search->percentage == percent)
                        {
                                c++;
                                printf("%d %s %f\n",search->rollno,search->name,search->percentage);
                        }
                        search=search->next;
                }
                search=*ptr;
		if(c<1)
                {
                        printf("Enter the updated name and percentage\n");
                        scanf("%s %f",search->name,&search->percentage);
                }
                if(c>=1)
                {
                        printf("Enter the roll number to modify the record\n");
                        scanf("%d",&search->rollno);
                        printf("Enter the updated  percentage\n");
                        scanf("%f", &search->percentage);
                }

        }
}








