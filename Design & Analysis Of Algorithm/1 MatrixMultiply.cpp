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

int strassen(int *A, int *B, int *C, int m, int n)
{
    if(m==2)
    {
        int P=(*A+*(A+n+1))*(*B+*(B+n+1));  //P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1])
        int Q=(*(A+n)+*(A+n+1))*(*B);   //Q=(A[1][0]+A[1][1])*B[0][0]
        int R=(*A)*(*(  B+1)-*(B+n+1));   //R=A[0][0]*(B[0][1]-B[1][1])
        int S=(*(A+n+1))*(*(B+n)-*B);   //S=A[1][1]*(B[1][0]-B[0][0])
        int T=(*A+*(A+1))*(*(B+n+1));   //T=(A[0][0]+A[0][1])*B[1][1]
        int U=(*(A+n)-*A)*(*B+*(B+1));  //U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1])
        int V=(*(A+1)-*(A+n+1))*(*(B+n)+*(B+n+1));  //V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);

        *C=*C+P+S-T+V;  //C[0][0]=P+S-T+V
        *(C+1)=*(C+1)+R+T;  //C[0][1]=R+T
        *(C+n)=*(C+n)+Q+S;  //C[1][0]=Q+S
        *(C+n+1)=*(C+n+1)+P+R-Q+U;  //C[1][1]=P+R-Q+U
    }
    else
    {
        m=m/2;
        strassen(A,B,C,m,n);			//recursive calls for partitioning
        strassen(A,B+m,C+m,m,n);
        strassen(A+m,B+m*n,C,m,n);
        strassen(A+m,B+m*(n+1),C+m,m,n);			//using pointers to update the matrices directly instead
        strassen(A+m*n,B,C+m*n,m,n);				//	of partitioning and merging seperately
        strassen(A+m*n,B+m,C+m*(n+1),m,n);
        strassen(A+m*(n+1),B+m*n,C+m*n,m,n);
        strassen(A+m*(n+1),B+m*(n+1),C+m*(n+1),m,n);
    }
}



int main()
{
	int ch,n,temp;	
	cout<<"\nEnter no of elements:  ";		//accept  size and vector
	cin>>n;	
	int A[n][n],B[n][n],C[n][n];		//matrices
	
	do
	{
		cout<<"Enter choice \n1.Accept \n2.Display \n3.Multiply \n4.Exit\n";		// do while for choices
		cin>>ch;		
		br;					//break line defined in #define
		switch(ch)
		{
			case 1:				
				
				cout<<"\nEnter elements First Matrix:  \n";			//accept 1st martix
				
				for(int i=0;i<n;i++)				
					for(int j=0;j<n;j++)
					{					
						cin>>A[i][j];	
						C[i][j]=0;
					}				
					
				cout<<"\nEnter elements Second Matrix:  \n";		//2nd matrix

				for(int i=0;i<n;i++)				
					for(int j=0;j<n;j++)										
						cin>>B[i][j];				
									
				br;				//break line defined in #define
			break;

			case 2:
				cout<<"\nFirst Matrix: \n";
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
						cout<<A[i][j]<<" "; 		
					cout<<endl;
				}
				cout<<endl;
				cout<<"Second Matrix: \n";
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
						cout<<B[i][j]<<" "; 		
					cout<<endl;
				}
				fbr;				//break line defined in #define
			break;

			case 3:
				strassen(&A[0][0],&B[0][0],&C[0][0],n,n);
				cout<<"\nThird Matrix: \n";
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
						cout<<C[i][j]<<" "; 		
					cout<<endl;
				}
				cout<<endl;				
				br;					//break line defined in #define
			break;
		}

	} while(ch!=4);

	return 0;
}



/*     			OUTPUT


Enter no of elements:  4
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit
1
========================================

Enter elements First Matrix:
1 2 5 7
9 8 7 4
3 2 4 5
0 5 9 33

Enter elements Second Matrix:
6 4 3 1
8 2 4 6
0 7 9 3
5 7 2 1
========================================
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit
2
========================================

First Matrix:
1 2 5 7
9 8 7 4
3 2 4 5
0 5 9 33

Second Matrix:
6 4 3 1
8 2 4 6
0 7 9 3
5 7 2 1

========================================
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit
3
========================================

Third Matrix:
57 92 70 35
138 129 130 82
59 79 63 32
205 304 167 90

========================================
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit
4
========================================


Enter no of elements:  2
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit
1
========================================

Enter elements First Matrix:
1 1
1 1

Enter elements Second Matrix:
2 2
2 2
========================================
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit
2
========================================

First Matrix:
1 1
1 1

Second Matrix:
2 2
2 2

========================================
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit
3
========================================

Third Matrix:
4 4
4 4

========================================
Enter choice
1.Accept
2.Display
3.Multiply
4.Exit





*/
