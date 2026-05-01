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
        unordered_map<vector<int>, vector<string>, VectorHash> mpp;

        for(int i = 0; i < n; i++) {
            for(char ch : strs[i]) {
                freq[i][ch - 'a']++;
            }

            mpp[freq[i]].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for(auto p : mpp) {
            vector<string> str;
            for(auto s : p.second) {
                str.push_back(s);
            }
            res.push_back(str);
        }

        // vector<int> vis(n, 0);
        // vector<vector<string>> ans;

        // for(int i = 0; i < n; i++) {
        //     vector<string> str;
        //     if(!vis[i]) str.push_back(strs[i]);
        //     vis[i] = 1;
        //     for(int j = i + 1; j < n; j++) {
        //         bool flag = true;
                
        //         for(int k = 0; k < 26; k++) {
        //             if(freq[j][k] != freq[i][k]) {
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if(flag && !vis[j]) {
        //             str.push_back(strs[j]);
        //             vis[j] = 1;
        //         }
        //     }
        //     if(str.size() > 0) ans.push_back(str);
        // }



        return res;
    }
};
