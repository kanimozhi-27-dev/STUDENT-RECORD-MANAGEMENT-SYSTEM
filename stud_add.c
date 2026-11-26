#include"student.h"
void stud_add(SLL **ptr)
{
	SLL *new=*ptr;
	new=malloc(sizeof(SLL));
        if(new==0)
        {
        printf(BOLD RED "Memory not allocated"RST" \n");
        return;
        }

	int roll=1;
	while(isroll(roll,*ptr))
	{
		roll++;
	}


        new->rollno=roll;
	printf(BOLD UND CYAN "Enter name and percentage"RST"\n");
	scanf("%s %f",new->name,&new->percentage);
	if(new->percentage < 0.0f || new->percentage > 100.0f)
	{
		printf(BOLD RED "Invalid percentage. Enter between 0.00 and 100.00"RST "\n");
		free(new);
		return;
	}

	new->next=0;
	if(*ptr==0)
	{
		*ptr=new;
	}
	else
	{
		SLL *last=*ptr;
		while(last->next)
		{
			last=last->next;
		}

		last->next=new;
	}
}
int isroll(int num,SLL *ptr)
{
if(ptr==0)
return 0;
while(ptr)
{
if(ptr->rollno==num)
return 1;
ptr=ptr->next;
}
return 0;
}
