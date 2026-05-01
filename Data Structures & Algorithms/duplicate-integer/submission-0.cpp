class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int ele : nums) {
            if(mpp.find(ele) != mpp.end()) {
                return true;
            }
            mpp[ele]++;
        }

        return false;
    }
};