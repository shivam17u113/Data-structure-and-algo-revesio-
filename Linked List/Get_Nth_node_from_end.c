#include <stdio.h>
#include <stdlib.h>

struct node
{  int data;
   struct node *next;
};

typedef struct node node;
node *head=NULL,*p=NULL;
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

struct node * find_element(node *head, int loc)
{
    int n = 0;
	struct node* curr = head;

	// Count number of nodes in the linked list
	while (curr)
	{
		curr = curr->next;
		n++;
	}

	// if number of nodes is more than or equal to loc
	if (n >= loc)
	{
		curr = head;
		for (int i = 0; i < n - loc; i++)
			curr = curr->next;
	}

	return curr;
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
    p = find_element(head,loc);
    
    if(p)
      printf("Nth node from end is = %d ", p->data);
      
    return 0;
}
