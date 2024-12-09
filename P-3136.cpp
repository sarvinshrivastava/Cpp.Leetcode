class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool v = false, c = v;

        for (auto ch : word) {
            if (ch >= '!' && ch <= '/' || ch >= ':' && ch <= '@' || ch >= '[' && ch <= '`' || ch >= '{' && ch <= '~') return false;
            if (ch >= '0' && ch <= '9') continue;
            else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') v = true;
            else c = true;
        }

        return v && c;
    }
};
