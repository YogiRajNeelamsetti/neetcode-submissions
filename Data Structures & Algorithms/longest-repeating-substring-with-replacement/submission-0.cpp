class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int n = s.size();
        int maxFreq = 0;

        int l = 0, r = 0;
        int maxLen = 0;
        while(r < n) {
            mpp[s[r]]++;
            if(mpp[s[r]] > maxFreq) {
                maxFreq = mpp[s[r]];
            }
            if((r - l + 1) - maxFreq > k) {
                mpp[s[l]]--;
                maxFreq = 0;
                l++;
            }
            
            if((r - l + 1) - maxFreq <= k) {
                if((r - l + 1) > maxLen) {
                    maxLen = (r - l + 1);
                }
            }
            r++;
        }
        return maxLen;
    }
};
