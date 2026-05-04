class TimeMap {
public:
    map<string, vector<pair<int, string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int low = 0, high = mpp[key].size() - 1;
        string s = "";
        while(low <= high) {
            int mid = (low + high) / 2;
            if(mpp[key][mid].first <= timestamp) {
                s = mpp[key][mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return s;
    }
};
