/*
			4. Goldbach’s Conjecture Algorithm

It states that, “Every even integer greater than 2 can be expressed as the sum of two primes“. In other words, 
a Goldbach number is a positive integer that can be expressed as the sum of two primes.

Time Complexity : O(log^2(n)) // order of log square n

https://www.geeksforgeeks.org/program-for-goldbachs-conjecture-two-primes-with-given-sum/


*/
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int MAX = 10000; 
  
// Array to store all prime less than and equal to 10^6 
vector <int> primes; 
  
// Utility function for Sieve of Sundaram 
void sieveSundaram() 
{ 
    // In general Sieve of Sundaram, produces primes smaller 
    // than (2*x + 2) for a number given number x. Since 
    // we want primes smaller than MAX, we reduce MAX to half 
    // This array is used to separate numbers of the form 
    // i + j + 2*i*j from others where 1 <= i <= j 
    bool marked[MAX/2 + 100] = {0}; 
  
    // Main logic of Sundaram. Mark all numbers which 
    // do not generate prime number by doing 2*i+1 
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++) 
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1) 
            marked[j] = true; 
  
    // Since 2 is a prime number 
    primes.push_back(2); 
  
    // Print other primes. Remaining primes are of the 
    // form 2*i + 1 such that marked[i] is false. 
    for (int i=1; i<=MAX/2; i++) 
        if (marked[i] == false) 
            primes.push_back(2*i + 1); 
} 
  
// Function to perform Goldbach's conjecture 
void findPrimes(int n) 
{ 
    // Return if number is not even or less than 3 
    if (n<=2 || n%2 != 0) 
    { 
        cout << "Invalid Input \n"; 
        return; 
    } 
  
    // Check only upto half of number 
    for (int i=0 ; primes[i] <= n/2; i++) 
    { 
        // find difference by subtracting current prime from n 
        int diff = n - primes[i]; 
  
        // Search if the difference is also a prime number 
        if (binary_search(primes.begin(), primes.end(), diff)) 
        { 
            // Express as a sum of primes 
            cout << primes[i] << " + " << diff << " = "
                 << n << endl; 
            return; 
        } 
    } 
} 


int main()
{
	sieveSundaram();
	findPrimes(5);
	findPrimes(21);
	findPrimes(38);
	findPrimes(100);	
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
