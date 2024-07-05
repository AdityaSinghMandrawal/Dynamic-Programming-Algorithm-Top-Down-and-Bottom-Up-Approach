//Top-Down Approach (Recursive with Memoization)

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n <= 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = solution.fib(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    return 0;
}

//Bottom-Up Approach (Iterative with Tabulation)

#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main() {
    int n = 10;
    cout << "Fibonacci number " << n << " is " << fib(n) << endl;
    return 0;
}
