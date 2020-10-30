#include <iostream>
#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;

string shortestCommonSupersequence(string a, string b) {
        
        int n=a.size();
        int m=b.size(); 
         int  dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
           
        for(int i=1;i<a.size()+1;i++)
        {
            for(int j=1;j<b.size()+1;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];    
                
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);                    
            }
        }   
        int i=a.size(),j=b.size();
        
        string ansss="";
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ansss.push_back(a[i-1]);
                i--, j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ansss.push_back(a[i-1]);
                    i--;
                }
                else
                {
                    ansss.push_back(b[j-1]);
                    j--;
                }
            }
        }    
        
        
            while(j>0)
            {
                ansss.push_back(b[j-1]);
                j--;
            }
        
       
            while(i>0)
            {
                ansss.push_back(a[i-1]);
                i--;
            }
              reverse(ansss.begin(),ansss.end());
        return ansss;      
    
    }

int main()
{
    string s,s2;
    cin>>s>>s2;
    
    cout<<shortestCommonSupersequence(s,s2  )<<endl;

    return 0;
}




/*
int main()
{
    int t;
    cin>>t;
    map<int,int> m;
    map<int,int> :: iterator itr;   

    while(t>0)
    {
       
        int temp=0;
        int n,b;

        cin>>n>>b;
        int a[n];
         // cout<<" +++ 00 ";
        for(int i=0;i<n;i++)
        {        
            cin>>a[i];

            m[a[i]]++;
            // cout<<" +++1 ";
        }

        // cout<<" +++2 ";

        // for(itr!=m.begin();itr!=m.end();itr++)
        //         cout<<itr->first<<" "<< itr->second;


            int cnt=0,sum=0,flag=0;
            for(itr!=m.begin();itr!=m.end();itr++)
            {
                if(itr->first<=sum)
                {
                    while(itr->second!=0)
                    {
                        if(itr->first+sum<=b)
                        {
                            sum+=itr->first;
                            itr->second--;
                            cnt++;   
                       }
                       else
                       { 
                            flag=1;
                            break;
                        }
                    }            
                }
                if(flag=1)
                        break;
                cnt++;
            }

            cout<<cnt;
            t--;
        }



  
    return 0;
}
*/















/*
int xorArray(int arr[], int n) 
{ 
    int res = 0; 
    for (int i = 0; i < n; i++) 
        res = res ^ arr[i]; 
  
    return res; 
} 
  
// Function to return the count of ways 
// to play the first move optimally 
long getTotalWays(int arr[], int n) 
{ 
  
    // XOR of all the array elements 
    long xorArr = xorArray(arr, n); 

  
    // The player making the first move 
    // can't win the game no matter 
    // how optimally he plays 
    if (xorArr == 0) 
        return 0; 
  
    // Initialised with zero 
    long numberOfWays = 0,cnt=0; 
    for (int i = 0; i < n; i++) 
    {
        long requiredCoins = xorArr ^ arr[i];   
        if (requiredCoins < arr[i]) 
            numberOfWays++; 
    } 
   

  
    return (numberOfWays%998244353); 
} 
  


int main() 
{
    int T,n,l,r,q;
    cin>>T;
    
    map <int,int> ::iterator itr;
   

   while(T>0)
    {       
        cin>>n;
        int flag=1;
        
        vector <int> a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cin>>q;
        for(int k=0;k<q;k++)
        {
            map <int,int> m;
            cin>>l>>r;
            if(l==r)
            {
                cout<<"1\n";
                continue;
            }
            int b[n],p=0;

            for(int j=l;j<=r;j++)
            {
                b[p++]=a[j];
                m[a[j]]++;
                itr=m.find(a[j]);
                if(itr->first==a[j] && itr->second>1)
                {
                    flag=0;
                }
            }
            if(flag==0)
            {
                cout << getTotalWays(b, r-l+1)<<endl;
            }
            else if(flag==1)
            {
                if((r-l+1)%2==0)
                {
                    cout<<"0\n";
                }
                else
                    cout<<"1\n";
            } 
            flag=1;
        }

        T--;
        
    }   
    return 0;
}
*/
