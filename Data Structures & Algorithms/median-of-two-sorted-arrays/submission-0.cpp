class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1, B = nums2;
        int total = nums1.size() + nums2.size();
        int half = total / 2;

        if(A.size() > B.size()) {
            A = nums2, B = nums1;
        }

        int l = 0, r = A.size();

        while(true) {
            int i = (l + r) / 2;
            int j = half - i;

            double ALeft = (i > 0) ? A[i - 1] : INT_MIN;
            double ARight = (i < A.size()) ? A[i] : INT_MAX;
            double BLeft = (j > 0) ? B[j - 1] : INT_MIN;
            double BRight = (j < B.size()) ? B[j] : INT_MAX;

            if(ALeft <= BRight && BLeft <= ARight) {
                if(total % 2 == 1) {
                    return min(ARight, BRight);
                }
                return (max(ALeft, BLeft) + min(ARight, BRight)) / 2;
            } else if(ALeft > BRight) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
    }
};
