class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.size();

        while (len >= 0 && s != goal) {
            s.push_back(s[0]);
            s.erase(s.begin());
            len--;
        }

        return (s == goal) ? true : false;
    }
};
