#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void calculateDifference(vector<vector<int>>& matrix, 
                        int high, int row, int col, int& maxDifference);

int main()
{
    // vector<vector<int>> matrix = {{1,2,-1,-4,-20},
    //                               {-8,-3,4,2,1},
    //                               {3,8,6,1,3},
    //                               {-4,-1,1,7,-6},
    //                               {0,-4,10,-5,1}};

    vector<vector<int>> matrix = {{7,3,-10,5},
                                  {9,6,2,11},
                                  {10,9,6,14},
                                  {17,5,15,8}};

    cout << "Matrix:\n";
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << "    ";
        }
        cout << "\n";
    }
    cout << endl;

    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    int rowG = rowSize-1;
    int colG = colSize-1;

    int high = INT_MIN;
    int rowIndex = 0;
    int colIndex = 0;

    int maxDifference = 0;

    while (rowG > 0)
    {
        high = matrix[rowG][colG];
        rowIndex = rowG;
        colIndex = colG;

        calculateDifference(matrix, high, rowIndex, colIndex, maxDifference);

        colG--;

        if (colG == 0)
        {
            colG = colSize-1;
            rowG--;
        }
    }

    cout << "MAX DIFFERENCE IS: " << maxDifference << endl;

    return 0;
}

void calculateDifference(vector<vector<int>>& matrix, 
                        int high, int row, int col, int& maxDifference)
{
    int low = INT_MAX;
    int difference = 0;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            low = min(matrix[i][j], low);
        }
    }

    difference = high - low;
    
    if (maxDifference < difference)
    {
        maxDifference = difference;
    }
}