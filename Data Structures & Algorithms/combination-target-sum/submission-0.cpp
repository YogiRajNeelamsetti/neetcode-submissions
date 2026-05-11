class Solution {
public:

    void combo(int idx, int n, int target, vector<int> &nums, vector<int> subset, vector<vector<int>> &res) {
        if(idx == n) {
            if(target == 0) {
                res.push_back(subset);
            }
            return;
        }

        if(nums[idx] <= target) {
            subset.push_back(nums[idx]);
            combo(idx, n, target - nums[idx], nums, subset, res);
            subset.pop_back();
            
        }
        combo(idx + 1, n, target, nums, subset, res);

        return;

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        combo(0, n, target, nums, {}, res);

        return res;
    }
};
