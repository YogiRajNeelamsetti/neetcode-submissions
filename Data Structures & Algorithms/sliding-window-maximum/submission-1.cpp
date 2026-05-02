class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxArray;
        priority_queue<pair<int, int>> pq;
        int maxi = INT_MIN;
        int maxIdx = 0;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        maxArray.push_back(pq.top().first);

        for(int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});
            while(!pq.empty() && pq.top().second < i - k + 1) {
                pq.pop();
            }
            maxArray.push_back(pq.top().first);
        }

        return maxArray;
    }
};
