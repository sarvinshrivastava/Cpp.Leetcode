class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.size();
        vector<int> diff(len + 1, 0);

        for (const auto& shift : shifts) {
            int st = shift[0], e = shift[1], dir = shift[2];
            diff[st] += (dir == 1) ? 1 : -1;
            diff[e + 1] += (dir == 1) ? -1 : 1;
        }

        int cShift = 0;
        for (int i = 0; i < len; ++i) {
            cShift += diff[i];
            int ch = s[i] - 'a';
            s[i] = 'a' + (ch + (cShift % 26) + 26) % 26;
        }

        return s;
    }
};
