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
 // Solved all
 class Solution {
 public:
 
     int ppFun(TreeNode* root, int ll, vector<int>&node_ll, vector<int>&node_ht, vector<pair<int, int>>&maxs) {
         if (!root) return 0;

         int h = max(ppFun(root -> left, ll + 1, node_ll, node_ht, maxs), ppFun(root -> right, ll + 1, node_ll, node_ht, maxs)) + 1;

         node_ll[root -> val] = ll;
         node_ht[root -> val] = h;

         if (h > maxs[ll].first) {
             maxs[ll].second = maxs[ll].first;
             maxs[ll].first = h;
         }
         else if (h > maxs[ll].second) {
             maxs[ll].second = h;
         }

         return h;
     }

     vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
         int n = 100001;

         vector <int> node_ll(n, -1);
         vector <int> node_ht(n, 0);
         vector <pair<int, int>> maxs(n, {0, 0});
         ppFun(root, 0, node_ll, node_ht, maxs);

         vector <int> a;
         for (auto x : queries) {
             int l = node_ll[x], h = node_ht[x];

             int m = (h == maxs[l].first) ? maxs[l].second : maxs[l].first;

             a.push_back(m + l - 1);
         }

         return a;
     }
 };

// Could only solve 34 out of 40 testcases with solution
/*
class Solution {
public:
    bool flag = false;
    vector<int> h;
    TreeNode* tmp,* r;

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        return max(lHeight, rHeight) + 1;
    }

    void find(TreeNode* root, int q) {
        if (root == NULL || flag == true) return;
        // cout << root -> val << endl;
        if (root -> left != NULL && q == root -> left -> val) {
            tmp = root -> left;
            root -> left = NULL;
            // cout << "left" << endl;
            h.push_back(height(r) - 1);
            root -> left = tmp;
            flag = true;
            return;
        }
        if (root -> right != NULL && q == root -> right -> val) {
            tmp = root -> right;
            root -> right = NULL;
            // cout << "right" << endl;
            h.push_back(height(r) - 1);
            root -> right = tmp;
            flag = true;
            return;
        }

        if (root -> left != NULL)
            find(root -> left, q);
        if (root -> right != NULL)
            find(root -> right, q);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        r = root;
        for (int i = 0; i < q.size(); i++) {
            find(root, q[i]);
            flag = false;
        }

        return h;
    }
};*/
