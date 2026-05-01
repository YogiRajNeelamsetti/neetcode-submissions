class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<int>> freq(n, vector<int>(26, 0));

        for(int i = 0; i < n; i++) {
            for(char ch : strs[i]) {
                freq[i][ch - 'a']++;
            }
        }

        vector<int> vis(n, 0);
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            vector<string> str;
            if(!vis[i]) str.push_back(strs[i]);
            vis[i] = 1;
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
                    vis[j] = 1;
                }
            }
            if(str.size() > 0) ans.push_back(str);
        }

        return ans;
    }
};
