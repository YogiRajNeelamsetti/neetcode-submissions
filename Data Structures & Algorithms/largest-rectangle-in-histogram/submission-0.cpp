class Solution {
public:
    vector<int> leftSmall(int n, vector<int> &heights) {
        stack<int> st;
        vector<int> res(n, -1);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(!st.empty()) res[i] = st.top();

            st.push(i);
        }

        return res;
    }
    vector<int> rightSmall(int n, vector<int> &heights) {
        stack<int> st;
        vector<int> res(n, n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(!st.empty()) res[i] = st.top();

            st.push(i);
        }

        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left, right;
        int n = heights.size();

        left = leftSmall(n, heights);
        right = rightSmall(n, heights);

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            left[i] += 1;
            right[i] -= 1;
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
        }

        return maxArea;
    }
};
