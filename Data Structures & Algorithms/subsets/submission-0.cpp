class Solution {
public:

    void subsets(int idx, int n, vector<int> subset, vector<vector<int>> &res, vector<int>& nums) {
        if(idx == n) {
            res.push_back(subset);
            return;
        }
        subsets(idx + 1, n, subset, res, nums);
        subset.push_back(nums[idx]);
        subsets(idx + 1, n, subset, res, nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        int n = nums.size();
        subsets(0, n, {}, res, nums);

        return res;
    }
};
