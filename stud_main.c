#include"student.h"
int main()
{
	SLL *headptr=0;
	load_file(&headptr);
	char op;
	while(1)
	{
		printf(BOLD CYAN"********STUDENT RECORD MENU ********\n" RST);
		printf(ITALIC" a/A : Add new record\n d/D : Delete a record\n s/S : Show the list\n m/M : Modify a record\n v/V : Save records\n e/E : Exit\n t/T : Sort the list\n l/L : Delete all the records\n r/R : Reverse the list\n"RST);
		printf(BOLD ITALIC"Enter your choice:\n"RST);
		scanf(" %c", &op);
		op=tolower(op);
		switch(op)
		{
			case 'a' : stud_add(&headptr);break;
			case 'd' : stud_del(&headptr);break;
			case 's' : stud_show(headptr);break;
			case 'm' : stud_mod(headptr);break;
			case 'v' : stud_save(headptr);break;
			case 'e' : stud_exit(headptr);break;
			case 't' : stud_sort(headptr);break;
			case 'l' : stud_delNode(&headptr);break;
			case 'r' : stud_reverse(&headptr);break;
			default  : printf(BOLD RED"Invalid option!\n"RST); 
		}
	}
	return 0;
}



int stud_count(SLL *ptr)
{
	int c=0;

	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}

void stud_sort(SLL *ptr)
{
	if(ptr==0)
	{
		printf(BOLD RED"No students records available\n"RST);
		return;
	}

	int i,j,c=stud_count(ptr);
	SLL *p1=ptr,*p2,t;
	char name[50],op;
	float percent;
	printf(BOLD LAVENDER"N/n : Sort with name\n"RST);
	printf(BOLD LAVENDER"P/p : Sort with percentage\n"RST);
	scanf(" %c", &op);

	if(op=='n')
	{
		for(i=0;i<c-1;i++)
		{
			p2=p1->next;
			for(j=0;j<c-1-i;j++)
			{
				if(strcmp(p1->name,p2->name)>0)
				{
					t.rollno=p1->rollno;
					strcpy(t.name,p1->name);
					t.percentage=p1->percentage;

					p1->rollno=p2->rollno;
					strcpy(p1->name,p2->name);
					p1->percentage=p2->percentage;

					p2->rollno=t.rollno;
					strcpy(p2->name,t.name);
					p2->percentage=t.percentage;
				}
				p2=p2->next;
			}
			p1=p1->next;
		}
	}

	else if(op=='p')
	{
		for(i=0;i<c-1;i++)
		{
			p2=p1->next;
			for(j=0;j<c-1-i;j++)
			{
				if(p1->percentage < p2->percentage)
				{
					t.rollno=p1->rollno;
					strcpy(t.name,p1->name);
					t.percentage=p1->percentage;

					p1->rollno=p2->rollno;
					strcpy(p1->name,p2->name);
					p1->percentage=p2->percentage;

					p2->rollno=t.rollno;
					strcpy(p2->name,t.name);
					p2->percentage=t.percentage;
				}
				p2=p2->next;
			}
			p1=p1->next;
		}
	}

}

void stud_delNode(SLL **ptr)
{
	if(*ptr==0)
	{
		printf(BOLD RED"No student records found\n"RST);
		return;
	}
	int c=1;
	SLL *del=*ptr;
	while(del)
	{
		*ptr=del->next;
		sleep(1);
		printf("Node position : %d deleted\n",c++);
		free(del);
		del=*ptr;
	}
	printf(BOLD ITALIC GREEN"All students records are deleted successfully\n"RST);

}

void stud_reverse(SLL **ptr)
{
	if(*ptr==0)
	{
		printf(BOLD RED"No students records are found\n"RST);
		return;
	}

	int i,c=stud_count(*ptr);
	if(c>1)
	{
		SLL **a=malloc(sizeof(SLL*)*c);
		SLL *t=*ptr;
		for(i=0;i<c;i++)
		{
			a[i]=t;
			t=t->next;
		}
		for(i=c-1;i>0;i--)
		{
			a[i]->next=a[i-1];
			a[0]->next=0;
			*ptr=a[c-1];
		}
	}
}

void stud_exit(SLL *ptr)
{
	char op;
	SLL *temp;
	printf(BOLD LAVENDER"S/s : Save and exit\n"RST);
	printf(BOLD LAVENDER"E/e : Exit without saving\n"RST);
	scanf(" %c", &op);
	op=tolower(op);
	if(op=='s')
	{
		stud_save(ptr);
		while(ptr)
		{
			temp=ptr;
			ptr=ptr->next;
			free(temp);
		}
		exit(0);
	}

	else if(op=='e')
	{
		exit(0);
	}
}

void load_file(SLL **ptr)
{

	FILE  *fp=fopen("student.dat","r");
	if(fp==0)
	{
		return;
	}

	SLL *new=*ptr;
	while(1)
	{
		new=malloc(sizeof(SLL));
                if(new==0)
                {
                        break;
                }

		if((fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage))!=3)
		{
                        free(new);
			break;
		}
		else
		{
			new->next=0;
			if(*ptr==0)
			{
				*ptr=new;
			}
			else
			{
				SLL *last=*ptr;
				while(last->next)
					last=last->next;

				last->next=new;
			}
		}
	}
        fclose(fp);
}
