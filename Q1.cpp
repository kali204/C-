#include<iostream>
using namespace std;
int knapsack(int wt[],int val[],int n,int W)
{
    if(W<=0)
    {
        return 0;
    }
    if(n<=0)
    {
        return 0;
    }
    if(wt[n-1]>W)
    {
        return knapsack(wt,val,n-1,W);
    }
    return max(knapsack(wt,val,n-1,W),knapsack(wt,val,n-1,W-wt[n-1])+val[n-1]);

}
int main()
{
    int n;
    cin>>n;
    int wt[n],val[n],W;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    cin>>W;
    cout<<knapsack(wt,val,n,W);
    return 0;
}