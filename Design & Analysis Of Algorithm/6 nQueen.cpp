/*
					SIDDESH SUNIL VYAVAHARE 
						A3 17U373
						 331067
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<set>
using namespace std;
int cnt=0;
void display(vector<int> a,int n)  //display array 
{
	for(int k=1;k<=n;k++)	
		cout<<a[k]<<" ";
	
	cout<<endl;

	for(int i=1;i<=n;i++)
	{		
		for(int j=1;j<=n;j++)
		{
			if(j==a[i])			
				cout<<"Q";
			else
				cout<<"-";
		}
		cout<<endl;
	}
	cout<<"========================================\n";
}

int place(vector<int> a,int k,int pos)  // store queen at col value   kth queen 
{
	for(int i=1;i<k;i++)
	{
		if(a[i]==pos)
			return 0;
		
		if( abs(k-i) == abs(a[i]-pos))
			return 0;		
	}
	return 1;		
}


void queen(vector<int> a,int k,int n)			// k is queen no
{
	
	for(int i=1;i<=n;i++)
	{
		if(place(a,k,i))	//check if we can place queen
		{
			a[k]=i;
			if(k==n)		
				display(a,n);			//display when found 
			
			queen(a,k+1,n);			
		}
	}
}

int main()
{
	int ch,n;
	do
	{
		cout<<"Enter choice \n1.Accept \n2.Display \n3.Exit\n";		// do while for choices
		cin>>ch;
		cout<<"========================================\n";
		switch(ch)
		{
			case 1:
				cin>>n;
				n++;
				cout<<"========================================\n";
			break;

			case 2:
				vector<int> a(n);	
				for(int i=0;i<a.size()+1;i++)
					a[i]=0;
				a[1]=1;
				queen(a,1,n-1);
			break;
		}

	} while(ch!=3);

	return 0;
}


/*     			OUTPUT


Enter choice
1.Accept
2.Display
3.Exit
1
========================================
4
========================================
Enter choice
1.Accept
2.Display
3.Exit
2
========================================
2 4 1 3
-Q--
---Q
Q---
--Q-
========================================
3 1 4 2
--Q-
Q---
---Q
-Q--
========================================
Enter choice
1.Accept
2.Display
3.Exit
1
========================================
5
========================================
Enter choice
1.Accept
2.Display
3.Exit
2
========================================
1 3 5 2 4
Q----
--Q--
----Q
-Q---
---Q-
========================================
1 4 2 5 3
Q----
---Q-
-Q---
----Q
--Q--
========================================
2 4 1 3 5
-Q---
---Q-
Q----
--Q--
----Q
========================================
2 5 3 1 4
-Q---
----Q
--Q--
Q----
---Q-
========================================
3 1 4 2 5
--Q--
Q----
---Q-
-Q---
----Q
========================================
3 5 2 4 1
--Q--
----Q
-Q---
---Q-
Q----
========================================
4 1 3 5 2
---Q-
Q----
--Q--
----Q
-Q---
========================================
4 2 5 3 1
---Q-
-Q---
----Q
--Q--
Q----
========================================
5 2 4 1 3
----Q
-Q---
---Q-
Q----
--Q--
========================================
5 3 1 4 2
----Q
--Q--
Q----
---Q-
-Q---
========================================
Enter choice
1.Accept
2.Display
3.Exit
3
========================================
*/
