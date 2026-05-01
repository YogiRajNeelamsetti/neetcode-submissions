class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int n = s.size();
        int maxFreq = 0;

        int maxLen = 0, l = 0;

        for(int r = 0; r < n; r++) {
            mpp[s[r]]++;

            maxFreq = max(maxFreq, mpp[s[r]]);

            while((r - l + 1) - maxFreq > k) {
                mpp[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};
