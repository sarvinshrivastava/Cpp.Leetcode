class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        sort(f.begin(), f.end());

        vector<string> result;

        for (const string& folder : f) {
            if (result.empty() || folder.compare(0, result.back().size(), result.back()) != 0 || folder[result.back().size()] != '/') {
                result.push_back(folder);
            }
        }

        return result;
    }
};
