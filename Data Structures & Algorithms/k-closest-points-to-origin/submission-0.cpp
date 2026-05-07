class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        priority_queue<pair<int, vector<int>>> pq;
        
        for(auto &point : points) {
            int x = point[0];
            int y = point[1];

            int dist = (x * x) + (y * y);

            pq.push({dist, {x, y}});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
