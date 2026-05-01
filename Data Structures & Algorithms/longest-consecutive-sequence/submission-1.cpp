class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        sort(nums.begin(), nums.end());

        int maxLen = 1;
        int len = 1;
        int prev = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] - prev == 1) {
                len++;
                maxLen = max(maxLen, len);
            } else if(nums[i] - prev == 0){
                continue;
            } else {
                len = 1;
            }
            prev = nums[i];
            cout<<prev<<" ";
        }

        return maxLen;
    }
};
