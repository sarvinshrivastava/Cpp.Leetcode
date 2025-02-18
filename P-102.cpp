class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> level;

        q.push(root); q.push(NULL);

        while (!q.empty()) {
            auto temp = q.front(); q.pop();

            if (temp == NULL) {
                res.push_back(level);
                level.clear();

                if (!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
                level.push_back(temp -> val);

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return res;
    }
};
