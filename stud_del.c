#include"student.h"
void stud_del(SLL **ptr)
{
        if(*ptr==0)
        {
                printf(BOLD RED"No students records available.\n"RST);
                return;
        }

        char name[50],op;
        int roll,c=0;
        SLL *del=*ptr;
        SLL *prev=0;
        printf("R/r : Enter roll number to delete\n");
        printf("N/n : Enter name to delete\n");
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
				c++;
				roll=del->rollno;
				printf("%d %s %f\n",del->rollno,del->name,del->percentage);
			}
			del=del->next;
		}
		if(c==0)
		{
			printf("Name not found\n");
			return;
		}
		if(c>1)
		{
			printf(BOLD RED ITALIC"Enter the rollno to delete the name\n"RST);
			scanf("%d",&roll);
		}
		del=*ptr;
		prev=0;

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
				printf("Deletion by name done sunccessfully\n");
				break;
                        }
                        prev=del;
                        del=del->next;
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
