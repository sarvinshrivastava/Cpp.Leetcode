class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, queue<int>> m;
        int len = groupSizes.size();

        for (int i = 0; i < len; ++i) {
            m[groupSizes[i]].push(i);
        }

        vector<vector<int>> ans;
        for (auto& [size, q] : m) {
            while (!q.empty()) {
                vector<int> group;
                for (int i = 0; i < size; ++i) {
                    group.push_back(q.front());
                    q.pop();
                }
                ans.push_back(group);
            }
        }

        return ans;
    }
};
