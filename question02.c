/*2. Write functions to allocate memory for 2 dimensional matrices dynamically. Write another function
to free the memory allocated for 2 dimensional matrices. Write functions to calculate addition,
subtraction, multiplication of two matrices of 3x3.*/
#include<stdio.h>
#include<stdlib.h>

typedef enum menu{
    EXIT, ADD, SUB, MUL
} menu_t;

int** make_matrix( int , int );    // allocating an matrix
void enter_matrix( int**, int, int );       // take values from user to fill matrix
void free_matrix( int**, int, int );  // free memory of matrix
void disp_matrix( int**, int, int);      // to display a matrix

void add_matrix( int**, int**, int**, int, int);
void sub_matrix( int**, int**, int**, int, int);
void mul_matrix( int**, int**, int**, int, int);

int main(void)
{
    int **a, **b;
    int rows, columns;
    menu_t choice;

    printf("Enter rows and columns for matrix : ");
    scanf("%d %d", &rows, &columns);
    
    a = make_matrix(rows, columns);
    printf("Enter values of matrix a :\n");
    enter_matrix(a, rows, columns);

    b = make_matrix(rows, columns);
    printf("Enter values of matrix b :\n");
    enter_matrix(b, rows, columns);

    int **c = make_matrix(rows, columns);   // to store result of arthematic functions

    do
    { //menu driven programm
        printf("0.EXIT  1.ADD  2.SUB  3.MUL\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case ADD:
            add_matrix( a, b, c, 3, 3);
            break;
        case SUB:
            sub_matrix( a, b, c, 3, 3);
            break;
        case MUL:
            mul_matrix( a, b, c, 3, 3);
            break;
        case EXIT:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
        printf("resultant is \n");
        disp_matrix(c, 3, 3);
    }while(choice != 0);

    free_matrix(a, rows, columns); free(a); 
    free_matrix(b, rows, columns); free(b);
    free_matrix(c, rows, columns); free(c);    
    
    return 0;
}


// memory Allocate for matrix


int** make_matrix(int rows, int columns)
{
    int i, j;
    
    int **arr = (int**)malloc(sizeof(int*));

    for (i = 0; i < rows; i ++)
        arr[i] = (int*)malloc(columns * sizeof(int));

    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
            arr[i][j] = 0;

    printf("\n");
    return arr;
}

// Enter matrix element

void enter_matrix(int **arr, int rows, int columns)
{
    int i,j;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
}

//function to free memory of matrix

void free_matrix( int **arr, int rows, int columns )
{
    int i, j;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
            free(&arr[i][j]);  
        free(arr[i]);
}


// addition 

void add_matrix( int **a, int **b, int **c, int rows, int columns)
{
    int i, j;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
            c[i][j] = a[i][j] + b[i][j];
}


// subtraction

void sub_matrix( int **a, int **b, int **c, int rows, int columns)
{
    int i, j, k;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
            c[i][j] = a[i][j] - b[i][j];
}

// multiplication of matrices

void mul_matrix( int **a, int **b, int **c, int rows, int columns)
{
    int i, j,k, sum;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
        {
            sum = 0;
            for(k = 0; k < 3 ; k++)
                sum = (a[i][k]*b[k][i]) + sum;
            c[i][j] = sum;
        }
}

// Display matrix

void disp_matrix(int **arr, int rows, int columns)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
            printf("%3d", arr[i][j]);
        printf("\n");
    }
}