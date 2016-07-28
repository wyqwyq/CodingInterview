class Solution {
public:
    int getMoneyAmount(int n) {
        if(n <= 1)  return 0;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int k = 1; k < n; k++){
            for(int i = 1; i + k <= n; i++){
                int j = i + k;
                int val = numeric_limits<int>::max();
                for(int m = i; m <= j; m++){
                    val = min(val, m + max(dp[i][m - 1], dp[m + 1][j]));
                }
                dp[i][j] = val;
            }
        }
        
        return dp[1][n];
    }
};
