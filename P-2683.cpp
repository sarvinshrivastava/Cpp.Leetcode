class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int a = 0;

        for (auto x : derived)
            a ^= x;

        if (a == 0)
            return true;

        return false;
    }
};
