class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        vector<vector<int>> freq(n + 1);
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for(auto [n, c] : mpp) {
            freq[c].push_back(n);
        }

        vector<int> res;

        for(int i = n; i >= 0; i--) {
            for(int n : freq[i]) {
                res.push_back(n);
                if(res.size() == k) return res;
            }
        }
    }
};
