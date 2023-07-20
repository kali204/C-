#include<bits/stdc++.h>
using namespace std;
void FO(int arr[],int l,int r,int key)
{
    while(l<=r)
    {
       int mid=l+(r-l)/2;
       if(arr[mid]==key)
       {
          cout<<mid;
          r=mid-1;
       }
       if (arr[mid]>key)
       {
        l=mid+1;        /* code */
       }
       else{
        r=mid-1;
       }   
    }
}
void EO(int arr[],int l,int r,int key)
{
   
    while(l<=r)
    {
       int mid=l+(r-l)/2;
       if(arr[mid]==key)
       {
          cout<<mid;
          l=mid-1;
       }
       if (arr[mid]>key)
       {
        l=mid+1;        /* code */
       }
       else{
        r=mid-1;
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
    sort(arr,arr+n);
    int key;
    cin>>key;
    FO(arr,0,n,key);
    EO(arr,0,n,key);
}