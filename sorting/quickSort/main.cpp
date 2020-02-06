#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition_make(int arr[] ,int low ,int high)
{
    int pivote =arr[high];
    int i=low-1;

    for(int j=low;j<=high;j++)
    {
        if(arr[j]<pivote)
        {
            i++;

           swap(&arr[i],&arr[j]);

        }
    }
   swap(&arr[i+1],&arr[high]);

   return i+1;
}



void quick_sort(int arr[], int low , int high)
{
    if(low<high)
    {
        int pi= partition_make(arr,low,high);

        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);

    }


}


int main()
{
   int arr[7] ={8,1,6,2,5,4} ;

   quick_sort(arr,0,5);

   for(int i=0;i<6; i++)
    cout<<arr[i]<<"  ";
   cout<<endl;
    return 0;
}
