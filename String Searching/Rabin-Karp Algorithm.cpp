/*
			5. Rabin-Karp Algorithm

It is a string-searching algorithm created by Richard M. Karp and Michael O. 
Rabin that uses hashing to find an exact match of a pattern string in a text.

Time Complexity : O(n)

https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

*/
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define mod 101

#define X 1000002





// void search(char pat[], char txt[], int m,int n,int q)  
// {  
//     int M = m;  
//     int N = n;  
//     int i, j;  
//     int p = 0; // hash value for pattern  
//     int t = 0; // hash value for txt  
//     int h = 1;  
  
//     // The value of h would be "pow(d, M-1)%q"  
//     for (i = 0; i < M - 1; i++)  
//         h = (h * d) % q;  
  
//     // Calculate the hash value of pattern and first  
//     // window of text  
//     for (i = 0; i < M; i++)  
//     {  
//         p = (d * p + pat[i]) % q;  
//         t = (d * t + txt[i]) % q;  
//     }  
  
//     // Slide the pattern over text one by one  
//     for (i = 0; i <= N - M; i++)  
//     {  
  
//         // Check the hash values of current window of text  
//         // and pattern. If the hash values match then only  
//         // check for characters on by one  
//         if ( p == t )  
//         {  
//             /* Check for characters one by one */
//             for (j = 0; j < M; j++)  
//             {  
//                 if (txt[i+j] != pat[j])  
//                     break;  
//             }  
  
//             // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]  
//             if (j == M)  
//                 cout<<"Pattern found at index "<< i<<endl;  
//         }  
  
//         // Calculate hash value for next window of text: Remove  
//         // leading digit, add trailing digit  
//         if ( i < N-M )  
//         {  
//             t = (d*(t - txt[i]*h) + txt[i+M])%q;  
  
//             // We might get negative value of t, converting it  
//             // to positive  
//             if (t < 0)  
//             t = (t + q);  
//         }  
//     }  
// }  


// void aaa(char pattern[],char  txt[],int M,int N)     //a string   b pattern
// {
//     vector<long long int> ans;
//     int n=N;
//     int m=M;

//     long long int p=0,t=0;
//     long long int h=1;
//     for(int i=0;i<m-1;i++)
//     {
//         h=(h*d)%mod;
//     }
//     for(int i=0;i<m;i++)
//     {
//         p=(d*p+pattern[i])%mod;
//         t=(256*t+txt[i])%mod;
//     }
//     for(int i=0;i<=n-m;i++)
//     {
//         if(p==t)
//         {
//             int j=0;
//             for(j=0;j<m;j++)
//             {
//                 if(txt[i+j]!=pattern[j])
//                     break;
//             }       
//             if(j==m)                           
//                 ans.push_back(i);
            
//         }
//         else if(i<n-m)
//         {
//             t=((d*(t-txt[i]*h))+txt[i+m])%mod;
//             if(t<0)
//                 t+=mod;
//         }
//     }
//     if(ans.size()!=0)
//     {
//         cout<<ans.size()<<endl;
//         for(int i=0;i<ans.size();i++)
//         {
//             cout<<ans[i]+1;
//             if(ans.size()!=i+1)
//                 cout<<" ";
//         }
//     }
//     else 
//         cout<<"NOT FOUND";
//     cout<<endl;
//     ans.clear();
// }

#define MU 123
#define ULL unsigned long long
ULL HASH[1000009];


void preHASH(char str[] , int n)
{
    HASH[n] = 0;
    for(int i = n-1 , j = 1 ; i>=0 ; i-- , j++){
        HASH[i] = HASH[i+1]*MU + str[i] - 97;
    }
}
void solve(char text[] , char pattern[] , int p , int t){
    ULL p_HASH = 0 , check , pre = 1;
    for(int i = p-1 ; i>=0 ; i--){
        p_HASH = p_HASH*MU + pattern[i] - 97;
        pre = pre*MU;
    }
    check = p_HASH;
    vector<int> v;
    int flag = 0;
    preHASH(text , t);
    for(int i = 0; i < t - p + 1 ; i++ )
        if(HASH[i] - pre*HASH[i+p] == check){
            flag++;
            v.push_back(i+1);
        }
    if(flag == 0)
        printf("Not Found\n");
    else
    {
        printf("%d\n",flag);
        for(int i = 0 ; i < flag ; i++)
            printf("%d ",v[i]);
        printf("\n");
    }
}



int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char text[1000009] ,  pattern[1000009];
        scanf("%s%s",text , pattern);
        int n , m ;
        n = strlen(text);
        m = strlen(pattern);
        solve(text , pattern , m , n);
    }
	return 0;
}

