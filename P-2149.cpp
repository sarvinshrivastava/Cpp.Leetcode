class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int posIdx = 0, negIdx = 1;

        for (int num : nums) {
            if (num > 0) {
                result[posIdx] = num;
                posIdx += 2;
            } else {
                result[negIdx] = num;
                negIdx += 2;
            }
        }
        return result;
    }
};
