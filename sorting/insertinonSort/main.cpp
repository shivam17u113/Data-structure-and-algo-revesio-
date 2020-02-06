#include <iostream>

using namespace std;

int binary_search_fun(int arr[], int item , int low, int high)
{
  int mid= (low+high)/2;


if(arr[mid]==item)
    return mid+1;

if(high<=low)
{
if(item<arr[low])
     return low;

return low+1;
}

if(item<arr[mid])
  return  binary_search_fun(arr,item,low,mid-1);

return binary_search_fun(arr,item,mid+1,high);


}




int main()
{


    int arr[10]= {5,4,2,10,3,1,5,3,9,6};
    int key=0,j=0;



    for(int i=0;i<=9;i++)
    {
        // sort even positin
        if(i%2==0)
        {
             key=arr[i];
        j=i-2;

        while(j>=0 && arr[j]>key)
        {

            arr[j+2]=arr[j];
            j=j-2;
        }

        arr[j+2]=key;

        }
        // sort odd position
         if(i%2!=0)
        {
        key=arr[i];
        j=i-2;

        while(j>=0 && arr[j] >key)
        {

            arr[j+2]=arr[j];
            j=j-2;
        }

        arr[j+2]=key;

        for(int i=0;i<10;i++)
         cout<<arr[i]<<"  ";
         cout<<endl;

        }



    }



    return 0;
}
