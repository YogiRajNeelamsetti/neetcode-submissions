class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int maxArea = INT_MIN;

        int l = 0, r = n - 1;

        while(l < r) {
            maxArea = max(maxArea, (r - l) * min(heights[l], heights[r]));
            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxArea;
    }
};
