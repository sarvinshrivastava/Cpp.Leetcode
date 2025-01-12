class Solution {
public:
    bool canBeValid(string s, string locked) {
        int len = s.size();
        if (len % 2 == 1)
            return false;

        stack<int> opnb, unl;

        for (int i = 0; i < len; i++) {
            if (locked[i] == '0') {
                unl.push(i);
            } else if (s[i] == '(') {
                opnb.push(i);
            } else if (s[i] == ')') {
                if (!opnb.empty()) {
                    opnb.pop();
                } else if (!unl.empty()) {
                    unl.pop();
                } else {
                    return false;
                }
            }
        }

        while (!opnb.empty() && !unl.empty() &&
               opnb.top() < unl.top()) {
            opnb.pop();
            unl.pop();
        }

        if (!opnb.empty()) {
            return false;
        }

        return true;
    }
};
