class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(s == "+") {
                    st.push(second + first);
                } else if(s == "-") {
                    st.push(second - first);
                } else if(s == "*") {
                    st.push(second * first);
                } else if(s == "/") {
                    st.push(second / first);
                }
            } else {
                st.push(stoi(s));   
            }

        }
        return st.top();

    }
};
