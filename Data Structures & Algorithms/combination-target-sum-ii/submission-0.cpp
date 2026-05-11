class Solution {
public:
    void combo(int idx, int n, int target, vector<int> arr, vector<int> &nums, vector<vector<int>> &res) {
        if(target == 0) {
            res.push_back(arr);
            return;
        }

        for(int i = idx; i < n; i++) {
            if(i > idx && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;
            arr.push_back(nums[i]);
            combo(i + 1, n, target - nums[i], arr, nums, res);
            arr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        combo(0, n, target, {}, candidates, res);

        return res;
    }
};
