// Check if LL is palindrome or not
// LL + Stack
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL;
typedef struct node node;

int stack[10],top=-1,arr[10],arr_len=0;

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
    
    i=0;
    p=head;
    while(p!=NULL)
    {
        push(p->data);
        p=p->next;
    }
printf("\narr print:");
    for(k=0; k<arr_len; k++)
    {
        printf("%d ",arr[k]);    
    }
    
    j=0;
    while(top!=-1)
    {
        ans=pop();
    //   printf("%d ",ans);
        item[j]=ans;
        j++;
    }
    printf("\nitem print:");
    for(k=0; k<j; k++)
    {
        printf("%d ",item[k]);    
    }
    
    printf("\nj=%d arr_len=%d:",j,arr_len);
    if(arr_len==j)
    {
        for(k=0; k<arr_len; k++)
        {
            if(arr[k]==item[k])
            {
                cnt++;
            }
        }
    }
    else
        printf("\nNot palindrome");
    
    if(cnt==arr_len)
        printf("\npalindrome");
    else
        printf("\nnot palindrome");
    
    
    return 0;
}

/*Output
Enter Total nodes : 5                                                                           
Enter 1 node data : 1                                                                           
Enter 2 node data : 2                                                                           
Enter 3 node data : 2                                                                           
Enter 4 node data : 2                                                                           
Enter 5 node data : 1                                                                           
                                                                                                
Linked List...                                                                                  
<-1-><-2-><-2-><-2-><-1->                                                                       
arr print:1 2 2 2 1                                                                             
item print:1 2 2 2 1                                                                            
j=5 arr_len=5:                                                                                  
palindrome    
*/
