class Solution {
public:
    string toString(vector<vector<int>>& board) {
        string st;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                st.push_back(board[i][j] + '0');

        return st;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        vector<vector<int>> moves = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };

        string start = toString(board);
        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr.first == target) return curr.second;

            int zeroIndex = curr.first.find('0');
            for (int neighbor : moves[zeroIndex]) {
                string newState = curr.first;
                swap(newState[zeroIndex], newState[neighbor]);
                if (visited.find(newState) == visited.end()) {
                    visited.insert(newState);
                    q.push({newState, curr.second + 1});
                }
            }
        }
        return -1;
    }

};
