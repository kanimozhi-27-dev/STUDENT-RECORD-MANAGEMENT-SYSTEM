#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>

#define MAGENTA "\033[95m"
#define RST     "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define UND     "\033[4m"
#define CORAL   "\033[38;2;255;127;80m"
#define MINT    "\033[38;2;152;255;152m"
#define ORANGE  "\033[38;5;208m"
#define PINK    "\033[38;5;205m"
#define PURPLE  "\033[38;5;129m"
#define GOLD    "\033[38;5;220m"
#define TEAL    "\033[38;5;37m"

typedef struct student
{
        int rollno;
        char name[50];
        float percentage;
        struct student *next;
}SLL;
void stud_add(SLL **);
void stud_show(SLL *);
void stud_del(SLL **);
int stud_count(SLL *);
void stud_mod(SLL **);
void stud_save(SLL *);
void stud_sort(SLL *);
void stud_delNode(SLL **);
void stud_reverse(SLL **);
void stud_exit(SLL *);
