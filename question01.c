//1. Input a string from user on command line. String may have multiple commas e.g.
//"Welcome,to,Sunbeam,CDAC,Diploma,Course". Print each word individually.
#include<stdio.h>
#include<string.h>
//command Line Argument
int main (int argc, char *argv[])
{

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] == ',')  //To check whether is is comma"," or not.
            printf("\n");
        else
            printf("%c",argv[1][i]); //print each character except comma "," .
        
    }
    
    return 0;
}