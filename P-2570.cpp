class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map <int, int> map;

        for (auto& ele : nums1)
            map[ele[0]] += ele[1];
        for (auto& ele : nums2)
            map[ele[0]] += ele[1];

        vector < vector < int > > result;

        for (auto [key, val] : map)
            result.push_back({key, val});

        sort(result.begin(), result.end());

        return result;
    }
};
