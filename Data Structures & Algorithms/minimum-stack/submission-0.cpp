class MinStack {
public:
    map<int, int>mp;
    stack<int>st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        mp[st.top()]--;
        if(mp[st.top()] == 0)mp.erase(st.top());
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto a = mp.begin();
        return (*a).first;
    }
};
