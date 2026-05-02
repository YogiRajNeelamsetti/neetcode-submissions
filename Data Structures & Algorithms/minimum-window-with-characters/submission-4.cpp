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
        int cnt = 0;

        while(r < n) {
            if(mpp[s[r]] > 0) cnt++;
            mpp[s[r]]--;

            while(cnt == m) {
                if((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
