class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> mpp;
        int l = 0, r = 0;
        int n = s.size();
        int maxLen = 0;

        while(r < n) {
            mpp[s[r]]++;

            if(r - l + 1 == mpp.size()) {
                maxLen = max(maxLen, r - l + 1);
            }

            while(l < r && (r - l + 1) != mpp.size()) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }

        return maxLen;
    }
};
