class Solution {
public:
    vector<string> res;
    void DFS (TreeNode* n, string st) {
        if (n == NULL)
            return;

        if (n -> left == NULL && n -> right == NULL) {
            res.push_back(st + to_string(n -> val));
            return ;
        }

        DFS (n -> left, st + to_string(n -> val) + "->");
        DFS (n -> right,st + to_string(n -> val) + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        DFS(root, "");

        return res;
    }
};
