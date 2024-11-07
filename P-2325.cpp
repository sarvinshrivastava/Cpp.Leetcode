class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> us;
        int i = 0;

        for (auto x : key)
            if (x != ' ' && us.find(x) == us.end()) {
                us[x] = 'a' + i;
                i++;
            }

        string st;
        for (auto x : message)
            if (x != ' ') st += us[x];
            else st += ' ';

        return st;
    }
};
