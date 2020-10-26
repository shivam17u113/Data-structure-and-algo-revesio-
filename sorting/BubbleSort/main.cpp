#include<iostream> 
#include <bits/stdc++.h> 
using namespace std; 
  
void exchange(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

vector<int>  bubbleSort(vector<int> a, int n)  
{  
    for (int i = 0; i < n-1; i++) 
        for (int j = 0; j < n-i-1; j++)  
            if (a[j] > a[j+1])  
                exchange(&a[j], &a[j+1]); 
    return a;
}  
  

void Display(vector<int> a, int size)  
{ 
    for (int i = 0; i < size; i++)  
        cout << a[i] << " ";  
    cout << endl;  
}  
   
int main()  
{  
    vector<int> a;
    int n,b;
    cin>>n;
    for (int i = 0; i < n; ++i)
     {
         cin>>b;
         a.push_back(b);
     } 
    a=bubbleSort(a, n);  
    cout<<"Sorted elements: \n";  
    Display(a, n);  
    return 0;  
} 