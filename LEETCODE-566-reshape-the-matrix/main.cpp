#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& matrix, int r, int c);

int main() 
{
    vector<vector<int>> matrix = {{1,2},{3,4}};
    cout << "Initial Matrix:\n";
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    vector<vector<int>> reshapedMatrix = matrixReshape(matrix, 1, 4);
    cout << "Final Matrix (If reshape possible):\n";
    for (auto i : reshapedMatrix)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}

vector<vector<int>> matrixReshape(vector<vector<int>>& matrix, int r, int c)
{
    int row = matrix.size();
    int col = matrix[0].size();

    if (row*col != r*c)
    {
        return matrix;
    }

    vector<vector<int>> reshape(r, vector<int>(c));
    int rowIndex = 0;
    int colIndex = 0;

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            reshape[rowIndex][colIndex++] = matrix[i][j];
            if (colIndex == c)
            {
                colIndex = 0;
                rowIndex++;
            }
        }
    }
    return reshape;
}