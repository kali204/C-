// Fibonaci number using top down approach
#include <iostream>
#include <vector>
using namespace std;
int fib(int n, vector<int> &dp)
{
    // Base condition
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    for (int i = 0; i <= n; i++)
        cout << fib(i, dp);

    return 0;
}
