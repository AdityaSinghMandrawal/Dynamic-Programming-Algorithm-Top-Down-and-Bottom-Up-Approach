#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Top-Down Approach (Recursive with Memoization)
int solve1(int i,int j,vector<int>& v,vector<vector<int>>& dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    int step=0;
    for(int k=i;k<j;k++){
        step=v[i-1] * v[k] * v[j] + solve1(i,k,v,dp) + solve1(k+1,j,v,dp);
        if(step<mini){
            mini=step;
        }
    }
    dp[i][j]=mini;
    return dp[i][j];
}

//Bottom-Up Approach (Iterative with Tabulation)
int solve2(vector<int>& v){
    int n=v.size();
    int dp[n][n];
    for(int i=1;i<n;i++){
        dp[i][i]=0;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=INT_MAX;
            for(int k=i;k<j;k++){
                int step=v[i-1] * v[k] * v[j] + dp[i][k] + dp[k+1][j];
                if(step<mini){
                    mini=step;
                }
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}
    int minScoreTriangulation1(vector<int>& v) {
     int n=v.size();   
     vector<vector<int>> dp(n,vector<int>(n,-1));
     return solve1(1,n-1,v,dp);
    }
    int minScoreTriangulation2(vector<int>& v) {
     int n=v.size();
     return solve2(v);
    }
};
int main() {
    vector<int> vertices = {1, 3, 1, 4, 1, 5};
    Solution sol;
    int result1 = sol.minScoreTriangulation1(vertices);//recursive function
    int result2 = sol.minScoreTriangulation2(vertices);//tabulation method
    cout << "Minimum score triangulation: " << result1 << endl;
    cout << "Minimum score triangulation: " << result2 << endl;
    return 0;
}