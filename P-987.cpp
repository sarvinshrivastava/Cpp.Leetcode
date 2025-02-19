class Solution {
public:
    vector<tuple<int, int, int>> nodes;

    void DFS(TreeNode* root, int hd, int level) {
        if (!root)
            return;
        nodes.push_back({hd, level, root->val});

        DFS(root->left, hd - 1, level + 1);
        DFS(root->right, hd + 1, level + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        DFS(root, 0, 0);

        sort(nodes.begin(), nodes.end(), [](const auto &a, const auto &b) {
            if (get<0>(a) == get<0>(b)) {
                if (get<1>(a) == get<1>(b))
                    return get<2>(a) < get<2>(b);
                return get<1>(a) < get<1>(b);
            }
            return get<0>(a) < get<0>(b);
        });

        vector<vector<int>> result;
        int prev_hd = INT_MIN;
        for (auto &entry : nodes) {
            int hd, level, val;
            tie(hd, level, val) = entry;
            if (hd != prev_hd) {
                result.push_back({});
                prev_hd = hd;
            }
            result.back().push_back(val);
        }

        return result;
    }
};
