class Solution {
public:
    long long minimumSteps(string s) {
        long long mc = 0, pc = 0, cc = 0, oc = 1;
        int i, j;
        cout << "size: " << s.size() << endl;

        for(i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                cc++;
            }
            else {
                for (j = i - 1; j >= 0; j--) {
                    if (s[j] == '1') {
                        oc++;
                    }
                    else {
                        break;
                    }
                }
                mc = mc + cc * oc;
                // mc += pc * oc + cc;
                // pc += cc;
                cout << "i:" << i << " cc:" << cc << " oc:" << oc << " mc:" << mc << endl;
                // cc = 0;
                oc = 1;
                i = j + 1;
            }

        }

        return mc;
    }
};
