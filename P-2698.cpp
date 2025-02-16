class Solution {
public:
    void reccurse(string& s, int& key, bool& flag, int sum, int idx) {
        if (idx >= s.size()) {
            if (sum == key)
                flag = true;

            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            int n = stoi(s.substr(idx, i - idx + 1));

            if (key >= n)
                reccurse(s, key, flag, sum + n, i + 1);
        }
    }

    bool validate(int key) {
        string num = to_string(key * key);
        bool flag = false;
        reccurse(num, key, flag, 0, 0);
        return flag;
    }

    int punishmentNumber(int n) {
        int sum = 1;

        for (int i = 2; i <= n; ++i)
            if (validate(i))
                sum += i * i;

        return sum;
    }
};
