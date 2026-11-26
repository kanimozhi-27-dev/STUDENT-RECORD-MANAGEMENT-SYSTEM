#include"student.h"
void stud_add(SLL **ptr)
{
        SLL *new;
        new=malloc(sizeof(SLL));

        printf(BOLD ITALIC SKY_BLUE"Enter the student's Roll NUmber name and percentage:\n"RST);
        scanf("%d %s %f", &new->rollno, new->name,&new->percentage);
        new->next=*ptr;
        *ptr=new;
}

