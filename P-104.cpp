class Solution {
public:
    int DFS (TreeNode* n) {
        if (n == NULL)
            return 0;

        if (n -> left == NULL && n -> right == NULL) {
            return 1;
        }

        return max(DFS (n -> left), DFS (n -> right)) + 1;
    }

    int maxDepth(TreeNode* root) {
        return DFS (root);
    }
};
