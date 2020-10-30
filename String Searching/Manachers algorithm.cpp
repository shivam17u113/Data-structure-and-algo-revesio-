
#include <iostream>
#include <vector>
#include<cstring>
#include<bits/stdc++.h>
#include<map>
#include <unordered_map>
#include<iterator>
using namespace std;

void palindome(string s)
{
	string a="";
	a+='$';
	for(int i=0;i<s.size();i++)
	{
		a=a+"#";
		a=a+s[i];
	}
	a=a+"#@";
	vector<int> P(a.size());
	for (int i = 0; i < P.size(); ++i)
		P[i]=0;
	int C=0,R=0;

	for(int i=1;i<a.size()-1;i++)
	{
		int mir=2*C-i;

		if(i<R)
			P[i]=min(R-i,P[mir]);

		while(a[i+(1+P[i])]==a[i -(1+P[i])])
			P[i]++;

		if(i+P[i]>R)
		{
			C=i;
			R=i+P[i];
		}
	}

	string ans;
	int index,max=0;
	for (int i = 0; i < P.size(); ++i)
	{
		cout<<P[i]<<" " ;
		if(max<P[i])
		{
			index=i;
			max=P[i];
		}	
	}
	for(int i=index;i>=0;i--)
	{
		if(a[i]=='#' || a[i]=='$')
			continue;
		else
		{
			ans+=a[i];
		}
	}
	cout<<ans;
	auto itr=ans.begin();
	itr++;
	string ans2=ans.substr(1,ans.size());
	reverse(ans2.begin(),ans2.end());
	ans=ans2+ans;

	cout<<endl<<ans<<endl;
	cout<<s.size()<<" " <<a.size()<<endl;

	
}






int main() 
{
	string s;
	cin>>s;	
	palindome(s);
	return 0;
}
