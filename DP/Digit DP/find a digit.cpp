/*


https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/


*/

//flag is used to if occurance of 3 occurs or not 




#include <iostream>
#include <vector>
#include<cstring>
#include<bits/stdc++.h>
#include<map>
#include <unordered_map>
#include<iterator>
using namespace std;
using std::vector;
#define ll long long int
long long int dp[10][2][2];			// digits,tight ,flag

 //   flag== if 3 is present or not

long long int solve(string s,ll pos=0,ll tight=1,ll flag=0)
{
	if(pos==s.size())
	{
		if(flag==1)
			return 1;
		else 
			return 0;
	}

	else if(dp[pos][tight][flag]!=-1)	
		return dp[pos][tight][flag];

	else if(tight ==1)
	{
		ll res=0;
		for(int i=0;i<=s[pos]-'0';i++)
		{
			ll flg=flag;
			if(i==3)
				flg=1;

			if(i==s[pos]-'0')	  		//if i==s[pos] then tight val =1;		
				res+=solve(s,pos+1,1,flg);
			else
				res+=solve(s,pos+1,0,flg);	//else tight val=0;		
		}
		dp[pos][tight][flag]=res;
		return res;	
	}
	else if(tight==0)  //yes
	{
		ll res=0;
		for(int i=0;i<=9;i++)
		{
			ll flg=flag;
				if(i==3)
					flg=1;
			res+=solve(s,pos+1,0,flg);	//tight val =0 for normal
		}
		dp[pos][tight][flag]=res;
		return res;
	}
}


int main() 
{
	int t;
	cin>>t;
	long long int n;
	while(t--)
	{	
		cin>>n;		
		memset(dp,-1,sizeof(dp));
		string a=to_string(n);
		cout<<n-solve(a)<<endl;			
	}
	return 0;
}
