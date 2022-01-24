#include <stdio.h>
void enqueue();
void dequeue();
void display();
int f = -1;
int rear = -1;
void main()
{
    int r = 1;
    int opt,size;
    printf("enter the size of queue you want\n");
    scanf("%d",&size);
    int queue_array[size];
    do
    {
        printf("MENU\n Please select your operation on the queue\n");
        printf("1 for enqueue function\n");
        printf("2 for dequeue function\n");
        printf("3 for displaying your queue\n");
        printf("4 for exiting this menu\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            enqueue(queue_array,size);
        }
        else if (opt==2)
        {
            dequeue(queue_array,size);
        }
        else if (opt==3)
        {
            display(queue_array,size);
        }
        else
        {
            r=0;
        }
        
        

    } while (r>0);
    
}
void enqueue(int queue_array[],int size)
{
    int element;
    if (rear == size - 1)
    printf("Queue is Overflow \n");
    else
    {
        if (f == - 1)
        {
        f = 0;
        }
        printf("pls enter your element : ");
        scanf("%d", &element);
        rear++;
        queue_array[rear] = element;
    }
} 
 
void dequeue(int queue_array[],int size)
{
    if (f == - 1 || f > rear)
    {
        printf("Queue is Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[f]);
        f++;
    }
} 

 
void display(int queue_array[],int size)
{
    int i;
    if (f == - 1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("Displaying your queue : \n");
        for (i = f; i <= rear; i++)
        {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
} 