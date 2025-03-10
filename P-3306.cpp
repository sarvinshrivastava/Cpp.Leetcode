#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
using namespace std;

// class Solution {
// public:
//     int countOfSubstrings(string word, int k) {
//         int n = word.length(), result = 0;

//         for (int st = 0; st < n; st++) {
//             /*
//             'a' -> bit 0,
//             'e' -> bit 1,
//             'i' -> bit 2,
//             'o' -> bit 3,
//             'u' -> bit 4
//             */
//             int cCnt = 0;
//             bool fA = false, fE = false, fI = false, fO = false, fU = false;

//             for (int end = st; end < n && cCnt <= k; end++) {
//                 char c = word[end];

//                 if (c == 'a') fA = true;
//                 else if (c == 'e') fE = true;
//                 else if (c == 'i') fI = true;
//                 else if (c == 'o') fO = true;
//                 else if (c == 'u') fU = true;
//                 else cCnt++;

//                 if (cCnt > k) break;

//                 if (cCnt == k && fA && fE && fI && fO && fU)
//                     result++;
//             }
//         }

//         return result;
//     }
// };

class Solution
{
private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    long countOfSubstrings(string word, int k)
    {
        long result = 0;
        int st = 0, end = 0, cCnt = 0, nxtCntIdx = word.size();
        
        unordered_map <char, int> vCnt;
        vector <int> nxtCnt(word.size());

        for (int i = word.size() - 1; i >= 0; i--)
        {
            nxtCnt[i] = nxtCntIdx;
            if (!isVowel(word[i]))
                nxtCntIdx = i;
        }

        while (end < word.size())
        {
            char nChar = word[end];

            if (isVowel(nChar))
                vCnt[nChar]++;
            else
                cCnt++;

            while (cCnt > k)
            {
                char sChar = word[st];
                if (isVowel(sChar))
                {
                    vCnt[sChar]--;
                    if (vCnt[sChar] == 0)
                        vCnt.erase(sChar);
                }
                else
                    cCnt--;
                st++;
            }

            while (st < word.size() && vCnt.size() == 5 &&
                   cCnt == k)
            {
                char sChar = word[st];

                result += nxtCnt[end] - end;
                if (isVowel(sChar))
                {
                    vCnt[sChar]--;
                    if (vCnt[sChar] == 0)
                        vCnt.erase(sChar);
                }
                else
                    cCnt--;
                st++;
            }
            end++;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string word;
    int k;
    cin >> word >> k;

    auto st = chrono::high_resolution_clock::now();

    int result = solution.countOfSubstrings(word, k);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - st;

    cout << "Result: " << result << endl;
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}