class Solution {
public:
    unordered_map <int, int> map;
    TreeNode* reccurse(vector<int>& pre, int i1, int j1, int i2, int j2) {
        /*
        left
        pre: i1 + 1 -> i1 + k - i2
        in: i2 -> k - 1
        right
        pre: i1 + k - i2 + 1 -> j1
        in: k + 1 -> j2
        */

        if (i1 > j1)
            return NULL;

        TreeNode* root = new TreeNode(pre[i1]);
        int k = map[pre[i1]];

        // Left
        root -> left = reccurse(pre, i1 + 1, i1 + k - i2, i2, k - 1);
        // Right
        root -> right = reccurse(pre, i1 + k - i2 + 1, j1, k + 1, j2);
        return root;
    }


    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for (int i = 0; i < in.size(); ++i)
            map[in[i]] = i;

        return reccurse(pre, 0, pre.size() - 1, 0, in.size() - 1);
    }
};
