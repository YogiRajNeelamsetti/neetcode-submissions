class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int mini = prices[0];

        for(int &sell : prices) {
            profit = max(profit, sell - mini);
            mini = min(mini, sell);
        }
        
        return profit;
    }
};
