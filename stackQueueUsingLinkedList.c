#include <stdio.h>
#include <stdlib.h>
struct Node
{
   int data;
   struct Node *next;
}*top = NULL;

struct Q_node   
{  
    int data;   
    struct Q_node *next;  
}; 

struct Q_node *front;  
struct Q_node *rear; 

void enqueue();

void dequeue();

void queue_display();  

void push(int);
void pop();
void stack_display();
void main(){
    int r =1;
    int opt;
    do
    {
        printf("Please Select What you want to implement\n");
        printf("MENU\n");
        printf("1. For implementing Stack using Linked List\n");
        printf("2. For implementing Queue using Linked List\n");
        printf("3. For Exiting this menu\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            int k =1;
            int opt_1;
            do
            {
                printf("SubMENU\n");
                printf("1. For Push ()\n");
                printf("2. For Pop()\n");
                printf("3. For Display()\n");
                printf("4. For Exiting this SubMENU\n");
                printf("Please Select Your Number\n");
                scanf("%d",&opt_1);
                if (opt_1==1)
                {
                    int c;
                    printf("Enter your Element\n");
                    scanf("%d",&c);
                    push(c);

                }
                else if (opt_1==2)
                {
                    pop();
                   
                }
                else if (opt_1==3)
                {
                    stack_display();
                }
                else if(opt_1==4)
                {
                    k=0;
                }
                
                
                

            } while (k>0);
           
        }
        else if(opt==2)
        {
            int z = 1;
            int opt_2;
            do
            {
              printf("SubMENU\n");
              printf("1. For Enqueue ()\n");
              printf("2. For Dequeue () \n");
              printf("3. For Display() \n");
              printf("4. For exiting this SubMENU\n");
              printf("Please select what you want to do \n");
              scanf("%d",&opt_2);

              if (opt_2==1)
              {
                  enqueue();
              }
              else if (opt_2==2)
              {
                  dequeue();
              }
              else if (opt_2==3)
              {
                  queue_display();
              }
              else if (opt_2==4)
              {
                  z=0;
              }
              
              
              
                
            } while (z>0);
            
        }
        else if (opt==3)
        {
            r=0;
        }
        
        
        
    } while (r>0);
    
    
    
}

void push(int c)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = c;
   if(top == NULL)
   {
      newNode->next = NULL;
   }
   else
   {
      newNode->next = top;
   }
   top = newNode;
   
}
void pop()
{
   if(top == NULL)
   {
      printf("Stack is Empty\n");
   }
   else
   {
      struct Node *temp = top;
      printf("Deleted element is : %d\n", temp->data);
      top = temp->next;
      free(temp);
   }
}
void stack_display()
{
   if(top == NULL)
   {
      printf("Stack is Empty!!!\n");
   }
   else
   {
      struct Node *temp = top;
      while(temp->next != NULL){
          printf("%d\n",temp->data);
	      temp = temp -> next;
      }
      printf("%d\n",temp->data);
   }
}
void enqueue()  
{  
    struct Q_node *ptr;  
    int item;   
      
    ptr = (struct Q_node *) malloc (sizeof(struct Q_node));  
    if(ptr == NULL)  
    {  
        printf("Queue is Overflow\n");  
        return;  
    }  
    else  
    {   
        printf("Enter value fo your element \n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}
void dequeue()  
{  
    struct Q_node *ptr;  
    if(front == NULL)  
    {  
        printf("Queue is Underflow\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void queue_display()  
{  
    struct Q_node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("Queue is Empty\n");  
    }  
    else  
    {   printf("Displaying Elements\n") ;
        while(ptr != NULL)   
        {  
            printf("%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}       