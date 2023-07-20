#include <iostream>
#include <vector>
#include <string>
using namespace std;
string findLCS(const string& sequence1, const string& sequence2) {
    int m = sequence1.length();
    int n = sequence2.length();
    
    // Create a matrix of size (m+1) x (n+1) to store LCS lengths
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Perform tabulation
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (sequence1[i - 1] == sequence2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Retrieve the LCS by backtracking through the matrix
    int i = m, j = n;
    string lcs;
    
    while (i > 0 && j > 0) {
        if (sequence1[i - 1] == sequence2[j - 1]) {
            lcs = sequence1[i - 1] + lcs;
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    
    return lcs;
}

int main() {
    string sequence1 = "AGGTAB";
    string sequence2 = "GXTXAYB";
    
    string lcs = findLCS(sequence1, sequence2);
    
    cout << "Longest Common Subsequence: " << lcs << std::endl;
    
    return 0;
}
