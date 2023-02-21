class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftSmall = prices[0], curLarge = prices[0], profit = 0;
        for (int index = 1; index < prices.size(); index++)
        {
            curLarge = prices[index];
            profit = max(profit, curLarge - leftSmall);
            leftSmall = min(leftSmall, prices[index]);
        }
        return profit;
    }
};



/*
i   0   1   2   3   4   5
p   7   1   5   3   6   4

index       0   1   2   3   4   5      
leftSmall   7   1   1   1   1   1
curLarge    7   1   5   3   6   4
profit      0   0   4   2   5   3
final       0   0   4   4   5   5
*/