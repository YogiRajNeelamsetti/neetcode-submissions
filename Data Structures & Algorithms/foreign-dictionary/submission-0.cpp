class Solution {
public:

    string topo(vector<vector<int>> &adj, unordered_set<int> &s) {
        vector<int> indegree(26, 0);

        for(int i = 0; i < 26; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < 26; i++) {
            if(s.count(i) > 0 && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        string str = "";
        for(int i = 0; i < ans.size(); i++) {
            str += (ans[i] + 'a');
        }

        return str;
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        unordered_set<int> s;

        for(string str : words) {
            for(char ch : str) {
                s.insert(ch - 'a');
            }
        }

        int n = words.size();

        for(int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;
            for(int ptr = 0; ptr < len; ptr++) {
                if(s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    found = true;
                    break;
                }
            }

            if(!found && s1.size() > s2.size()) {
                return "";
            }
        }

        string ans = topo(adj, s);

        if(ans.size() != s.size()) return "";

        return ans;
    }
};
