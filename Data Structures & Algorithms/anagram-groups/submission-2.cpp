class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;
            for (int x : v) {
                // combine hashes (31 is a common multiplier)
                h ^= hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<int>> freq(n, vector<int>(26, 0));

        for(int i = 0; i < n; i++) {
            for(char ch : strs[i]) {
                freq[i][ch - 'a']++;
            }
        }

        vector<vector<string>> res;
        vector<bool> vis(n);

        for(int i = 0; i < n; i++) {
            vector<string> str;
            if(!vis[i]) str.push_back(strs[i]);
            vis[i] = true;

            for(int j = i + 1; j < n; j++) {
                bool flag = true;

                for(int k = 0; k < 26; k++) {
                    if(freq[j][k] != freq[i][k]) {
                        flag = false;
                        break;
                    }
                }

                if(flag && !vis[j]) {
                    str.push_back(strs[j]);
                    vis[j] = true;
                }
            }
            if(str.size() > 0) res.push_back(str);
        }

        return res;
    }
};
