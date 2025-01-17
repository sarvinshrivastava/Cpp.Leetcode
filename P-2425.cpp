class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a1 = 0, a2 = 0;
        int len1 = nums1.size(), len2 = nums2.size();

        if (len1 % 2 != 0)
            for (auto x : nums2)
                a2 ^= x;

        if (len2 % 2 != 0)
            for (auto x : nums1)
                a1 ^= x;

        return a1 ^ a2;
    }
};
