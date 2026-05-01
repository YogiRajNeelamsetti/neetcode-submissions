class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[i];

                if(sum < 0) {
                    l++;
                } else if(sum > 0) {
                    r--;
                } else {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++, r--;
                }
            }
        }

        vector<vector<int>> res;

        for(auto it : s) {
            res.push_back(it);
        }

        return res;

    }

};
