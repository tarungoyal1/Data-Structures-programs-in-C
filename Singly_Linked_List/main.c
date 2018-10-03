/*
	Singly Linked list implementation in C
	Demonstrating operations such as insertion, deletion, sorting, reversing, etc.

	Made by Tarun Goyal (8 Feb, 2016)
	find me at github -> https://github.com/tarungoyal1c

*/

#include<stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *getnewnode(){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    printf("Enter info for new node:");
    scanf("%d",&t->info);
    return t;
}

void create(struct node * head){

    struct node *newnode=getnewnode(), *ptr=head;

    //on first insertion we are working on head (as ptr points to address of head)
    while(ptr->link!=NULL)
        ptr=ptr->link;

    //ptr reached to last node which has no address to any further node

    ptr->link=newnode;
    newnode->link=NULL;
}

void printlist(struct node * head){
    struct node *ptr=head->link;
    if(ptr==NULL){
        printf("EMPTY LIST");
        return;
    }

    //You can simply print the list from while loop below omitting next 2 lines
    printf("\nFinal linked list:\n%d", ptr->info);
    ptr=ptr->link;

    while(ptr!=NULL){
        printf(" -> %d",ptr->info);
        ptr=ptr->link;
    }
    printf("\n");
}

void addatbeg(struct node *head){
    struct node *newnode=getnewnode();

    newnode->link=head->link;
    head->link=newnode;
}

void addatend(struct node *head){
 struct node *newnode=getnewnode(), *ptr=head;

 while(ptr->link!=NULL) ptr=ptr->link;
 ptr->link=newnode;
 newnode->link=NULL;
}

void addafternode(struct node *head){
    if(head->link==NULL)return;
    int val;
    printf("Enter node in the list after which u gotta insert:");
    scanf("%d",&val);

    //val arg is info at a node already present in the list
   struct node *newnode=getnewnode(), *ptr=head;

   while(ptr->link!=NULL){
    if(ptr->info==val){
        newnode->link=ptr->link;
        ptr->link=newnode;
        return;
    }
    ptr=ptr->link;
   }
}

void deleteatbeg(struct node *head){
    //attempting to delete in empty list
    if(head->link==NULL){
        printf("UNDERFLOW\n");
        return;
  }

  head->link=head->link->link;
}

void deleteafternode(struct node *head){
    //attempting to delete in empty list
    if(head->link==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    int val;
    printf("Enter value of node you wish to delete:");
    scanf("%d",&val);
    struct node *ptr=head;
    while(ptr->link!=NULL){
        if(ptr->link->info==val){
            printf("Node found, so deleting %d\n", val);
            ptr->link=ptr->link->link;
            return;
        }
        ptr=ptr->link;
    }
    printf("Node not found in the list\n");

}

void deleteatpos(struct node *head){
    //attempting to delete in empty list
    if(head->link==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    int pos;
    printf("Enter position at which u gotta delete:");
    scanf("%d",&pos);
    int c=1;
    struct node *ptr=head;
    while(ptr->link!=NULL){
        if(pos==c){
            printf("Node found at position %d is %d, so deleting %d\n", pos, ptr->link->info, ptr->link->info);
            ptr->link=ptr->link->link;
            return;
        }
        ++c;
        ptr=ptr->link;
    }
    printf("Invalid position!");
}

void deleteatlast(struct node *head){
    //attempting to delete in empty list
    if(head->link==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    struct node *ptr=head;
    while(ptr->link->link!=NULL)
        ptr=ptr->link;
    ptr->link=NULL;
}

void reverse(struct node *head){
    struct node *next,*ptr=head->link,*prev=NULL;
    while(ptr!=NULL){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    head->link=prev;
}

void sort(struct node *head){

    struct node *ptr=head, *q;
    int tmp;

    for(;ptr->link!=NULL;ptr=ptr->link){
        for(q=ptr->link;q!=NULL;q=q->link){
            if(ptr->info > q->info){
                tmp = ptr->info;
                ptr->info = q->info;
                q->info = tmp;

            }
        }
    }

}

int main(){
    int opt,val, optc=0;
    char o;

    //head is tracking pointer, it holds only the address of first node in linked list
    //head itself is not considered as a node in linked list and contains no actual data
    struct node *head;
    head->link = NULL;
    head->info = NULL;

    printf("Create singly linked list:\n");
    
    do{
        create(head);
        printf("Press y to repeat again:");
        getchar();
        scanf("%c",&o);
    }while(o=='y');

    printlist(head);

    printf("\n---Press appropriate key, enter -1 to exit loop---\n");

    while(1){
        printf("------------------\nOperation ID: %d\n-------------------",optc++);
        printf("\nPress 1 to add at begining\nPress 2 to add at end\nPress 3 to add after a certain node\nPress 4 to delete at begin\nPress 5 to delete a node by value\nPress 6 to delete at certain position\nPress 7 to delete at last\nPress 8 to reverse the list\nPress 9 to sort the list\n");
        scanf("%d",&opt);

        if(opt<0)break;

        switch(opt){
            case 1:
                addatbeg(head);
                printlist(head);
            break;
            case 2:
                addatend(head);
                printlist(head);
            break;
            case 3:
                addafternode(head);
                printlist(head);
            break;
            case 4:
                deleteatbeg(head);
                printlist(head);
            break;
            case 5:

                deleteafternode(head);
                printlist(head);
            break;
            case 6:
                deleteatpos(head);
                printlist(head);
            break;
            case 7:
                deleteatlast(head);
                printlist(head);
            break;
            case 8:
                reverse(head);
                printlist(head);
            break;
            case 9:
                sort(head);
                printlist(head);
            break;
        }
    }
    return 0;
}
