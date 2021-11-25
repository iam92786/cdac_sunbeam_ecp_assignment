/*5. An inventory management system needs to manage data of the items into binary file. Each item has
id, name, price and quantity. Write a menu-driven program to implement add, find, display all, edit
and delete operations from the items file. Order id (int) should be generated automatically and must
be unique */
#include<stdio.h>
#include<stdio.h>

typedef struct inventry
{
    int id;
    char name[20];
    float price;
    int quant;
}inv;
typedef enum {add = 1, find, display_all, edit, delete}choice;

void inventry_add(inv*, int);
void Print_data(inv*, int);
int main (void)
{
    inv arr[20];
    char str[20];
    int index,  a = 0, d = 0, ret;
    FILE *fp = fopen("que05.txt","w");
    fclose(fp);
    choice cho;
    do
    {   //menu driven approch to select the oprations
        printf("\n>>Menu<<\n1.Add\n2.Find\n3.Display All\n4.Edit\n5.Delete from the items File\n6.Exit\n");
        printf("Enter Your Choice HERE : ");
        scanf("%d",&cho);
 
        switch (cho)
        {
        case add : //add new item entry 
            
            inventry_add(arr+a,a);
            fp = fopen("que05.txt","a");
            fwrite((arr+a),sizeof(arr+a),1,fp);            
            fclose(fp);
            ++a;
            break;

        case find:  //find the item detal individually
        index = 0;
            printf("Enter Items Id number : ");
            scanf("%d",&index);

            fp = fopen("que05.txt","a");
            fread((arr+index),sizeof(arr+index),1,fp);   
            printf("\nId\tItem\tPrice\tQuantity\n");
            Print_data(arr+index,index);
                 
            fclose(fp);
            break;
                 
            printf("No Match Found");
            break;
        case display_all:
            d = 0;
            fp = fopen("que05.txt","r");
            while (ret = fread((arr+d),sizeof(inv),1,fp) != '\0')
            {
                printf("%d",ret);
                printf("\nId\tItem\tPrice\tQuantity\n");
                Print_data(arr+d,d);

            }
            fclose(fp);
            d = 0;
            break;
        case edit:
            fp = fopen("que05.txt","a");
            printf("Enter Items Id number : ");
            scanf("%d",&index);
            inventry_add(arr+index,index);
            
            fclose(fp);
            break;
        case delete:
            //Delet all entry 
            remove("que05.txt");
            printf("\nAll Item Data is deleted\n");
            break;
        }

    } while (cho != 0);

    return 0;
}
void Print_data(inv* inv, int ind) //Function for Print Item Details
{
    printf("%d\t%s\t%0.2f\t%d",ind,inv->name,inv->price,inv->quant);
}
void inventry_add(inv* inv, int ind) //function for add new Item detail
{
    
    printf("Add Inventry, id = %d\n",ind);
    printf("items Name : ");
    scanf("%s",inv->name);
    
    printf("Quantity : ");
    scanf("%d",&inv->quant);

    printf("Price : ");
    scanf("%f",&inv->price);

}