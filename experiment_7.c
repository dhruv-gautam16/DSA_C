#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data; 
    struct node *right_child; 
    struct node *left_child; 
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x)
    {
        return root;
    }
    else if(x>root->data)
    {

        return search(root->right_child, x);
    }
    else
    {
        return search(root->left_child,x);
    }
}

struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}
struct node* delete(struct node *root, int x)
{
    
    if(root==NULL)
    {

        return NULL;
    }
    if (x>root->data)
    {
        root->right_child = delete(root->right_child, x);
    }
    else if(x<root->data){
        root->left_child = delete(root->left_child, x);
    }
    else
    {
       
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

       
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL){
                temp = root->right_child;
            }
            else{
                temp = root->left_child;
            }
            free(root);
            return temp;
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->left_child); 
        printf("%d\n", root->data); 
        inorder(root->right_child);
    }
}
struct node* insert(struct node *root, int x)
{
    
    if(root==NULL){
        return new_node(x);
    }
    else if(x>root->data){ 
        root->right_child = insert(root->right_child, x);
    }
    else{
        root->left_child = insert(root->left_child,x);
    }
    return root;
}

void main(){
    int r = 1;
    int opt;
    int a,f,n,i,del,sea;
    printf("ENTER YOUR ROOT NODE\n");
    scanf("%d",&a);
    struct node *root;
    root = new_node(a);
    do
    {

        printf("MENU\n");
        
        printf("1. FOR INSERTING NODE\n");
        printf("2. FOR DELETING A NODE\n");
        printf("3. FOR INORDER TRAVERSAL\n");
        printf("4. FOR SEARCHING AN ELEMENT\n");
        printf("5. FOR EXITING THIS MENU\n");
        scanf("%d",&opt);
    
        if (opt==1)
        {
            printf("ENTER HOW MANY ELEMENTS YOU WANT TO ENTER\n");
            scanf("%d",&n);
            for ( i = 0; i < n; i++)
            {
                printf("ENTER YOUR ELEMENT\n");
                scanf("%d",&f);
                insert(root,f);
            }
            
        }
        else if (opt==2)
        {
            printf("ENTER THE ELEMENT YOU WANT TO DELETE\n");
            scanf("%d",&del);
            root=delete(root,del);

        }
        else if (opt==3)
        {
            inorder(root);
        }
        else if (opt==4)
        {
            printf("ENTER THE ELEMENT YOU WANT TO SEARCH FOR\n");
            scanf("%d",&sea);
            search(root,sea);
        }
        else if (opt==5)
        {
            r=0;
        }
        
        
        
        
        

    } while (r>0);
    
}