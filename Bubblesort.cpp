#include <iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
    int i,j;
    bool swapped;
    for(i=0;i<n;i++)
    {
        swapped=false;
        for(j=0;j<n-i-1;j++)
        {
           if(arr[j]>arr[j+1])
           {
            swap(arr[j],arr[j+1]);
            swapped=true;
           }
        }
        if(swapped==false)
        {
            break;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,n);
}