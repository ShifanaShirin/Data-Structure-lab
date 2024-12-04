#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
        struct node *prev;
        struct node *lock;
};
struct node *head=NULL;
void display(){
        struct node *temp=head;
        if(temp==NULL){
                printf("\n Linked list is empty");
        }
        else{
                printf("\n Elements are:");
                while(temp!=NULL)
                {
                        printf("%d \t",temp->data);
                        temp=temp->next;
                }
        }
}
void search(){
        int s,f=0;
        printf("\n Enter value to be search:");
        scanf("%d",&s);
        struct node *temp=head;
        if(head==NULL)
                printf("\n List is empty");
        else{
                while(temp!=NULL){
                        if(temp->data==s){
                                f=1;
                                printf("\n Element found");
                        }
                        temp=temp->next;
                }
                if(f!=1)
                        printf("\n Element not found");
}
}

void insert_begin() {
        int data;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("\n Enter the value to be inserted:");
        scanf("%d",&data);
        newnode->data = data;

        newnode->next = head;

        newnode->prev = NULL;
        if (head!= NULL)
                head->prev = newnode;
        head = newnode;

        display();
}

void insert_anywhere() {
        struct node *prev=head;
        int data,p,count=2;
        struct node *temp;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));


        printf("\n Enter the position to be inserted:");
        scanf("%d",&p);
        if(head==NULL)
                printf("List is empty");
        else if(p==1)
                insert_begin();

        else{
                printf("\n Enter the data to be inserted:");
                scanf("%d",&data);


                temp=head;
                while(temp!=NULL){
                    if(p==count){
                        newnode->data=data;
                        newnode->next=temp->next;
                        temp->next=newnode;
                        break;
                    }
                    else{
                        temp=temp->next;
                        count++;
                    }
                }
                display();
        }
}

void insert_end() {
        int data;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("\n Enter the value to be inserted:");
        scanf("%d",&data);

        newnode->data = data;

        newnode->next = NULL;


        struct node* temp = head;

        if (head == NULL) {
                newnode->prev = NULL;
                head = newnode;
                return;
        }

        while (temp->next != NULL)
                temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        display();
}

void delete_begin(){
        struct node *temp=head;
        if (head == NULL)
                printf("\n list is empty");

        else{
                head=temp->next;
                free(temp);
                display();
        }
}
void delete_anywhere(){
        int p;
        if(head==NULL)
                printf("\n List is empty");
        else{
                printf("\n Enter the position to be deleted:");
                scanf("%d",&p);
                struct node *temp=head;
                struct node *lock=NULL;
                if(p<1)
                        printf("\n Invalid");
                else if(p==1)
                        delete_begin();
                else{
                        for(int i=1;i<p&&temp!=NULL;i++){
                                lock=temp;
                                temp=temp->next;
                                if(temp==NULL)
                                        printf("\n Position not found");
                                lock->next=temp->next;
                                temp->lock=lock->next;
                                free(temp);
                        }
                        display();
                }
        }
}
void delete_end(){
struct node *ptr=head;
        struct node *temp=ptr;
        if(ptr==NULL)
                printf("\n List is empty");
        else if(ptr->next==NULL){
                head=NULL;
                free(ptr);
                printf("\n List is empty");
        }
        else{
                ptr=head;
                while(ptr->next!=NULL){
                        temp=ptr;
                        ptr=ptr->next;

                }
                temp->next=NULL;
                free(ptr);
                display();
        }
}
void main()
{
        int ch;
        do{
                printf("\n Menu \n 1.Insert at beginning \n 2.Insert at any position \n 3.Insert at end \n 4.Search \n 5.Delete from beginnin>
                printf("\n Enter your choice:");
                scanf("%d",&ch);
                switch(ch){
                        case 1: insert_begin();
                                break;
                        case 2: insert_anywhere();
                                break;
                        case 3: insert_end();
                                break;
                        case 4: search();
                                break;
                        case 5: delete_begin();
                                break;
                        case 6: delete_end();
                                break;
                        case 7: delete_anywhere();
                                break;
                        case 8: display();
                                break;
                        case 9: printf("\n Exit...");
                                exit(0);
                        default: printf("\n Invalid Entry..");

                }
        }while(ch!=9);
}
