class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr(position.size());

        for(int i = 0; i < speed.size(); i++) {
            arr[i] = {position[i], speed[i]};
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        stack<float> st;

        for(int i = 0; i < arr.size(); i++) {
            int pos = arr[i].first;
            int sp = arr[i].second;
            cout<<pos<<" "<<sp<<endl;
            float time = (target - pos) / (float)sp;

            if(st.empty()) st.push(time);
            if(!st.empty() && time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};
