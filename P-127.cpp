class Solution {
public:
    bool isAlike(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                cnt++;

        return cnt == 1;
    }

    int findShortestPath(vector<vector<int>>& adjList, int src, int dest) {
        vector<bool> isVisited(adjList.size(), false);
        queue<pair<int, int>> q; // pair of (node, distance)
        q.push({src, 1});
        isVisited[src] = true;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (node == dest) {
                return dist;
            }

            for (int neighbor : adjList[node]) {
                if (!isVisited[neighbor]) {
                    q.push({neighbor, dist + 1});
                    isVisited[neighbor] = true;
                }
            }
        }

        return 0; // If no path is found
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Checking the presence of begin and end words
        bool bFlag = false, eFlag = false;
        int bIdx = -1, eIdx = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) {
                bIdx = i;
                bFlag = true;
            }
            if (wordList[i] == endWord) {
                eIdx = i;
                eFlag = true;
            }
        }

        if (!eFlag)
            return 0;
        if (!bFlag) {
            wordList.push_back(beginWord);
            bIdx = wordList.size() - 1;
        }

        // Creating Adj List
        vector<vector<int>> adjList(wordList.size());
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (isAlike(wordList[i], wordList[j])) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Searching Shortest Path
        return findShortestPath(adjList, bIdx, eIdx);
    }
};
