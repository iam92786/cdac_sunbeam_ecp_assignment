//Write a function to sort array which takes comparator function as an argument. Where the
//comparator function takes two elements of array which are to be compared as arguments and
//contains logic to compare elements in array

#include<stdio.h>

int arrary_sort(int arr[]);
int comp(int, int);
void print_array(int arr[]);

int main (void)
{
    int arr[5];
    //1st = 11,22,44,33,55 //2nd = 11,22,44,33,55
    //3rd = 11,22,33,44,55 4th = , 5th
    printf("Enter arrya elements : ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    print_array(arr);
    arrary_sort(arr);
    print_array(arr);
    return 0;
}

int arrary_sort(int arr[])
{
    int temp;
    int (*funptr)(int,int);
    funptr = comp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            //if(arr[i] > arr[j])
            if(comp(arr[i],arr[j]))
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

        }
        
    }
    
}
int comp(int num1, int num2)
{ //if (num1 > num2) => positive (return > 0)
    //else ( return < 0)
    return num1 - num2;
}

void print_array(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    
}