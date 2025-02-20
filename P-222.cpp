class Solution {
public:
    pair<bool, int> isPerfect(TreeNode* rt) {
        if (rt == NULL)
            return {true, 0};

        TreeNode* child = rt;
        int leftCnt = 0, rightCnt = 0;

        while (child != NULL) {
            child = child -> left;
            leftCnt++;
        }

        child = rt;

        while (child != NULL) {
            child = child -> right;
            rightCnt++;
        }

        return {(leftCnt == rightCnt), (1 << leftCnt) - 1};
    }

    int countNodes(TreeNode* rt) {
        if (rt == NULL)
            return 0;

        int cnt = 1;

        // Left Sub Tree
        auto [flagL, heightL] = isPerfect(rt -> left);
        if (flagL)
            cnt += heightL;
        else
            cnt += countNodes(rt -> left);

        // Right Sub Tree
        auto [flagR, heightR] = isPerfect(rt -> right);
        if (flagR)
            cnt += heightR;
        else
            cnt += countNodes(rt -> right);

        return cnt;
    }
};
