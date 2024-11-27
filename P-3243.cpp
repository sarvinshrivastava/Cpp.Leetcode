class Solution {
public:
    int minDis = INT_MAX;

    void findMinPath(unordered_map<int, vector<int>> cons, int end, int curr,
                     int currDisTrav) {

        if (curr == end) {
            minDis = (currDisTrav - 1 < minDis) ? currDisTrav - 1 : minDis;
            return;
        }

        for (auto x : cons[curr]) {
            findMinPath(cons, end, x, currDisTrav + 1);
        }
    }

    void findMinPathBFS(unordered_map<int, vector<int>>& cons, int start, int end) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        unordered_set<int> visited;

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == end) {
                minDis = min(minDis, dist - 1);
                continue;
            }

            for (int neighbor : cons[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, dist + 1});
                }
            }
        }
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> cons;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            cons[i].push_back(i + 1);
        }

        for (auto q : queries) {
            cons[q[0]].push_back(q[1]);

            // findMinPath(cons, n, 0, 0);
            findMinPathBFS(cons, 0, n);

            ans.push_back(minDis);
            minDis = INT_MAX;
        }

        return ans;
    }
};
