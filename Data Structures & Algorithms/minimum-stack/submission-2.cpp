class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if(val > mini) st.push(val);
            else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long ele = st.top();
        st.pop();
        if(ele < mini) {
            mini = 2LL * mini - ele;
        }
    }
    
    int top() {
        long long ele = st.top();
        if(mini < ele) return ele;
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};
