class Solution {
public:
    char increment(char a) {
        a = a + 1;
        return (a == '{') ? 'a' : a;
    }

    bool canMakeSubsequence(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size(), j = 0, l = 0;

        for (int i = 0; i < len2; ++i)
            for (; j < len1; ++j)
                if (str2[i] == str1[j] || str2[i] == increment(str1[j])) {
                    ++j;
                    ++l;
                    break;
                }

        return (l == len2) ? true : false;
    }
};
