class Solution {
public:
    string makeFancyString(string s) {
        // int len = s.size();
        // auto it = s.begin();
        // int i, j;

        // cout << len << "\n\n";
        // for (int i = 1; i < len - 1; ) {
        //     if (s[i-1] == s[i] && s[i] == s[i+1]) {
        //         s.erase(it + i);
        //         len = s.size();
        //         // cout << "len:" << len << " i:" << i << "\n";
        //     }
        //     else i++;
        // }

        // for (i = 0; i < len  - 1; i++) {
        //     if (s[i] == s[i + 1]) {
        //         j = i + 2;
        //         while(j < len && s[j] != s[i]) {
        //             j++;
        //         }
        //         s.erase(it + i + 2, it + j - 1);
        //         len = s.size();
        //         i = j;
        //     }
        // }

        string res;

        if (s.size() < 2)
            return s;

        for (auto c : s) {
            int len = res.size();

            if (len < 2 || !(res[len - 1] == c && res[len - 2] == c))
                res += c;
        }

        return res;
    }
};
