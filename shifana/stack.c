#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node*next;
};
struct node*top=NULL;
int isEmpty()
{
        if (top==NULL)
                return 1;
        else
                return 0;
}
void push(int value)
{
        struct node*newnode=(struct node*) malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=top;
        top=newnode;
        printf("Element Inserted Successfull\n");
}
void pop()
{
        struct node*temp;
        if (isEmpty())
        {
                printf("Stack Underflow!!\n");
        }
        else
        {
                temp=top;
                top=temp->next;
                free(temp);
        }
        printf("Element deleted successfully\n");
}
int peek()
{
        if (isEmpty())
        {
                printf("Stack Underflow\n");
        }
        else
        {
                printf("The topmost element is %d\n",top->data);
        }
}
void display()
{
        struct node*temp=top;
        if(isEmpty())
        {
                printf("Stack Underflow\n");
        }
        else
        {
                printf("The stack elements are:\n");
                while(temp)
                {
                        printf("%d\n",temp->data);
                        temp=temp->next;
                }
        }
}
void search()
{
        struct node*temp=top;
        int found=0;
        int value;
        if (isEmpty())
        {
                printf("Stack Underflow\n");
        }
        else
        {
                printf("Enter the value to be searched: ");
                scanf("%d",&value);
                while(temp)
                {
                        if (temp->data==value)
                        {
                                found=1;
                                break;
                        }
                        temp=temp->next;
                }
                if (found==1)
                        printf("Element Found\n");
                else
                        printf("Element not found\n");
        }
}
int main()
{
        int value,choice;
        while(1)
        {
                printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.SEARCH\n6.EXIT\nEnter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Enter the value to be inserted: ");
                                scanf("%d",&value);
                                push(value);
                                break;
                        case 2:
                                pop();
                                break;
                        case 3:
                                peek();
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                search();
                                break;
                        case 6:
                                exit(1);
                                break;
                        default:
                                printf("Invalid Choice\n");
                                break;
                }
        }
}
