#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build a binary tree from a vector of integers
TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (nodes[i] != "null")
        {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to parse input string into a vector of strings
vector<string> parseInput(const string &input)
{
    vector<string> result;
    stringstream ss(input.substr(1, input.size() - 2)); // Remove '[' and ']'
    string item;

    while (getline(ss, item, ','))
    {
        result.push_back(item);
    }

    return result;
}

pair<TreeNode *, int> dfs(TreeNode *root)
{
    if (!root)
    {
        return {nullptr, 0};
    }

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    if (left.second > right.second)
        return {left.first, left.second + 1};

    if (left.second < right.second)
        return {right.first, right.second + 1};

    return {root, left.second + 1};
}

TreeNode *lcaDeepestLeaves(TreeNode *root)
{
    return dfs(root).first;
}

int main()
{
    string input;
    cin >> input;
    vector<string> nodes = parseInput(input);

    TreeNode *root = buildTree(nodes);

    cout << lcaDeepestLeaves(root)->val << endl;

    return 0;
}