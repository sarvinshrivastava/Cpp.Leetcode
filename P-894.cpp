class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int n) {
        if ((n & 1) == 0)
            return {};
        if (n == 1)
            return {new TreeNode(0)};

        if (memo.count(n))
            return memo[n];

        vector<TreeNode*> res;

        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);

            for (auto l : left)
                for (auto r : right) {
                    TreeNode* rt = new TreeNode(0);
                    rt->left = l;
                    rt->right = r;
                    res.push_back(rt);
                }
        }

        memo[n] = res;
        return res;
    }
};
