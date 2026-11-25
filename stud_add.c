#include"student.h"
void stud_add(SLL **ptr)
{
        SLL *new;
        new=malloc(sizeof(SLL));
        printf("Enter the student's rollno,name and percentage:\n");
        scanf("%d %s %f",&new->rollno,new->name,&new->percentage);
        new->next=*ptr;
        *ptr=new;
}

