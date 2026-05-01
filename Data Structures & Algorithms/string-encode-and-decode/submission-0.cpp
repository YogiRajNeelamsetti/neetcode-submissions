class Solution {
public:

    string encode(vector<string>& strs) {
        vector<int> sizes;

        string str = "";
        for(string &s : strs) {
            int sz = s.size();
            sizes.push_back(sz);

            str += to_string(sz) + ',';
        }

        str += '#';

        for(string &s : strs) {
            str += s;
        }

        return str;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};

        vector<int> sizes;
        vector<string> res;

        int i = 0;

        while(s[i] != '#') {
            string curr = "";
            while(s[i] != ',') {
                curr += s[i];
                i++;
            }

            sizes.push_back(stoi(curr));
            i++;
        }
        i++;

        for(int &sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;
    }
};
