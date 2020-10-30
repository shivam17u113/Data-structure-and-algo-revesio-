/*
					SIDDESH SUNIL VYAVAHARE 
						  A3 17U373
						   331067
						   TY IT
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>
using namespace std;
#define br  cout<<"========================================\n";
#define fbr cout<<"\n========================================\n";

class warshall
{
	private:
		int v,e;		//no of vertices and edges 
		int **a;		// pointer approach for storing and accessing 2d matrix for graph
	public:
		void accept();
		void display();
		void war();
		warshall()
		{
			cout<<"Enter vertices \n";
			cin>>v;
			a=new int*[v];
			for(int i=0;i<v;i++) 	//allocate memory			
				a[i]=new int[v];
			
			for(int i=0;i<v;i++)			//assign weight of graph to infinite if i!=j
			{
				for(int j=0;j<v;j++)
				{
					if(i==j)
						*(*(a+i)+j)=0;
					else
						*(*(a+i)+j)=999;
				}
			}
		}
};



void warshall::accept()						//accept the edges
{
	cout<<"Enter no of Edges: ";
	cin>>e;
	int r,c,w;
	cout<<"Enter Source Destinaion and Weight\n";
	for(int i=1;i<=e;i++)
	{
		cin>>r>>c>>w;
		*(*(a+r)+c)=w;
	}
}

void warshall::display()			//display graph
{
	cout<<"The Matrix is  \n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			cout<<*(*(a+i)+j)<<"\t";		
		cout<<endl;
	}
	
}

void warshall::war()		//shortest path updated in same matrix
{	
	for(int k=0;k<v;k++)	
		for(int i=0;i<v;i++)		
			for(int j=0;j<v;j++)			
				a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
			
	display();						//display the result
}

int main()
{	
	warshall W;
	int ch;
	do
	{
		cout<<"Enter choice \n1.Accept \n2.Display \n3.Warshals \n4.Exit\n";		// do while for choices
		cin>>ch;		
		br;					//break line defined in #define
		switch(ch)
		{
			case 1:	
				W.accept();				
				br;				//break line defined in #define
			break;

			case 2:
				W.display();
				fbr;				//break line defined in #define
			break;

			case 3:
				W.war();
				br;					//break line defined in #define
			break;
		}

	} while(ch!=4);

	return 0;
}



/*     			OUTPUT


Enter vertices
5
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
1
========================================
Enter no of Edges: 5
Enter Source Destinaion and Weight
0 1 66
2 4 4
3 1 55
1 0 22
2 3 12
========================================
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
2
========================================
The Matrix is
0       66      999     999     999
22      0       999     999     999
999     999     0       12      4
999     55      999     0       999
999     999     999     999     0

========================================
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
3
========================================
The Matrix is
0       66      999     999     999
22      0       999     999     999
89      67      0       12      4
77      55      999     0       999
999     999     999     999     0
========================================
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
4
========================================
Enter vertices
6
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
1
========================================
Enter no of Edges: 8
Enter Source Destinaion and Weight
1 0 55
2 3 10
4 1 33
3 1 0
2 0 11
2 1 87
0 3 22
3 0 2
========================================
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
2
========================================
The Matrix is
0       999     999     22      999     999
55      0       999     999     999     999
11      87      0       10      999     999
2       0       999     0       999     999
999     33      999     999     0       999
999     999     999     999     999     0

========================================
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
3
========================================
The Matrix is
0       22      999     22      999     999
55      0       999     999     999     999
11      10      0       10      999     999
2       0       999     0       999     999
88      33      999     999     0       999
999     999     999     999     999     0
========================================
Enter choice
1.Accept
2.Display
3.Warshals
4.Exit
4
========================================

*/
