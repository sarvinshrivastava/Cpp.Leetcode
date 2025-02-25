class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < n; ++i) {
            string s = equations[i][0], d = equations[i][1];

            graph[s].push_back({d, values[i]});
            graph[d].push_back({s, 1.0 / values[i]});
        }

        vector<double> res;
        for (auto& q : queries) {
            string src = q[0], dest = q[1];

            if (!graph.count(src) || !graph.count(dest)) {
                res.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited{src};
            queue<pair<string, double>> qq({{src, 1.0}});
            bool flag = false;

            while (!qq.empty()) {
                auto front = qq.front(); qq.pop();

                if (front.first == dest) {
                    res.push_back(front.second);
                    flag = true;
                    break;
                }

                for (auto& nei : graph[front.first]) {
                    if (!visited.count(nei.first)) {
                        visited.insert(nei.first);
                        qq.push({nei.first, front.second * nei.second});
                    }
                }
            }

            if (!flag)  res.push_back(-1.0);
        }

        return res;
    }
};
