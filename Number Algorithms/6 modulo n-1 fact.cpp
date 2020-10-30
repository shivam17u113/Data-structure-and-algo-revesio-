/*
			6. Wilson’s Theorem

Wilson’s theorem is for computing (n − 1)! modulo n for large n.

O(1)


*/
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;


 
// Utility function to do modular exponentiation. 
// It returns (x^y) % p 
int power(int x, unsigned int y, int p) 
{ 
    int res = 1; // Initialize result 
    x = x % p; // Update x if it is more than or 
    // equal to p 
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 



// Function to find modular inverse of a under modulo p 
// using Fermat's method. Assumption: p is prime 
int modInverse(int a, int p) 
{ 
    return power(a, p - 2, p); 
} 
  
// Returns n! % p using Wilson's Theorem 
int modFact(int n, int p) 
{ 
    // n! % p is 0 if n >= p 
    if (p <= n) 
        return 0; 
  
    // Initialize result as (p-1)! which is -1 or (p-1) 
    int res = (p - 1); 
  
    // Multiply modulo inverse of all numbers from (n+1) 
    // to p 
    for (int i = n + 1; i < p; i++) 
        res = (res * modInverse(i, p)) % p; 
    return res; 
}


long long int ansss(int a ,int b)
{
	long long int ans=0;
	while(a!=1)
	{
		if(a==1)
			break;	
		long long int temp=((a%b)*(a-1)%b)%b;
		ans=(ans+temp)%b;
		a--;
	}
	return ans;
} 
  



int main()
{
    cout<<modFact(25,29);
    cout<<ansss(25,29);
	
	return 0;
}



