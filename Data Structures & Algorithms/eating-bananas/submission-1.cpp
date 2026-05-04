class Solution {
public:
    long long check(vector<int> &piles, int mid) {
        long long hours = 0;
        for(int &num : piles) {
            hours += ceil(static_cast<double>(num) / mid);
            // cout<<hours<<" ";
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        // cout<<low<<" "<<high;
        int ans = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
