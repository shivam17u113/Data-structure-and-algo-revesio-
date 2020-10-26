
#include <iostream>
#include <vector>
#include<cstring>
#include<bits/stdc++.h>
#include<map>
#include <unordered_map>
#include<iterator>
using namespace std;

void computeZ(string a,int Z[])
{
	int n=a.size();
	int L,R,k;
	L=R=0;
	Z[0]=0;
	for(int i=1;i<n;i++)
	{
		if(i>R)
		{
			L=R=i;
			while(R<n && a[R-L]==a[R])
				R++;
			Z[i]=R-L;
			R--;
		}
		else 
		{
			k=i-L;
			if(Z[k]<R-i+1)
			{
				Z[i]=Z[k];
			}
			else
			{
				L=i;
				while(R<n && a[R-L]==a[R])
					R++;
				Z[i]=R-L;
				R--;
			}
		}
	}
}

void Z(string text,string pattern)
{
	vector<int> ans;
	int cnt=0;
	string  a=pattern + '$'+ text;
	int n=a.size();

	int Z[n];

	computeZ(a,Z);

	for (int i = 0; i < n; ++i)
	{
		if(Z[i]==pattern.size())
			ans.push_back(i-pattern.size()-1);
			// cnt++;
	}
	if(ans.size()!=0)
	{


		cout<<ans.size()<<endl;
		for (int i = 0; i < ans.size(); ++i)	
			cout<<ans[i]+1<<" " ;
		cout<<endl;
	}
	else
		cout<<"Not Found\n";
	ans.clear();
}



int main() 
{
	int a,n;
	cin>>n;
	string s,s2;
	// cin>>s;
	while(n--)
	{
		cin>>s>>s2;
		Z(s,s2);
	}
	
	return 0;
}
