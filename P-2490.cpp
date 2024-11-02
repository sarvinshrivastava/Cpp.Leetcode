class Solution {
public:
    bool isCircularSentence(string sentence) {
        int slen = sentence.size(), vlen;
        vector <string> vst;
        string temp;

        for (int i = 0; i < slen; i++) {
            if (sentence[i] == ' ') {
                vst.push_back(temp);
                temp.clear();
            }
            else {
                temp += sentence[i];
            }
        }
        vst.push_back(temp);

        vlen = vst.size();

        if (vst[0][0] != vst[vlen - 1][vst[vlen - 1].size() - 1])
            return false;

        for (int i = 0; i < vlen - 1; i++)
            if (vst[i + 1][0] != vst[i][vst[i].size() - 1])
                return false;

        return true;
    }
};
