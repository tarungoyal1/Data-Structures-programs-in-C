/*
    Doubly linked list in C
    Implemented by Tarun Goyal (11 March, 2016)
    find me on github-> https://github.com/tarungoyal1

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *plink;
    int info;
    struct node *nlink;
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
    while(ptr->nlink!=NULL)
        ptr=ptr->nlink;

    //ptr reached to last node which has no address to any further node

    ptr->nlink=newnode;
    newnode->plink=ptr;
    newnode->nlink=NULL;
}

void printlist(struct node * head){
    //this way of printing the doubly linked list handles all cases of deletion
    //you can print simply as you like
    struct node *ptr=head;
    if(ptr==NULL||ptr->nlink==NULL){
        printf("EMPTY LIST\n");
        return;
    }


    //You can simply print the list as you do singly linked list but i had to embellish the printing
    if(ptr->nlink!=NULL){
        printf("\nFinal linked list:\nNULL <- %d ->", ptr->nlink->info);
        if(ptr->nlink->nlink==NULL){
            printf(" NULL\n");
            return;
        }
        ptr=ptr->nlink->nlink;
    }

    while(ptr->nlink!=NULL){
        printf(" <- %d -> ",ptr->info);
        ptr=ptr->nlink;
    }
    printf(" <- %d -> NULL\n", ptr->info);
}

void addatbeg(struct node *head){
    struct node *newnode=getnewnode();

    newnode->plink=NULL;
    newnode->nlink=head->nlink;
    head->nlink=newnode;
}

void addatend(struct node *head){
 struct node *newnode=getnewnode(), *ptr=head;

 while(ptr->nlink!=NULL) ptr=ptr->nlink;

 ptr->nlink=newnode;
 newnode->plink=ptr;
 newnode->nlink=NULL;
}

void addafternode(struct node *head){
    if(head->nlink==NULL)return;
    int val;
    printf("Enter node in the list after which u gotta insert:");
    scanf("%d",&val);

    //val arg is info at a node already present in the list
   struct node *newnode=getnewnode(), *ptr=head;

   while(ptr->nlink!=NULL){
    if(ptr->info==val){
         newnode->plink=ptr;
         newnode->nlink=ptr->nlink;
         ptr->nlink=newnode;
        return;
    }
    ptr=ptr->nlink;
   }
}

void deleteatbeg(struct node *head){
    //attempting to delete in empty list
    if(head->nlink==NULL){
        printf("UNDERFLOW\n");
        return;
    }

  head->nlink=head->nlink->nlink;
  head->plink = NULL;

}

void deleteafternode(struct node *head){
    //attempting to delete in empty list
    if(head->nlink==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    int val;
    printf("Enter value of node you wish to delete:");
    scanf("%d",&val);
    struct node *ptr=head;
    while(ptr->nlink!=NULL){
        if(ptr->nlink->info==val){
            printf("Node found, so deleting %d\n", val);
            //if clause handles if node to be deleted is at last
            if(ptr->nlink->nlink==NULL){
                ptr->nlink = NULL;
                return;
            }
            ptr->nlink->nlink->plink=ptr;
            ptr->nlink=ptr->nlink->nlink;
            return;
        }
        ptr=ptr->nlink;
    }
    printf("Node not found in the list\n");

}

void deleteatlast(struct node *head){
    //attempting to delete in empty list
    if(head->nlink==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    struct node *ptr=head;
    while(ptr->nlink->nlink!=NULL)
        ptr=ptr->nlink;
    ptr->nlink=NULL;
}

void deleteatpos(struct node *head){
    //attempting to delete in empty list
    if(head->nlink==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    int pos;
    printf("Enter position at which u gotta delete:");
    scanf("%d",&pos);
    int c=1;
    struct node *ptr=head;
    while(ptr->nlink!=NULL){
        if(pos==c){
            printf("Node found at position %d is %d, so deleting %d\n", pos, ptr->nlink->info, ptr->nlink->info);

            if(ptr->nlink->nlink==NULL){
                ptr->nlink = NULL;
                return;
            }
            ptr->nlink->nlink->plink=ptr;
            ptr->nlink=ptr->nlink->nlink;
            return;
        }
        ++c;
        ptr=ptr->nlink;
    }
    printf("Invalid position!");
}


int main()
{
    int opt,val, optc=0;
    char o;

    //head is tracking pointer, it holds only the address of first node in linked list
    //head itself is not considered as a node in linked list and contains no actual data
    struct node *head;
    head->plink = NULL;
    head->nlink = NULL;
    head->info = NULL;

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

        printf("\nPress 1 to add at begin\n");
        printf("Press 2 to add at end\n");
        printf("Press 3 to add after a node\n");
        printf("Press 4 to delete at begin\n");
        printf("Press 5 to delete at last\n");
        printf("Press 6 to delete a node by value\n");
        printf("Press 7 to delete at position\n");

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
                 deleteatlast(head);
                printlist(head);
            break;
            case 6:
                deleteafternode(head);
                printlist(head);
            break;
            case 7:
                deleteatpos(head);
                printlist(head);
            break;
//            case 8:
//                reverse(head);
//                printlist(head);
//            break;
//            case 9:
//                sort(head);
//                printlist(head);
//            break;
        }
    }

    return 0;
}
