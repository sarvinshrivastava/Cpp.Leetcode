/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
    Rules:-
        * rt -> left -> val = 2 * rt -> val + 1
        * rt -> right -> val = 2 * rt -> val + 2
*/

class FindElements {
public:
    TreeNode* temp;
    void reccurse(TreeNode* rt) {
        // if (rt == NULL)
        //     return;

        if (rt->left != NULL) {
            rt->left->val = 2 * rt->val + 1;
            reccurse(rt->left);
        }
        if (rt->right != NULL) {
            rt->right->val = 2 * rt->val + 2;
            reccurse(rt->right);
        }
    }

    FindElements(TreeNode* root) {
        temp = root;
        root->val = 0;
        reccurse(root);
    }

    bool findVal(int key, TreeNode* ptr) {
        if (ptr == NULL)
            return false;

        if (ptr->val == key)
            return true;

        return findVal(key, ptr->left) || findVal(key, ptr->right);
    }

    bool find(int target) {
        return findVal(target, temp);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
