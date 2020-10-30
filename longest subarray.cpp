/*
			Consider an array A. 
			Your job is to find longest subarray in which elements greater than x are more than elements not greater than x.

Input

1. size of array , x
2. Array elements

Example

Input

5 5
4 5 7 8 3

Output

3

Explanation

Subarray formed : [5,7,8]
*/


#include <iostream>
#include<bits/stdc++.h>
#include<map>
#include<iterator>
#include<string>
#include<set>
#include<vector>
#include<stack>
using namespace std;


int main()
{
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0; i<n;i++)
		cin>>a[i];
	int max=0;
	int cnt=0;
	for(int i=0; i<n; i++)
	{
		cnt=0;
		for(int j=i;j<n;j++)
		{	
			if(a[j]==x)
			{ }	
			else if(a[j]>x)
			{
				cnt++;
			}
			else if(a[j]<x)
			{
				cnt--;
			}
			if(max<(j-i) && cnt>0)
			{
				max=j-i;
				cout<<i<<" " <<max<<endl;
			}
		}
	}
	cout<<max;
	return 0;
}

