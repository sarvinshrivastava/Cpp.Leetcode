class Solution {
public:
    string reverseOnlyLetters(string s) {
        int j = s.size() - 1, i = 0;
        char temp;

        while (i < j) {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
                if (s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z') {
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    ++i; --j;
                }
                else --j;
            }
            else i++;
        }

        return s;
    }
};
