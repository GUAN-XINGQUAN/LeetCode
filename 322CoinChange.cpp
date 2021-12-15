class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int residual = i - coins[j];
                if (residual >= 0)
                    dp[i] = min(dp[i], dp[residual]+1);
            }
        }
        
        if (dp.back() > amount)
            return -1;
        return dp.back();
    }
};