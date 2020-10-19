//Program
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL;
typedef struct node node;

int stack[10],top=-1,arr[10],arr_len=0;

node* reverse(node* head, int k){
	if(head==NULL){
		return NULL;
	}
	struct node* next=NULL;
	struct node* prev=NULL;
	struct node* curr=head;
	int count=0;
	while(curr && count<k){
		//we store the next pointer into next
		//and connect the  current pointer to the head of the prev
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	//in the reverse list head node of the linkedlist will come to the tail
	//for this we connect the next node to it's next pointer 
	head->next=reverse(curr,k);
	return prev;
}

void push(int item)
{
    if(top<10)
    {
        top++;
        stack[top]=item;
        arr[arr_len]=item;
        arr_len++;
    }
    else
    {
        printf("\nStack Overflow...\n");
    }
}

int pop()
{   int item;

    if(top==-1)
    {
        printf("\nStack Underflow...\n");
        return -1;
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

int main()
{
    int i,n,j,k,ans,item[10],cnt=0,ans2;
    node *p,*nn;
    
    printf("Enter Total nodes : ");
    scanf("%d", &n);
    
    head=(node *)malloc(sizeof(node *));
    printf("Enter 1 node data : ");
    scanf("%d", &head->data);
    head->next=NULL;
    nn=p=head;
    
    for(i=1; i<n; i++)
    {   
        nn->next=(node *)malloc(sizeof(node *));
        nn=nn->next;
        printf("Enter %d node data : ",i+1);
        scanf("%d", &nn->data);
        nn->next=NULL;
        p=nn;
    }
    
    printf("\nLinked List...\n");
    p=head;
    while(p!=NULL)
    {
        printf("<-%d->", p->data);
        p=p->next;
    }
    nn=reverse(head,3);
    
    while(nn!=NULL)
    {
        printf("<-%d->", nn->data);
        nn=nn->next;
    }
    return 0;
}

/*Output
Enter Total nodes : 6                                                                           
Enter 1 node data : 1                                                                           
Enter 2 node data : 2                                                                           
Enter 3 node data : 3                                                                           
Enter 4 node data : 4                                                                           
Enter 5 node data : 5                                                                           
Enter 6 node data : 6                                                                           
                                                                                                
Linked List...                                                                                  
<-1-><-2-><-3-><-4-><-5-><-6->
<-3-><-2-><-1-><-6-><-5-><-4->
*/