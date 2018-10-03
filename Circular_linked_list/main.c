/*
    Circular linked list in C
    By Tarun Goyal (2016)
    find me on github: https://github.com/tarungoyal1


In circular linked list, there is a pointer (last) which is acutally the last node of the list and
instead of pointing to NULL (as in linked list) it points to first node.

Example:
                                (Last)
                                  |
-> 56 -> 34 -> 90 -> 32 -> 76 -> 65 ->
^                                    |
|                                    |
---<------<------<----<-------<-------

Using this approach, we don't have traverse entire list just for adding or deleting elements in last.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
}*last=NULL;

struct node * getnode(){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    printf("Enter info for new node:");
    scanf("%d",&t->info);
    return t;

}

void create(){
    struct node *newnode = getnode();
    if(last==NULL){
        last=newnode;
        last->link=newnode;
        return;
    }
    newnode->link=last->link;
    last->link=newnode;
    last=newnode;
}

void printlist(){
    if(last==NULL){
        printf("EMPTY LIST");
        return;
    }
    struct node *ptr=last->link;
    printf("\nFinal circular linked list:\n");
    do{
        printf("%d -> ",ptr->info);
        ptr=ptr->link;
    }while(ptr!=last->link);
    printf("LAST <-|");
}

void addatbeg(){
 struct node *newnode = getnode();
 //if list is empty
 if(last==NULL){
        last=newnode;
        last->link=newnode;
        return;
    }
 newnode->link=last->link;
 last->link=newnode;
}

void addatend(){
    struct node *newnode = getnode();
    //if list is empty
    if(last==NULL){
        last=newnode;
        last->link=newnode;
        return;
    }
    newnode->link=last->link;
    last->link=newnode;
    last=newnode;
}

void addbetween(){
    //add after a certain node
    if(last==NULL)return;
    int val;
    printf("Enter node in the list after which u gotta insert:");
    scanf("%d",&val);
    //val arg is info at a node already present in the list
   //check if val entered is of last node

   if(last->info==val){
    addatend();
    return;
   }

   struct node *newnode, *ptr=last->link;

    while(ptr->link!=last->link){
      if(ptr->info==val){
            newnode=getnode();
            newnode->link=ptr->link;
            ptr->link=newnode;
      }
      ptr=ptr->link;
    }
    printf("Node not found in the list\n");

}

void deletebegin(){
    //attempting to delete empty list
    if(last==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    //if list has only one node
    if(last->link==last){
        last=NULL;
        return;
    }
    last->link=last->link->link;
}

void deletelast(){
    //attempting to delete empty list
    if(last==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    //if list has only one node
    if(last->link==last){
        last=NULL;
        return;
    }
    struct node *ptr=last->link;
    while(ptr->link->link!=last->link) ptr=ptr->link;
    ptr->link=last->link;
    last=ptr;
}

void deletebetween(){
    //attempting to delete in empty list
    if(last==NULL){
        printf("UNDERFLOW\n");
        return;
    }

    int val;
    printf("Enter value of node you wish to delete:");
    scanf("%d",&val);

   //check if val entered is of last node
   if(last->info==val){
    deletelast();
    return;
   }

    struct node *ptr=last->link;
    while(ptr->link!=last->link){
        if(ptr->link->info==val) {
            ptr->link=ptr->link->link;
            return;
        }
        ptr=ptr->link;
    }
    printf("Node not found in the list\n");

}


void deleteposition(){
        //attempting to delete in empty list
    if(last==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    int pos;
    printf("Enter position at which u gotta delete:");
    scanf("%d",&pos);
    int c=1;
    struct node *ptr=last;
    while(ptr->link!=last){
        if(pos==c){
            printf("Node found at position %d is %d, so deleting %d\n", pos, ptr->link->info, ptr->link->info);
            ptr->link=ptr->link->link;
            return;
        }
        ++c;
        ptr=ptr->link;
    }
    //to handle deleting the node at last
    if(c==pos){
        deletelast();
        return;
    }
    printf("Invalid position!");

}

int main()
{
    char o;
    int opt, optc=0;
    printf("Create circular linked list using last pointer:\n");
    do{
        create();
        printf("Press y to create another:");
        getchar();
        scanf("%c",&o);
    }while(o=='y');
    printlist();

    while(1){
        printf("\n------------------\nOperation ID: %d\n-------------------",optc++);
        printf("\nPress 1 to add at begin\n");
        printf("Press 2 to add at end\n");
        printf("Press 3 to add in between\n");
        printf("Press 4 to delete begin\n");
        printf("Press 5 to delete last\n");
        printf("Press 6 to delete a node by value\n");
        printf("Press 7 to delete at position\n");
        printf("Press -1 to exit the loop \n");

        scanf("%d", &opt);
        if(opt<=0)break;

        switch(opt){
            case 1:
                addatbeg();
                printlist();
            break;
            case 2:
                addatend();
                printlist();
            break;
            case 3:
                addbetween();
                printlist();
            break;
            case 4:
                deletebegin();
                printlist();
            break;
            case 5:
                deletelast();
                printlist();
            break;
            case 6:
                deletebetween();
                printlist();
            break;
            case 7:
                deleteposition();
                printlist();
            break;
        }
    }

    return 0;
}
