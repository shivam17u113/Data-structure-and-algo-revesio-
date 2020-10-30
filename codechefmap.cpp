#include <iostream>
using namespace std;
int cnt=0;

int BIN(int a[100],int l,int r,int key)
{
	if(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==key)
		{
			cnt++;
			// return mid;
		}
		if(a[mid]>=key)
		{
			 BIN(a,l,mid-1,key);
		}
		if(a[mid]<=key)
		{
			 BIN(a,mid+1,r,key);
		}
	}
	return -1;
}


int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int key;
	cin>>key;

	BIN(a,0,n-1,key);
	cout<<cnt;
	
	return 0;
}
