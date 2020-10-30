/*
https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/
*/
//flag is used to if occurance of 3 occurs or not 

#include <iostream>
#include <vector>
#include<cstring>
#include<climits>
#include<bits/stdc++.h>
#include<map>
#include <unordered_map>
#include<iterator>
using namespace std;
long long int dp[1000][1000];
long long int a[1000];

long long int summ(int i,int k)
{
	long long int  ans=0;
	for(int A=i;A<=k;A++)
	{
		ans=(ans+a[A]);
		ans=ans%100;
	}
	return ans%100;
}

long long int solve(int i,int j)
{
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];

	dp[i][j]=INT_MAX;
	for(int k=i;k<=j;k++)	
		dp[i][j]=min(dp[i][j],solve(i,k)+solve(k+1,j)+summ(i,k)*summ(k+1,j));	
		
	return dp[i][j];
}
	

int main() 
{
	int n;		
	while((scanf("%d",&n))>0)
	{		

			for(int i=0;i<=n;i++)					
				for(int j=0;j<=n;j++)
					dp[i][j]=-1;

			for(int i=0;i<n;i++)					
				cin>>a[i];
			if(n==1)
				cout<<"0"<<endl;
			else
				cout<<solve(0,n-1)<<endl;	
				
		
	}
	return 0;
}
