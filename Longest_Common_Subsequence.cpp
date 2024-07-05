#include<bits/stdc++.h>
using namespace std;
    //Top-Down Approach (Recursive with Memoization)
    int solve(string &t1, string &t2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (t1[i] == t2[j]) {
            dp[i][j] = 1 + solve(t1, t2, i - 1, j - 1, dp);
        } else {
            dp[i][j] = max(solve(t1, t2, i - 1, j, dp), solve(t1, t2, i, j - 1, dp));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence1(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, n - 1, m - 1, dp);
    }

    //Bottom-Up Approach (Iterative with Tabulation)
    int longestCommonSubsequence2(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // Create a 2D DP table with (n+1) x (m+1) size
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // Fill the DP table iteratively
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // The length of the longest common subsequence is stored in dp[n][m]
        return dp[n][m];
    }
    int main() {
        string text1 = "abcde";
        string text2 = "ace";
        cout<< longestCommonSubsequence1(text1, text2) << endl;//recursive function
        cout<< longestCommonSubsequence2(text1, text2) << endl;//tabulation method
        return 0;
    }
