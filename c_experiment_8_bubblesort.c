#include <stdio.h>
void bubble_printarray(int a[], int n)   
{  
    int i;  
    for(i = 0; i < n; i++)    
    {    
        printf("%d ",a[i]);    
    }        
}  
void bubblesort(int a[], int n)   
{  
   int i, j, temp;  
   for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }     
}
 void insertsort(int a[], int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<=a[j])
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

void insert_printarray(int a[], int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d  ", a[i]);
    }
}
void selection_sort(int a[], int n)  
{  
    int i, j, small;  
      
    for (i = 0; i < n-1; i++)     
    {  
        small = i;  
          
        for (j = i+1; j < n; j++)  
        if (a[j] < a[small])  
            small = j;  
  
    int temp = a[small];  
    a[small] = a[i];  
    a[i] = temp;  
    }  
}
void selectionsort_printarray(int a[],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
}    
void main()
{
    int i,n,opt;
    printf("Enter the no of elements you want\n");
    scanf("%d",&n);
    int a[n];
    for ( i = 0; i < n; i++)
    {
        printf("Enter your element\n");
        scanf("%d",&a[i]);
    }
    
    int r=1;
    do
    {
        printf("\nMENU\n");
        printf("1. FOR IMPLEMENTING INSERTION SORT\n");
        printf("2. FOR IMPLEMENTING BUBBLE SORT\n");
        printf("3. FOR IMPLEMENTING SELECTION SORT\n");
        printf("4. FOR EXITING THIS MENU\n");
        scanf("%d",&opt);
        if(opt==1)
        {
            printf("Now we will be implementing Insertion Sort\n");
            insertsort(a,n);
            insert_printarray(a,n);

        }
        else if (opt==2)
        {
            printf("Now we will be implementing Bubble Sort\n");
            bubblesort(a,n);
            bubble_printarray(a,n);
        }
        else if (opt==3)
        {
            printf("Now we will be implementing Selection Sort\n");
            selection_sort(a,n);
            selectionsort_printarray(a,n);
        }
        else
        {
            r=0;
        }
        
        
    } while (r>0);
    
    

}
 