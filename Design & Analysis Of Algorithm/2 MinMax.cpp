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

struct ans  //structure of min and max
{
	int max;
	int min;
};

struct ans solve(vector<int>a,int l,int h)		// returning structure for max and min val
{
	struct ans s,a1,a2;			//structures for 2 values 
	if(l==h)					//same index same min max		
	{
		s.max=a[h];
		s.min=a[l];
		return s;
	}
	else if(l==h-1)				//only last 2 elements return min max by comparing
	{
		if(a[l]<a[h])
		{
			s.max=a[h];
			s.min=a[l];
			return s;
		}
		else
		{
			s.min=a[h];
			s.max=a[l];
			return s;
		}
	}
	int mid=(l+h)/2;
	a1=solve(a,l,mid);		// recursive calls for left half
	a2=solve(a,mid+1,h);	//recursive calls for right half

	struct ans ANS;

	if(a1.max>a2.max)	// after all recusive calls returned values of min and max
		ANS.max=a1.max;
	else
		ANS.max=a2.max;

	if(a1.min<a2.min)
		ANS.min=a1.min;
	else
		ANS.min=a2.min;

	return ANS;					//returned after all recurisve calls
}

int main()
{
	int ch,n,temp;	
	vector<int>a;
	do
	{
		cout<<"Enter choice \n1.Accept \n2.Display \n3.Min Max \n4.Exit\n";		// do while for choices
		cin>>ch;		
		br;					//break line defined in #define
		switch(ch)
		{
			case 1:	
				a.clear();	
				cout<<"\nEnter no of elements:  ";		//accept  size and vector
				cin>>n;	
				cout<<"\nEnter elements:  \n";					
				for(int i=0;i<n;i++)
				{
					cin>>temp;				
					a.push_back(temp);
				}
				br;				//break line defined in #define
			break;

			case 2:

				for(int i=0;i<n;i++)
					cout<<a[i]<<" " ;
				fbr;				//break line defined in #define
			break;

			case 3:
					int l=0;
					int h=n-1;
					struct ans ANS=solve(a,l,h);
					cout<<" Min = "<<ANS.min<<" Max = "<<ANS.max<<endl;
					br;					//break line defined in #define
			break;
		}

	} while(ch!=4);

	return 0;
}


		*
	*		*
*	*	*	*






/*     			OUTPUT

Enter choice
1.Accept
2.Display
3.Min Max
4.Exit
1
========================================

Enter no of elements:  10

Enter elements:
66 32 -1 54 777 -123 0 951 -44 12345
========================================
Enter choice
1.Accept
2.Display
3.Min Max
4.Exit
2
========================================
66 32 -1 54 777 -123 0 951 -44 12345
========================================
Enter choice
1.Accept
2.Display
3.Min Max
4.Exit
3
========================================
 Min = -123 Max = 12345
========================================
Enter choice
1.Accept
2.Display
3.Min Max
4.Exit
1
========================================

Enter no of elements:  5

Enter elements:
-95 95 -123 987 0
========================================
Enter choice
1.Accept
2.Display
3.Min Max
4.Exit
2
========================================
-95 95 -123 987 0
========================================
Enter choice
1.Accept
2.Display
3.Min Max
4.Exit
3
========================================
 Min = -123 Max = 987
========================================
Enter choice
1.Accept
2.Display
3.Min Max
4.Exit
4
========================================

*/
