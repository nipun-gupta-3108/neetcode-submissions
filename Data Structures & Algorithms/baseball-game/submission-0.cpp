class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(const string &op : ops) {
            if(op == "+") {
                int p1 = st.top();
                st.pop();

                int p2 = st.top();
                st.push(p1);
                st.push(p1 + p2);
            } else if(op == "D") {
                int p = st.top();
                st.push(2 * p);
            } else if(op == "C") st.pop();
            else st.push(stoi(op));
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};