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

class Travel_Salesman
{
	private:
		int n,cost;		//no of city and cost 
		int **a;		// pointer approach for storing and accessing 2d matrix for cost
		int *visited;	//store hamiltonian cycle in x array
	public:
		void accept();			//accept  cost matrix
		void display();			//display cost matrix
		void MinCost(int );			
		int Find_Least(int );
		Travel_Salesman()
		{
			cout<<"Enter no of city \n";
			cin>>n;
			cost=0;				//initialize cost = 0;

			a=new int*[n];		//allocate ROW memory for cost matrix  

			visited=new int[n];		//allocate memory for visited array 

			for(int i=0;i<n;i++)		//init  visited with vertex 0
				visited[i]=0;

			for(int i=0;i<n;i++) 	//allocate memory for columns for graph		
				a[i]=new int[n];
			
			for(int i=0;i<n;i++)		//assign weight of graph to infinite if i!=j
				for(int j=0;j<n;j++)													
					*(*(a+i)+j)=0;				
		}
};

void Travel_Salesman::accept()				//accept the cost martix
{
	int temp;
	cout<<"Enter Cost Matrix Row Wise \n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			*(*(a+i)+j)=temp;
		}
}

void Travel_Salesman::display()			//display cost  matrix
{
	cout<<"The Graph is  \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<*(*(a+i)+j)<<"\t";		//pointer approach		
		cout<<endl;
	}	
}

void Travel_Salesman::MinCost(int city)
{
	int i,ncity;
	visited[city]=1;			//mark visited as 1
	cout<<city+1<<" --> ";		//display city no

	ncity=Find_Least(city);			//get Find_Least cost of city

	if(ncity==999)				//all city are visited so break recursive calls
	{
		ncity=0;
		cout<<ncity+1;				//display last city
		cost+=a[city][ncity];		//add final cost	
		fbr;	
		cout<<"Cost is "<<cost;			//display final cost
		return;
	}
	MinCost(ncity);				//recursive call for nwe city
}

int Travel_Salesman::Find_Least(int c)
{
	int nc=999;
	int min=999,kmin;

	for(int i=0;i<n;i++)		//traverse the array of city c
	{ 	
		if(a[c][i]!=0 && visited[i]==0 )		//search edge which is not visited
		{
			if(a[c][i]+a[i][c]<min)		//check if addition of path is min
			{
				min=a[i][0]+a[c][i];	//update min
				kmin=a[c][i];           //and store weight in kmin
				nc=i;
			}
		}
	}
	if(min!=999)			//if min if 999 all city are visited
		cost+=kmin;
	
	return nc;
}


int main()
{	
	Travel_Salesman H;
	int ch;
	do
	{
		cout<<"Enter choice \n1.Accept Cost Matrix\n2.Display Cost Matrix\n3.Generate Path & Cost \n4.Exit\n";		// do while for choices
		cin>>ch;		
		br;					//break line defined in #define
		switch(ch)
		{
			case 1:	
				H.accept();				
				br;				//break line defined in #define
			break;

			case 2:
				H.display();				
				fbr;				//break line defined in #define
			break;

			case 3:
				cout<<"Path is:\n";
				H.MinCost(0);
				fbr;					//break line defined in #define
			break;
		}

	} while(ch!=4);

	return 0;
}



/*     			OUTPUT

Enter no of city
4
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
1
========================================
Enter Cost Matrix Row Wise
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
========================================
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
2
========================================
The Graph is
0       10      15      20
10      0       35      25
15      35      0       30
20      25      30      0

========================================
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
3
========================================
Path is:
1 --> 2 --> 3 --> 4 --> 1
========================================
Cost is 95
========================================
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
4
========================================
Test Case 2
E:\Study\TY\DAA\Practicals>

Enter no of city
4
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
1
========================================
Enter Cost Matrix Row Wise
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
========================================
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
2
========================================
The Graph is
0       4       1       3
4       0       2       1
1       2       0       5
3       1       5       0

========================================
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
3
========================================
Path is:
1 --> 3 --> 2 --> 4 --> 1
========================================
Cost is 7
========================================
Enter choice
1.Accept Cost Matrix
2.Display Cost Matrix
3.Generate Path & Cost
4.Exit
4
========================================

*/
