#include"student.h"
void stud_save(SLL *ptr)
{
        if(ptr==0)
        {
                printf("No students records available\n");
                return;
        }
        FILE *fp;
        fp=fopen("student.dat","w");
        while(ptr)
        {
                fprintf(fp,"%d %s %f",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
        printf("Student data saved successfully\n");
        fclose(fp);
}

