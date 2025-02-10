class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (auto ch : s) {
            if (ch >= '0' && ch <= '9' && !st.empty())
                st.pop();
            else
            st.push(ch);
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
