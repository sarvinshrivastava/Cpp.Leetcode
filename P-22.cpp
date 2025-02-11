class Solution {
public:
    vector <string> result;

    void generate (int n, int l_cnt, int r_cnt, string st) {
        if (st.size() == 2 * n) {
            result.push_back(st);
            return ;
        }

        if (l_cnt == r_cnt) {
            st.push_back('(');
            generate(n, l_cnt + 1, r_cnt, st);
            st.pop_back();
        }
        else if (l_cnt == n) {
            st.push_back(')');
            generate(n, l_cnt, r_cnt + 1, st);
            st.pop_back();
        }
        else {
            st.push_back('(');
            generate(n, l_cnt + 1, r_cnt, st);
            st.pop_back();
            st.push_back(')');
            generate(n, l_cnt, r_cnt + 1, st);
        }

    }

    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0, "");
        return result;
    }
};
