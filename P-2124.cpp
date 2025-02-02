class Solution {
public:
    bool checkString(string s) {
        bool first_b_sceen = false;
        for (auto x : s) {
            if (x == 'b')
                first_b_sceen = true;

            if (first_b_sceen && x == 'a')
                return false;
        }

        return true;
    }
};
