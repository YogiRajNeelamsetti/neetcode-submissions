class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0;
        int l = 0, r = 1;

        while(r < n) {
            if(prices[l] < prices[r]) {
                profit = max(profit, prices[r] - prices[l]);
            } else {
                l = r;
            }
            r++;
        }
        return profit;
    }
};
