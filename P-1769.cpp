class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> ans(len, 0);

        int cnt = 0, op = 0;
        for (int i = 0; i < len; ++i) {
            ans[i] += op;
            cnt += (boxes[i] == '1') ? 1 : 0;
            op += cnt;
        }

        cnt = 0, op = 0;
        for (int i = len - 1; i >= 0; --i) {
            ans[i] += op;
            cnt += (boxes[i] == '1') ? 1 : 0;
            op += cnt;
        }

        return ans;
    }
};


// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         int len = boxes.size();
//         vector <int> ballLoc;

//         for (int i = 0; i < len; ++i)
//             if (boxes[i] == '1')
//                 ballLoc.push_back(i);

//         vector <int> ans(len, 0);
//         for (int i = 0; i < len; ++i)
//             for (auto x : ballLoc)
//                 ans[i] += abs(i - x);

//         return ans;
//     }
// };
