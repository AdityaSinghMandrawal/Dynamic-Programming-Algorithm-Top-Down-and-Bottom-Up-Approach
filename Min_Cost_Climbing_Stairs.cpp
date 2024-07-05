#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:

    //Top-Down Approach (Recursive with Memoization)
    int solve(int n,vector<int>& cost,vector<int>& dp){
        if(n<=1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=min(solve(n-1,cost,dp),solve(n-2,cost,dp))+cost[n];
        return dp[n];
    }

    //Bottom-Up Approach (Iterative with Tabulation)
    int solve2(int n,vector<int>& cost){
        int dp[n+1];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }

    //Recursive Function Call
    int minCostClimbingStairs1(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return (min(solve(n-1,cost,dp),solve(n-2,cost,dp)));
    }

    //Iterative Function Call
    int minCostClimbingStairs2(vector<int>& cost) {
        int n=cost.size();
        return solve2(n,cost);
    }
};
int main(){
        int n,m;
        cin>>n;
        vector<int> cost(n,0);
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }
        Solution obj;
        int ans1=obj.minCostClimbingStairs1(cost);//recursive function
        int ans2=obj.minCostClimbingStairs2(cost);//tabulation method
        cout<<ans1<<ans2<<endl;
        return 0;
}