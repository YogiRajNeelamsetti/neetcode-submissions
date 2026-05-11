class Solution {
public:
    void permutations(int n, vector<int> arr, vector<int> &nums, vector<int> freq, vector<vector<int>> &res) {
        if(arr.size() == n) {
            res.push_back(arr);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!freq[i]) {
                arr.push_back(nums[i]);
                freq[i] = 1;
                permutations(n, arr, nums, freq, res);
                freq[i] = 0;
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0);

        vector<vector<int>> res;
        permutations(n, {}, nums, freq, res);

        return res;
    }
};
