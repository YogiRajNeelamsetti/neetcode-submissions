class MedianFinder {
public:
    int count;
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if(!large.empty() && num > large.top()) {
            large.push(num);
        } else {
            small.push(num);
        }

        if(large.size() > small.size()) {
            int t = large.top();
            large.pop();
            small.push(t);
        } else if(small.size() > large.size()) {
            int t = small.top();
            small.pop();
            large.push(t);
        }
        return;
    }
    
    double findMedian() {
        double median;
        if(small.size() > large.size()) {
            median = small.top();
        } else if(large.size() > small.size()) {
            median = large.top();
        } else {
            int t1 = small.top();
            int t2 = large.top();
            median = (t1 + t2) / 2.0;
        }
        return median;
    }
};
