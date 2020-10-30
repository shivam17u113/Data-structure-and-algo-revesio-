#include <iostream>
#include <vector>
#include<cstring>
#include<string>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

long long int  lcs2(vector<int> &a, vector<int> &b) {

	long long int n=a.size();
	long long int m=b.size();


	long long int dp[n+1][m+1];

	memset(dp,0,sizeof(dp));

	for(int i=1;i<n+1;i++)
		for(int j=1;j<m+1;j++)
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);



	int i=n,j=m;
	vector<int> s;

	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			s.push_back(a[i-1]);			
			i--; j--;
		}
		else		
			if(dp[i-1][j]>dp[i][j-1])			
				i--;			
			else 
				j--;		
	}

	cout<<"\nCommon str is ";
	for(int i=s.size()-1;i>=0;i--)
		cout<<s[i]<<" " ;
	cout<<endl;
	
	
	return dp[n][m];
	
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
