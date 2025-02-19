class Solution {
public:
    unordered_map<int, int> map;
    void DFS(TreeNode* rt, int level) {
        if (rt == NULL)
            return;

        map[level] = rt->val;
        DFS(rt->left, level + 1);
        DFS(rt->right, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        DFS(root, 0);

        vector<int> res(map.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = map[i];
        return res;
    }
};
