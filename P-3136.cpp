class Solution {
public:
    string compressedString(string word) {
        char cur = word[0];
        int len = word.size(), freq = 1;
        string res;

        for (int i = 1; i < len; i++) {
            if (word[i] != cur) {
                res += to_string(freq) + string(1, cur);
                cur = word[i];
                freq = 1;
            }
            else {
                if (freq == 9) {
                    res += "9" + string(1, cur);
                    freq = 1;
                }
                else freq++;
            }
        }

        if (freq > 9) {
            res += "9" + string(1, cur) + to_string(freq - 9) + string(1, cur);
        }
        else
            res += to_string(freq) + string(1, cur);

        return res;
    }
};
