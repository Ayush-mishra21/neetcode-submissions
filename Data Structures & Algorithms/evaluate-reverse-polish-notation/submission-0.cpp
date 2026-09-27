class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string A : tokens) {
            if (A == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            } else if (A == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if (A == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            } else if (A == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
            else{
                st.push(stoi(A));
            }
        }
        return st.top();
    }
};
