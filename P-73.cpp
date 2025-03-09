#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    unordered_set<int> rows, cols;
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }

    for (auto r : rows)
        for (int i = 0; i < n; ++i)
            matrix[r][i] = 0;
    for (auto c : cols)
        for (int i = 0; i < m; ++i)
            matrix[i][c] = 0;
}

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    for (auto &row : matrix)
    {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }
    return 0;
}