#include <stdio.h>
#include <stdlib.h>

struct node
{  int data;
   struct node *next;
};

typedef struct node node;
node *head=NULL;
int n;

void createNode()
{
    node *nn,*p;
    
    nn=(node *)malloc(sizeof(node *));
    printf("Enter value : ");
    scanf("%d", &nn->data);
    nn->next=NULL;
    
    if(head==NULL)
    {
        p=head=nn;
    }
    else
    {
        p->next=nn;
        p=nn;
    }
}

void traverse()
{
    node *p;
    p=head;
    
    while(p!=NULL)
    {
        printf("<-%d->",p->data);
        p=p->next;
    }
}

void find_location(node *p, int loc)
{
    node *front, *back;
    int i;
    front = back = head;
    if(loc > n)
    {
        printf("Error : n is greater than length of Linked List\n");
    }
    for(i = 0; i < loc-1; i++){
        front = front->next;
    }
    /* Now, move both pointers together till front reaches
last node of linked list */
    while(front->next != NULL){
        front = front->next;
        back = back->next;
    }
    printf("%d", back->data);
}

int main()
{
    int i, item, loc;
    
    printf("Enter Total nodes : ");
    scanf("%d", &n);
    
    printf("\nEnter %d nodes data...\n",n);
    for(i=0; i<n; i++)
    {
        createNode();
    }
    
    printf("\nLinked List(Traverse)...\n");
    traverse();

    printf("\nDisplay Location of element from last...\n");
    printf("\nEnter location : ");
    scanf("%d", &loc);
    find_location(head,loc);
    return 0;
}
