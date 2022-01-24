#include <stdio.h>
#include <stdlib.h>

void main()
{
    int r=1;
    int opt,size,choice;
    do
    {
        printf("MENU\n");
        printf("Please select what you want to do\n");
        printf("1.For Implementing structures\n");
        printf("2.For Implementing Stack\n");
        printf("3.For exiting this menu\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            struct christ_student
        {
            char student_id[100];
            char student_name[100];
            char marks[100];
        };
        struct christ_student arrr[3];
        struct christ_student *ptr = NULL;
        int d;
        ptr =arrr;
        for ( d = 0; d < 3; d++)
        {
            printf("enter the ID of student\n");
            scanf("%s",ptr->student_id);
            printf("please enter the name of student\n");
            scanf("%s",ptr->student_name);
            printf("please enter your marks\n");
            scanf("%s",ptr->marks);
            ptr++;
        }
        printf("now we are displaying the values that are there in our array\n");
        ptr=arrr;
        for ( d = 0; d < 3; d++)
        {
             printf("ID: %s\n", ptr->student_id);
             printf("Name: %s\n", ptr->student_name);
             printf("Marks: %s\n", ptr->marks);
             ptr++;
        }
        }
        else if (opt==2)
        {
            printf("Please enter the size of stack you want\n");
            scanf("%d",&size);
            int stack[size];
            int top=-1;
            int u = 1;
            do
            {
            printf("Please choose what you want to do\n");
            printf("1.For push()\n");
            printf("2.For pop()\n");
            printf("3.For display()\n");
            printf("4.For exiting this menu\n");
            scanf("%d",&choice);
            if (choice==1)
            {
                if (top>=size-1)
                {
                    printf("Stack is overflow\n");
                }
                else
                {
                    printf("Enter the value you want to enter\n");
                    int x;
                    scanf("%d",&x);
                    top++;
                    stack[top]=x;
                }
                
            }
            else if (choice==2)
            {
                if(top<=-1)
                {
                    printf("\n\t Stack is under flow");
                }
                else
                {
                    printf("\n\t The popped elements is %d",stack[top]);
                    top--;
                }
            }
            else if (choice==3)
            {
                int k;
                if(top>=0)
                {
                    printf("The elements in STACK \n");
                    for(k=top; k>=0; k--)
                    {
                        printf("%d\n",stack[k]);
                    }
                }
                else
                {
                    printf("Stack is empty\n");
                }
            }
            else
            {
                u=0;
            }
            } while (u>0);
        }
        else
        {
            r=0;
        }
        
    } while (r>0);
}
