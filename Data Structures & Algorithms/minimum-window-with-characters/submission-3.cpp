class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size(), m = t.size();
        int minLen = INT_MAX;

        unordered_map<char, int> mpp, window;

        for(char &ch : t) {
            mpp[ch]++;
        }
        
        int l = 0, r = 0;
        int start = 0;
        int need = mpp.size(), have = 0;

        while(r < n) {
            window[s[r]]++;

            if(mpp.count(s[r]) && window[s[r]] == mpp[s[r]]) have++;

            while(have == need) {
                if((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if(mpp[s[l]] > 0 && window[s[l]] < mpp[s[l]]) have--;
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
