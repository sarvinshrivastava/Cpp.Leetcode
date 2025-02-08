class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0, doubleSum = 0;

        for (auto x : nums) {
            if (x < 10)
                singleSum += x;
            else
                doubleSum += x;
        }

        return (singleSum == doubleSum) ? false : true;
    }
};
