#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


void printList() {

   struct node *ptr = head;
   while(ptr != NULL) {        
      printf(" %d\n",ptr->data);
      ptr = ptr->next;
   }

   
}


void insert(int data) {

   struct node *link = (struct node*) malloc(sizeof(struct node));

   
   link->data = data;
   link->next = head;
   head = link;
}
void delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("No elements in the list\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("Node deleted from linked list\n");  
    }  
}  

void main() {
    int r = 1;
    int opt,item;
    do
    {
        printf("MENU\n");
        printf("1 for inserting data into linked list\n");
        printf("2 for displaying linked list\n");
        printf("3 for deleting node in linked list\n");
        printf("4 for exiting this menu\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            printf("Enter your element\n");
            scanf("%d",&item);
            insert(item);
            
        }
        
        else if (opt==2)
        {
           printList();
        }
        else if (opt==3)
        {
            delete();
        }
        else if(opt==4)
        {
            r=0;
        }
        
        
        
    } while (r>0);
}