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

struct Job
{
	string title;
    int size;
};

class Tape
{
	int n;
	Job a[30];
	void exchange(int c,int d);
	void heap_sort();
	void heapify(int,int);
	public:
		void accept(string title,int size);
		void display();
		void solve();	
		Tape()
		{
			n=0;
		}
};

void Tape::accept(string title,int size)		//accept
{
	a[n].title=title;
	a[n++].size=size;
}


void Tape::display()		//display
{
	cout<<"Title     Size "<<endl;
	for(int i=0;i<n;i++)	
		cout<<a[i].title<<"         "<<a[i].size<<endl;		
}

void Tape:: heap_sort()			   //sort using heap sort
{
	int N= n -1; 		           // index of last element
	for(int i=(N-1)/2;i>=0;i--)	   //create max heap
		heapify(i,N);
	
	for(int i=N;i>=0;i--)
	{
		exchange(0,i);	//exchange first and last element
		heapify(0,i-1);		
	}
}

void Tape::exchange(int i, int j)  //swap struct for heap sort
{
	int temp;
	string s;
	temp=a[i].size;
	s=a[i].title;
	a[i].title=a[j].title;
	a[i].size=a[j].size;
	a[j].title=s;
	a[j].size=temp;
}
void Tape :: heapify(int root,int n)    //heapify the array of struct
{
	int largest=root;
	int left= 2*root + 1;
	int right= left+ 1;
	if(left<=n && a[left].size>a[largest].size)	//if left child exists and is greater than the root
		largest= left;
	if(right<=n && a[right].size>a[largest].size)	//if right child exists and is greater than the root and left_child
		largest=right;
	if(largest!= root)							//if root is not the largest
	{	
		exchange(root,largest);
		heapify(largest,n);		//go to the affected sub tree 
	}
}

void Tape::solve()
{
	int Num;		//number of tapes
	heap_sort();
	cout<<"Enter the number of tapes\n";
	cin>>Num;
	Tape* O1 = new Tape[Num];
	for(int i=0;i<n;i++)
	{
		int tape_num=i % Num;
		int count1=O1[tape_num].n;
		O1[tape_num].a[count1].title=a[i].title;
		O1[tape_num].a[count1].size=a[i].size;
		O1[tape_num].n++;
	}
	
	for(int i=0;i<Num;i++)
	{
		int MTR=0;
		cout<<"Contents of Tape "<<i+1<<endl;
		cout<<"title\tsize\n";
		for(int j=0;j<O1[i].n;j++)				//a[i][j] is struct array
		{
			cout<<O1[i].a[j].title<<"\t"<<O1[i].a[j].size<<endl;
			for(int k=0;k<=j;k++)
				MTR+=O1[i].a[k].size;
		}	
		cout<<"MTR: "<<MTR<<endl;
	}	
} 
int main()
{
	int ch,n;
	Tape T;	
	string title;
	int size;
	do
	{
		cout<<"Enter choice \n1.Accept Job\n2.Display Jobs\n3.Calculate\n4.Exit\n";		// do while for choices
		cin>>ch;		
		br;					//break line defined in #define
		switch(ch)
		{
			case 1:				
				
				cout<<"\nEnter no of programs:  ";			
				cin>>n;			
				cout<<"\nEnter Title And Size :  \n";		
				for(int i=0;i<n;i++)
				{
					cin>>title>>size;
					T.accept(title,size);
				}					
				br;				//break line defined in #define
			break;

			case 2:
				T.display();
				fbr;				//break line defined in #define
			break;

			case 3:
				T.solve();
				br;					//break line defined in #define
			break;
		}

	} while(ch!=4);

	return 0;
}



/*     			OUTPUT

Enter choice
1.Accept Job
2.Display Jobs
3.Calculate
4.Exit
1
========================================

Enter no of programs:  5

Enter Title And Size :
P1 8
P2 2
P3 34
P4 23
P5 76
========================================
Enter choice
1.Accept Job
2.Display Jobs
3.Calculate
4.Exit
2
========================================
Title     Size
P1         8
P2         2
P3         34
P4         23
P5         76

========================================
Enter choice
1.Accept Job
2.Display Jobs
3.Calculate
4.Exit
3
========================================
Enter the number of tapes
3
Contents of Tape 1
title   size
P2      2
P3      34
MTR: 38
Contents of Tape 2
title   size
P1      8
P5      76
MTR: 92
Contents of Tape 3
title   size
P4      23
MTR: 23
========================================
Enter choice
1.Accept Job
2.Display Jobs
3.Calculate
4.Exit
3
========================================
Enter the number of tapes
4
Contents of Tape 1
title   size
P2      2
P5      76
MTR: 80
Contents of Tape 2
title   size
P1      8
MTR: 8
Contents of Tape 3
title   size
P4      23
MTR: 23
Contents of Tape 4
title   size
P3      34
MTR: 34
========================================
Enter choice
1.Accept Job
2.Display Jobs
3.Calculate
4.Exit
3
========================================
Enter the number of tapes
5
Contents of Tape 1
title   size
P2      2
MTR: 2
Contents of Tape 2
title   size
P1      8
MTR: 8
Contents of Tape 3
title   size
P4      23
MTR: 23
Contents of Tape 4
title   size
P3      34
MTR: 34
Contents of Tape 5
title   size
P5      76
MTR: 76
========================================
Enter choice
1.Accept Job
2.Display Jobs
3.Calculate
4.Exit
4
========================================



*/
