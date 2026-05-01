class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 1;

        for(int num : s) {
            if(s.find(num - 1) == s.end()) {
                int len = 1;
                while(s.find(num + len) != s.end()) {
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }


        return maxLen;
    }
};
