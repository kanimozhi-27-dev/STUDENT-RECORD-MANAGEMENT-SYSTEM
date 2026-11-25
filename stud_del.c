#include"student.h"
void stud_del(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("No students records available.\n");
                return;
        }

        char name[50],op;
        int roll;
        SLL *del=*ptr;
        SLL *prev=0;
        printf("R/r : Delete by Rollnumber:\n");
        printf("N/n : Delete by Name:\n");
        scanf(" %c", &op);
        op=tolower(op);

        if(op=='n')
        {
                printf("Enter the name to delete:\n");
                scanf("%s",name);
        while(del)
        {
        if(strcmp(del->name,name)==0)
        {
                if(del==*ptr)
                {
                        *ptr=del->next;
                }
                else
                {
                        prev->next=del->next;
                }
                free(del);
        }
        prev=del;
        del=del->next;
        printf("Name not found\n");
        }
        }
        else if(op=='r')
        {
                printf("Enter the Rollno to delete:\n");
                scanf("%d",&roll);
                while(del)
                {
                        if(del->rollno == roll)
                        {
                                if(del==*ptr)
                                {
                                        *ptr=del->next;
                                }
                                else
                                {
                                        prev->next=del->next;
                                }
                                free(del);
                        }
                        prev=del;
                        del=del->next;
                }
        }
        else
                printf("Rollno not found\n");
}	
