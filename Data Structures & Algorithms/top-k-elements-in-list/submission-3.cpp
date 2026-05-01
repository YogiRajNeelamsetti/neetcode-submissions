class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> res;

        vector<int> freq(2001, 0);
        for(int i = 0; i < n; i++) {
            freq[nums[i] + 1000]++;
        }

        vector<vector<int>> bucket(n + 1);
        for(int i = 0; i < 2001; i++) {
            if (freq[i] > 0) {
                bucket[freq[i]].push_back(i - 1000);
            }
        }

        for(int i = n; i >= 1; i--) {
            for (int val : bucket[i]) {
                res.push_back(val);
                if(res.size() == k) return res;
            }
        }

        return res;
    }
};