#include <iostream>
#include <vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    // vector<vector<int>> matrix = {{1,2},{2,2}};

    cout << "Matrix:\n";
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    if (isToeplitzMatrix(matrix))
    {
        cout << "TRUE. The given matrix is a toeplitz matrix!\n";
    }
    else
    {
        cout << "FALSE. The given matrix is NOT a toeplitz matrix!\n";
    }

    return 0;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    int rowEnd = matrix.size()-1;
    int colEnd = matrix[0].size()-1;

    for (int i=0; i<rowEnd; i++)
    {
        for (int j=0; j<colEnd; j++)
        {
            if (matrix[i][j] != matrix[i+1][j+1])
            {
                return false;
            }
        }
    }
    return true;
}