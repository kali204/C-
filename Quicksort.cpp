#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;//3
    swap(arr[pivotIndex], arr[s]);//35,25  {15,20,25,35}

    // left and right wala part
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quicksort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return ;
    }

    // partition karna hai
    int p = partition(arr, s, e);

    // left part sort karo
    quicksort(arr, s, p - 1);//2

    // right part sort karo
    quicksort(arr, p + 1, e);
    
}
int main()
{
    int arr[4] = {35,20,15,25};
    int n = 4.;
    quicksort(arr, 0, n - 1);//quicksort function call....

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}