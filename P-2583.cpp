/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue <long long> pq;

    void levelOrderTraversal(TreeNode* root) {
        if (root == nullptr) return;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int cSize = q.size();
            long long tsum = 0;

            for (int count = 0; count < cSize; count++) {
                TreeNode* current = q.front();
                q.pop();
                tsum += current->val;

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            pq.push(tsum);
        }
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        levelOrderTraversal(root);

        while (!pq.empty() && k > 1) {
            pq.pop();
            k--;
        }
        if (!pq.empty())
            return pq.top();
        return -1;
    }
};
