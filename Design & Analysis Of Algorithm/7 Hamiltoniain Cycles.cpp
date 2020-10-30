/*
					SIDDESH SUNIL VYAVAHARE 
						  A3 17U373
						   331067
						   TY IT
*/

/*		REFERENCES ABDUL BARI  YOUTUBE CHANNEL HAMILTONIAN CYCLES      
*/

#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>
using namespace std;
#define br  cout<<"========================================\n";
#define fbr cout<<"\n========================================\n";

class H_Cycles
{
	private:
		int v,e;		//no of vertices and edges 
		int **a;		// pointer approach for storing and accessing 2d matrix for graph
		int *x;			//store hamiltonian cycle in x array
	public:
		void accept();
		void display();
		void Hamiltonian(int );
		void nextVertex(int );
		void displayX();
		H_Cycles()
		{
			cout<<"Enter vertices \n";
			cin>>v;
			a=new int*[v];		//ALLOCATE MEMORY FOR GRAPH 
			x=new int[v];
			for(int i=0;i<v;i++)		//INITIALIZE  WITH VERTEX 0
				x[i]=0;
			for(int i=0;i<v;i++) 	//allocate memory			
				a[i]=new int[v];
			
			for(int i=0;i<v;i++)		//assign weight of graph to infinite if i!=j
				for(int j=0;j<v;j++)									
					*(*(a+i)+j)=0;				
		}
};



void H_Cycles::accept()						//accept the edges
{
	cout<<"Enter no of Edges: ";
	cin>>e;
	int r,c;
	cout<<"Enter Source Destinaion \n";
	for(int i=1;i<=e;i++)
	{
		cin>>r>>c;
		*(*(a+r)+c)=1;
		*(*(a+c)+r)=1;
	}
}

void H_Cycles::display()			//display graph
{
	cout<<"The Matrix is  \n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			cout<<*(*(a+i)+j)<<"\t";		
		cout<<endl;
	}	
}
void H_Cycles:: displayX()		//DISPLAY THE HAMILTON CYCLE
{
	for(int i=0;i<v;i++)
		cout<<x[i]+1<<" ";
	cout<<x[0]+1<<endl;
}

void H_Cycles::Hamiltonian(int k)		// recursive funtion
{
	do
	{		
		if(k==v && a[x[v-1]][x[0]]!=0)			//display when cycle is complete
		{
			displayX();		//display the cycle stored in x and break recusrive call
			return ;
		}
		else 
			nextVertex(k);		//update  the x array 
		if(x[k]==0)		//if after repeating all vertex 0 occurs skip this itreartion
			return;

		if(k==v)		//after processing nextval if k==v display X array		
			displayX();		

		else if(k+1<=v)		
			Hamiltonian(k+1);	// else go to next new pos in x array 

	}while(1);

}
void H_Cycles::nextVertex(int k)
{
	do
	{		
		x[k]=(x[k]+1)%(v); 		//assign all the vertices mod v

		if(x[k]==0)				//if first vertex then break rec calls
			return;		

		if(a[x[k-1]][x[k]]!=0)    // if edge is present then
		{		
			int j=0;
			
			for( j=0;j<=k-1;j++)	//find for dublicate vertex if present break
				if(x[j]==x[k])
					break;
			
			if(j==k)				//if dublicate vertex is present then
				if(k<v || (k==v)&& a[x[v-1]][x[0]]!=0)	// if dublicate vertex is last vertex 
					return;								//and it edge to base vertex print it;
		}

	}while(1);
	
}

int main()
{	
	H_Cycles H;
	int ch;
	do
	{
		cout<<"Enter choice \n1.Accept Graph\n2.Display Graph\n3.Generate All Cycles \n4.Exit\n";		// do while for choices
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
				cout<<"All Hamiltonian Cycles are :\n";
				H.Hamiltonian(1);
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
1.Accept Graph
2.Display Graph
3.Generate All Cycles
4.Exit
1
========================================
Enter no of Edges: 8
Enter Source Destinaion
0 1
0 4
0 2
1 4
1 3
1 2
2 3
3 4
========================================
Enter choice
1.Accept Graph
2.Display Graph
3.Generate All Cycles
4.Exit
2
========================================
The Matrix is
0       1       1       0       1
1       0       1       1       1
1       1       0       1       0
0       1       1       0       1
1       1       0       1       0

========================================
Enter choice
1.Accept Graph
2.Display Graph
3.Generate All Cycles
4.Exit
3
========================================
All Hamiltonian Cycles are :
1 2 3 4 5 1
1 2 5 4 3 1
1 3 2 4 5 1
1 3 4 2 5 1
1 3 4 5 2 1
1 5 2 4 3 1
1 5 4 2 3 1
1 5 4 3 2 1
========================================
Enter choice
1.Accept Graph
2.Display Graph
3.Generate All Cycles
4.Exit
4
========================================

*/
