#include <iostream>
#include <vector>
#include<cstring>
#include<bits/stdc++.h>
#include<map>
#include<set>
#include <unordered_map>
#include<iterator>
using namespace std;
using std::vector;
#define ll long long int
long long int dp[10][80][2];			// digits,sum,tight
long long int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};


bool check(ll sum)
{
	return binary_search(prime,prime+23,sum);
}



long long int solve(string s,ll pos=0,ll sum=0,ll tight=1)
{
	if(pos==s.size())
	{
		if(check(sum))
			return 1;
		else 
			return 0;
	}
	else if(dp[pos][sum][tight]!=-1)	
		return dp[pos][sum][tight];
	else if(tight ==1)
	{
		ll res=0;
		for(int i=0;i<=s[pos]-'0';i++)
		{
			if(i==s[pos]-'0')			
				res+=solve(s,pos+1,sum+i,1);
			else
				res+=solve(s,pos+1,sum+i,0);			
		}
		dp[pos][sum][tight]=res;
		return res;
	}
	else if(tight==0)
	{
		ll res=0;
		for(int i=0;i<=9;i++)
			res+=solve(s,pos+1,sum+i,0);
		dp[pos][sum][tight]=res;
		return res;
	}
}


int main() 
{
	int t;
	cin>>t;
	long long int a=0,b=0;
	while(t--)
	{	
		cin>>a>>b;
		a--;
		memset(dp,-1,sizeof(dp));
		string p=to_string(a);
		string q=to_string(b);
		long long int ans1=solve(p);
		memset(dp,-1,sizeof(dp));
		long long int ans2=solve(q);
		cout<<ans2-ans1<<endl;
			
	}
	return 0;
}
