/*
			3. Prime Factorization using Sieve

This algorithm is used to find the prime factors of a given number. It can be seen as an application of Sieve.

Time Complexity : O(logn)


https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/


*/
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define MAXN 100000000 


class Node 
{
public:
	int data;
	Node* next;
};


void reverseLL(Node** head)
{ 
	
	stack<Node*> s; 
	Node* temp = *head;
	while (temp->next != NULL) 
	{
	
		s.push(temp); 
		temp = temp->next;
	}
	*head = temp;

	while (!s.empty()) 
	{
		t
		temp->next = s.top(); 
	

		s.pop(); 
	
	
		temp = temp->next; 
	}
	temp->next = NULL;
}


void printlist(Node* temp) 
{
	while (temp != NULL) 
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

// linked list
void insert_back(Node** head, int value)
{ 

	Node* temp = new Node();
	temp->data = value;
	temp->next = NULL;
	
	// If *head equals to NULL
	if (*head == NULL) 
	{
	*head = temp;
	return;
	}
	else
	{
	Node* last_node = *head;
	while (last_node->next != NULL) 
	{
		last_node = last_node->next;
	}
	last_node->next = temp;
	return;
	}
}

// Driver Code
int main()
{
	Node* head = NULL;

	insert_back(&head, 10);
	insert_back(&head, 20);
	insert_back(&head, 30);
	insert_back(&head, 40);
	insert_back(&head, 50);
	insert_back(&head, 60);
	printlist(head);
	reverseLL(&head);
	printlist(head);
	return 0;
}



/*

int primeFactors(int n)  
{      
    long long int  cnt=0;
    while (n % 2 == 0)  
    {     
        cout<<" a 2  ";   
        cnt++;  
        n = n/2;  
    }  
    cout<<n<<" ";
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {          
        while (n % i == 0)  
        {         
            cnt++;
            cout<<" b "<<i<<" ";
            n = n/i;  
        }  
    }   
    
    if (n > 2) 
    { 
        cnt++;
        cout<<n<<endl;
    }
    return cnt;
}  */
