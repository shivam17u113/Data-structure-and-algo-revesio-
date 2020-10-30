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
int m=1003;
long static dp[1001][1001][2];
int solve(string s,int i,int j,bool istrue)
{
    if(i>j)
        return false;
    if(i==j)
        if(istrue==1)
            return s[i]=='T';
        else 
            return s[i]=='F';
    if(dp[i][j][istrue]!=-1)
        return dp[i][j][istrue];
        
    long int ans=0;
    for(int k=i+1;k<j;k=k+2)
    {
        int lt,rt,lf,rf;
        
        if(dp[i][k-1][1]!=-1)
            lt=dp[i][k-1][1];
        else
            lt=solve(s,i,k-1,1);
            
        if(dp[k+1][j][1]!=-1)
            rt=dp[k+1][j][1];
        else
            rt=solve(s,k+1,j,1);
            
        if(dp[i][k-1][0]!=-1)
            lf=dp[i][k-1][0];
        else
            lf=solve(s,i,k-1,0);
            
        if(dp[k+1][j][0]!=-1)
            rf=dp[k+1][j][0];
        else
         rf=solve(s,k+1,j,0);
        
        
        if(s[k]=='|')
        {
            if(istrue==1)
                ans=(ans+lt*rf+rt*lf+lt*rt)%m;
            else
                ans=(ans+rf*lf)%m;
        }
        else if(s[k]=='&')
        {
            if(istrue==1)
                ans=(ans+lt*rt)%m;
            else
                ans=(ans+lt*rf+lf*rt+rf*lf)%m;
        }
        else if(s[k]=='^')
        {
            if(istrue==1)
                ans=(ans+lt*rf+lf*rt)%m;
            else
                ans=(ans+lt*rt+lf*rf)%m;
        }
    }
    return dp[i][j][istrue]=ans;
}




int Solution::cnttrue(string A) {
    memset(dp,-1,sizeof(dp));
    
    return solve(A,0,A.size()-1,true)%m;
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
