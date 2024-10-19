class Solution {
public:
    string randi (string s) {
        string st;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                st += '0';
            }
            else {
                st += '1';
            }
        }
        // cout << "st:" << st << endl;
        return st;
    }

    string genString (int n) {
        if (n == 1) {
            return "0";
        }
        else {
            string a = genString(n - 1);
            // cout << "a:" << a << endl;
            return a + '1' + randi(a);
        }
    }


    char findKthBit(int n, int k) {
        string st = genString(n);
        // cout << st;
        return st[k - 1];
    }
};
