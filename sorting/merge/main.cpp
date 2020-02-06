#include <iostream>

using namespace std;


void combine(int arr[] , int low ,int high)
{
    int mid= (low+high)/2;
    int l_size=mid-low+1;
int r_size =high-mid;

    int Left[l_size];
    int Right[r_size];



    for(int i=low ,j=0;j<l_size;i++,j++)
    {
        Left[j]=arr[i];
    }

    for(int i= mid+1,j=0;j<r_size;i++,j++)
    {
        Right[j] = arr[i];
    }

    int l=0;
    int r =0;
    int i=low;
    while(l!=l_size && r!=r_size)
    {
         if(Left[l]<Right[r])
        {
            arr[i]=Left[l];
            l++;
            i++;
        }
        if(Left[l]>Right[r])
        {
            arr[i]=Right[r];
            r++;
            i++;
        }
    }
while(l!=l_size)
{
    arr[i]=Left[l];
    i++;
    l++;
}

while(r!=r_size)
{
    arr[i]=Right[r];
    r++;
    i++;
}

}

void merge_sort(int arr[],int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;

        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        combine(arr,low,high);

    }
}



int main()
{

int arr [5] ={3,1,5,2,4};

merge_sort(arr,0,4);

for(int i=0;i<5;i++)
    cout<<arr[i]<<"  "<<endl;

    return 0;
}
