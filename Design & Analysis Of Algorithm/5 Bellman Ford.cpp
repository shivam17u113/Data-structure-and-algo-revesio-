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

class Bell_Ford
{
	private:
		int v,e;		//no of vertices and edges 
		int **a;		// pointer approach for storing and accessing 2d matrix for graph
		int *from,*dist;
	public:
		void accept();
		void display();
		int Bellman_Ford();
		Bell_Ford()					//constructor using dynamic memory allocation
		{
			cout<<"Enter vertices \n";
			cin>>v;
			a  = new int*[v];
			dist=new int[v];			//distance array from src
			from=new int[v];			//from array to store path
			for(int i=0;i<v;i++) 	//allocate memory			
				a[i]=new int[v];
			
			for(int i=0;i<v;i++)			
			{
				for(int j=0;j<v;j++)
				{					
						*(*(a+i)+j)=0;						
				}
			}
			dist[0]=0;
		}
};



void Bell_Ford::accept()						//accept the edges
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
	for(int i=0;i<v;i++)		//cost  matrix 
	{
		for(int j=0;j<v;j++)
			if(a[i][j]==0 && i!=j)		//infinite dist for dissconnected vertices
				a[i][j]=999;			// discarding self loop cost 

		dist[i]=999;
	}


	
}

void Bell_Ford::display()			//display graph
{
	cout<<"The Matrix is  \n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			cout<<*(*(a+i)+j)<<"\t";		
		cout<<endl;
	}
}

int Bell_Ford::Bellman_Ford()		//shortest path updated in same matrix
{	
	int src;
	cout<<"Enter source: ";
	cin>>src;
	for(int i=0;i<v;i++)		//init from array to src
		from[i]=src;	
	dist[src]=0;			//dist from src to src is 0

	/*
		relaxation move
		if dist [v] > dist[u] + c[u,v]
			d[v]=dist[u] + c[u,v]
	
	*/
	for(int i=1;i<v;i++)			//do vertices-1 relation iterations 	
		for(int j=0;j<v;j++)	// select edge
			for(int k=0;k<v;k++)
				if(a[j][k]!=999 || j!=k)		//disconnected vertices & self loop cannot be updated 
					if(dist[k]>dist[j]+a[j][k])		 //if prev dist is less than new edge + vertex dist
					{								//update
						dist[k]=dist[j]+a[j][k];
						from[k]=j;
					}


	for(int j=0;j<v;j++)			//select an edge
		for(int k=0;k<v && k!=j;k++)
			if(a[j][k]!=999)
				if(dist[k]>dist[j]+a[j][k])			
					return -1;

	for(int i=0;i<v;i++)		//display the result
	{
		cout<<"\nDistance of "<<i<<" is: "<<dist[i]<<endl;
		cout<<"Path is: ";
		int k=i;
		do
		{
			int j=from[k];
			if(j==0)
				cout<<j<<endl;
			else
				cout<<j<<"<-";
			k=j;
		}while(k!=from[k]);
	}
	return 0;					
}

int main()
{	
	Bell_Ford W;
	int ch;
	do 						// do while for choices
	{
		cout<<"Enter choice \n1.Accept \n2.Display \n3.Shortest Distance Using Bellman Ford \n4.Exit\n";		
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
				W.Bellman_Ford();
				fbr;					//break line defined in #define
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
3.Shortest Distance Using Bellman Ford
4.Exit
1
========================================
Enter no of Edges: 8
Enter Source Destinaion and Weight
0 1 -1
0 2 4
1 2 3
1 3 2
3 1 1
3 2 5
1 4 2
4 3 -3
========================================
Enter choice
1.Accept
2.Display
3.Shortest Distance Using Bellman Ford
4.Exit
3
========================================
Enter source: 0

Distance of 0 is: 0
Path is: 0

Distance of 1 is: -1
Path is: 0

Distance of 2 is: 2
Path is: 1<-0

Distance of 3 is: -2
Path is: 4<-1<-0

Distance of 4 is: 1
Path is: 1<-0

========================================
Enter choice
1.Accept
2.Display
3.Shortest Distance Using Bellman Ford
4.Exit
4
========================================
Enter vertices
5
Enter choice
1.Accept
2.Display
3.Shortest Distance Using Bellman Ford
4.Exit
1
========================================
Enter no of Edges: 8
Enter Source Destinaion and Weight
0 1 -1
0 2 4
1 2 3
1 3 2
3 1 1
3 2 5
1 4 2
4 3 -3
========================================
Enter choice
1.Accept
2.Display
3.Shortest Distance Using Bellman Ford
4.Exit
2
========================================
The Matrix is
0       -1      4       999     999
999     0       3       2       2
999     999     0       999     999
999     1       5       0       999
999     999     999     -3      0

========================================
Enter choice
1.Accept
2.Display
3.Shortest Distance Using Bellman Ford
4.Exit
3
========================================
Enter source: 1

Distance of 0 is: 998
Path is: 3<-4<-1<-
Distance of 1 is: 0
Path is: 1<-
Distance of 2 is: 3
Path is: 1<-
Distance of 3 is: -1
Path is: 4<-1<-
Distance of 4 is: 2
Path is: 1<-
========================================
Enter choice
1.Accept
2.Display
3.Shortest Distance Using Bellman Ford
4.Exit
4
========================================


*/
