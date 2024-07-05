#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    //Top-Down Approach (Recursive with Memoization)
    int solve1(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = solve1(coins, amount - coins[i], dp);
            if (ans != INT_MAX) {
                mini = min(mini, ans + 1);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    //Bottom-Up Approach (Iterative with Tabulation)
    int solve2(vector<int> &coins,int t){
        vector<int> dp(t+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=t;i++){
            for(int j=0;j<=coins.size();j++){
                if(i-coins[j]>=0&&dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[t]==INT_MAX){
            return-1;
        }
        else{
            return dp[t];
        }
    }

    //Recursive Function Call
    int coinChange1(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve1(coins, amount, dp);
        if (ans != INT_MAX) {
            return ans;
        } else {
            return -1;
        }
    }

    //Iterative Function Call
    int coinChange2(vector<int>& coins, int amount) {
        int ans = solve2(coins, amount);
        if (ans != INT_MAX) {
            return ans;
        } else {
            return -1;
        }
    }
};

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    Solution solution;
    int ans1 = solution.coinChange1(coins, amount);//recursive function
    int ans2 = solution.coinChange2(coins, amount);//tabulation method
    cout << ans1 << ans2 << endl;
    return 0;
}