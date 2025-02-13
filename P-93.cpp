class Solution {
public:
    vector<string> ipAddress;

    bool isValid(string s) {
        if (s.empty() || (s[0] == '0' && s.size() > 1))
            return false;
        if (stoi(s) > 255)
            return false;
        return true;
    }

    void reccurse(string& s, string op, int idx, int sepCnt) {
        if (idx >= s.size() && sepCnt == 4) {
            ipAddress.push_back(op);
            return;
        }

        for (int i = idx + 1; i <= idx + 3 && i <= s.size(); ++i) {
            string sub = s.substr(idx, i - idx);

            if (isValid(sub)) {
                reccurse(s, op + (op.empty() ? "" : ".") + sub, i, sepCnt + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ipAddress.clear();
        reccurse(s, "", 0, 0);
        return ipAddress;
    }
};
