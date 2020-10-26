/*
			5. Optimized Fibonacci Series Solution { Matrix Based Solution }

This algorithm is used to find the n-th number of a fibonacci series. It is done with the help of matrix manipulation.

Time Complexity : O(log n)

O(1)


*/
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;

  
long long int fib(long long int n) { 
    
    double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 
  

int main()
{
    std::cout << fib(0) << std::endl; 
	std::cout << fib(1) << std::endl; 
    std::cout << fib(2) << std::endl; 
    std::cout << fib(3) << std::endl; 
    std::cout << fib(4) << std::endl; 
    std::cout << fib(5) << std::endl; 
    std::cout << fib(6) << std::endl; 
    std::cout << fib(7) << std::endl; 
    std::cout << fib(8) << std::endl; 
    std::cout << fib(45) << std::endl; 

	
	return 0;
}



