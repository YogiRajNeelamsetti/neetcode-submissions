class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;

        int n = s.size();

        int l = 0, r = 0;
        int maxLen = 0;

        while(r < n) {
            mpp[s[r]]++;

            if(r - l + 1 == mpp.size()) {
                maxLen = max(maxLen, r - l + 1);
            } else {
                while(l < r && mpp.size() != (r - l + 1)) {
                    mpp[s[l]]--;
                    if(mpp[s[l]] == 0) mpp.erase(s[l]);
                    l++;
                }
            }
            r++;
        }

        return maxLen;
    }
};
