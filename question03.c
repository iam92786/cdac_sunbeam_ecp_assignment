/*3. Write a structure to store school student information. The student result is one of the members of
this information. Note that till 4th standard school follows grade scheme (A / B / C) and after 4th
standard it follows percentage pattern. Create array of 5 students, accept the information of 5
students from the user and store into array. Also display information of students on console in tabular
forma
*/
#include<stdio.h>
union result
{
    char grade;
    float per;
};
typedef struct student
{
    int rollno;
    char name[20];
    int std;
    union result result;
}stud;
void accept_student_data(stud *, int);
void print_student_data(stud *);

int main (void)
{
    //stud s1;
    stud arr[5];

    for (int i = 0; i < 5; i++)
        accept_student_data(arr+i, i);
    
    printf("Roll no ||   Name    || std  || Grade\n");
    for(int i = 0; i< 5; i++)
        print_student_data(arr+i);

    return 1;
}
void accept_student_data(stud *s, int count)
{
    printf("\nEntry no %d\n",count+1);
    printf("Roll no :");
    scanf("%d",&s->rollno);
    printf("Name : ");
    scanf("%s",s->name);
    printf("std : ");
    scanf("%d",&s->std);

    if (s->std <= 4)
    {
        printf("Grade (A/B/C): ");
        scanf("%*c%c",&s->result.grade);
    }else{
        printf("Percentage : ");
        scanf("%f",&s->result.per);
    }
}
void print_student_data(stud *s)
{   printf("%d\t   %s\t\t%d\t",s->rollno,s->name,s->std);
     if (s->std < 5)
    {
        printf(" %c\n",s->result.grade);
       
    }else{
        printf(" %0.2f\n",s->result.per);
    }
    //return 1;
}