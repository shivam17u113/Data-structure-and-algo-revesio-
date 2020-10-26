/*
			3. Prime Factorization using Sieve

This algorithm is used to find the prime factors of a given number. It can be seen as an application of Sieve.

Time Complexity : O(logn)


https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/


*/
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define MAXN 100000000 
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(long long int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}


int main()
{
	int n=30;
	sieve();
    vector<int>p =getFactorization(137384478/2);
    for(int i=0;i<p.size();i++)	
        cout<<p[i]<<" ";
    cout<<endl;
	return 0;
}



/*

int primeFactors(int n)  
{      
    long long int  cnt=0;
    while (n % 2 == 0)  
    {     
        cout<<" a 2  ";   
        cnt++;  
        n = n/2;  
    }  
    cout<<n<<" ";
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {          
        while (n % i == 0)  
        {         
            cnt++;
            cout<<" b "<<i<<" ";
            n = n/i;  
        }  
    }   
    
    if (n > 2) 
    { 
        cnt++;
        cout<<n<<endl;
    }
    return cnt;
}  */
