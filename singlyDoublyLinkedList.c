#include <stdio.h>
#include <stdlib.h>
struct dll  
{  
    struct dll *prev;  
    struct dll *next;  
    int data;  
};  
struct dll *head; 

struct cll   
{  
    int data;  
    struct cll *next;   
};  
struct cll *head_1;

void insertion_doublylink();
void delete_doublylink();
void display_doublylink();
void insertion_circularlink();
void deletion_circularlink();
void display_circularlink();

void main()
{
    int r = 1;
    int opt;
    do
    {
        printf("MENU\n");
        printf("1. For Implementing Doubly Linked List\n");
        printf("2. For Implementing Circular Linked List\n");
        printf("3. For Exiting this Menu\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            int opt_1;
            int s = 1;
            do
            {
                printf("SUBMENU of Doubly Linked List\n");
                printf("1. For Insertion()\n");
                printf("2. For Deletion()\n");
                printf("3. For Display()\n");
                printf("4. For Exiting this SUBMENU\n");
                scanf("%d",&opt_1);
                if (opt_1==1)
                {
                    insertion_doublylink();
                }
                else if (opt_1==2)
                {
                    delete_doublylink();
                }
                else if (opt_1==3)
                {
                    display_doublylink();
                }
                else if (opt_1==4)
                {
                    s=0;
                }
                
                
                
                
            } while (s>0);

        }
        else if (opt==2)
        {
          int opt_2;
            int t = 1;
            do
            {
                printf("SUBMENU of Circular Linked List\n");
                printf("1. For Insertion()\n");
                printf("2. For Deletion()\n");
                printf("3. For Display()\n");
                printf("4. For Exiting this SUBMENU\n");
                scanf("%d",&opt_2);
                if (opt_2==1)
                {
                    insertion_circularlink();
                }
                else if (opt_2==2)
                {
                    deletion_circularlink();
                }
                else if (opt_2==3)
                {
                    display_circularlink();
                }
                else if (opt_2==4)
                {
                    t=0;
                }
                
                
                
                
            } while (t>0);  
        }
        else if(opt==3)
        {
            r=0;
        }
        
        
    } while (r>0);
    
}

void insertion_doublylink()  
{  
   struct dll *ptr;   
   int ele;  
   ptr = (struct dll *)malloc(sizeof(struct dll));  
   if(ptr == NULL)  
   {  
       printf("Linked List OVERFLOW\n");  
   }  
   else  
   {  
    printf("Enter your element\n");  
    scanf("%d",&ele);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=ele;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=ele;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }   
}  
     
}

void delete_doublylink()  
{  
    struct dll *ptr;  
    if(head == NULL)  
    {  
        printf("Linked List UNDERFLOW\n");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("Node deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("Node deleted\n");  
    }  
  
} 

void display_doublylink()  
{  
    struct dll *ptr;  
    printf("Now we will be printing the values \n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
} 

void insertion_circularlink()  
{  
    struct cll *ptr,*temp;   
    int ele;   
    ptr = (struct cll *)malloc(sizeof(struct cll));  
    if(ptr == NULL)  
    {  
        printf("Linked List OVERFLOW\n");  
    }  
    else   
    {  
        printf("Enter Your Element \n");  
        scanf("%d",&ele);  
        ptr -> data = ele;  
        if(head_1 == NULL)  
        {  
            head_1 = ptr;  
            ptr -> next = head_1;  
        }  
        else   
        {     
            temp = head_1;  
            while(temp->next != head_1)  
                temp = temp->next;  
            ptr->next = head_1;   
            temp -> next = ptr;   
            head_1 = ptr;  
        }   
        printf("Node Inserted\n");  
    }  
              
}  

void deletion_circularlink()  
{  
    struct cll *ptr;   
    if(head_1 == NULL)  
    {  
        printf("Linked List UNDERFLOW\n");    
    }  
    else if(head_1->next == head_1)  
    {  
        head_1 = NULL;  
        free(head_1);  
        printf("Node deleted\n");  
    }  
      
    else  
    {   ptr = head_1;   
        while(ptr -> next != head_1)  
            ptr = ptr -> next;   
        ptr->next = head_1->next;  
        free(head_1);  
        head_1 = ptr->next;  
        printf("Node deleted\n");  
  
    }  
} 

void display_circularlink()  
{  
    struct cll *ptr;  
    ptr=head_1;  
    if(head_1 == NULL)  
    {  
        printf("No Values to Print\n");  
    }     
    else  
    {  
        printf("Now we will be printing Elements\n");  
          
        while(ptr -> next != head_1)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
              
}