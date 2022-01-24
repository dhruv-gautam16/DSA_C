#include <stdio.h>
#include <stdlib.h>
#define size 100
void input_array(int array[],int n){
    int i;
    printf("pls enter elements one by one\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    
}
int print_array(int array[],int n){
    int i;
    printf("now we are printing the values of element in array\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",array[i]);
    }
    
}
int binary_search(int array[],int n,int search){
  int first,last,middle;
  first = 0;
  last = n - 1;
  middle = (first+last)/2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      printf("%d found at location %d.\n", search, middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);

  return 0;
}


int deletion(int array[],int search,int n){
  int first,last,middle;
  first = 0;
  last = n - 1;
  middle = (first+last)/2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      array[middle]=0;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }

  return 0;
    

}
void main(){
    int a = 1;
    int opt,b,c,d;
    int arr[size];
   
    do
    {
        printf("             MENU\n");
        printf("SELECT one thing in the menu \n");
        printf("1.for creation of an array\n");
        printf("2. for searching an element in the array\n");
        printf("3 for deleting an element in the array\n");
        printf("4. for exiting this menu\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            printf("enter the number of elements you want\n");
            scanf("%d",&b);
            input_array(arr,b);
            print_array(arr,b);
        }
        else if (opt==2)
        {
            printf("pls enter the element you want to search for\n");
            scanf("%d",&c);
            binary_search(arr,b,c);

        }
        else if (opt==3)
        {
            printf("enter the element you want to delete\n");
            scanf("%d",&d);
            deletion(arr,d,b);
            print_array(arr,b);
        }
        else if (opt==4)
        {
            printf("we are exiting this menu\n");
            a=0;
        }
    } while (a>0);  
}