class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int curGrp = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[sorted[0]] = curGrp;

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(curGrp, list<int>(1, sorted[0])));

        for (int i = 1; i < nums.size(); i++) {
            if (abs(sorted[i] - sorted[i - 1]) > limit) {
                curGrp++;
            }

            numToGroup.insert(pair<int, int>(sorted[i], curGrp));

            if (groupToList.find(curGrp) == groupToList.end()) {
                groupToList[curGrp] = list<int>();
            }
            groupToList[curGrp].push_back(sorted[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};
