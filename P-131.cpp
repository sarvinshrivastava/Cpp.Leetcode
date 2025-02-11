class Solution {
private:
    bool isPalindrome(const string& st) {
        int i = 0, j = st.size() - 1;
        while (i < j) {
            if (st[i] != st[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    void backtrack(const string& s, int start, vector<string>& path,
                   vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            string substr = s.substr(start, end - start + 1);
            if (isPalindrome(substr)) {
                path.push_back(substr);
                backtrack(s, end + 1, path, result);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;

        backtrack(s, 0, path, result);

        return result;
    }
};
