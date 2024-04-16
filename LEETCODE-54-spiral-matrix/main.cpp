#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    cout << "Initial Matrix:\n";
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    vector<int> spiralOrderMatrix = spiralOrder(matrix);

    cout << "Resultant spiral order matrix:\n";
    for (auto i : spiralOrderMatrix)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();
    
    int rowStart = 0;
    int colStart = 0;
    int rowEnd = row-1;
    int colEnd = col-1;

    int count = 0;
    int total = row*col;

    while (count < total)
    {
        //Traverse Start Row
        for (int i=colStart; count<total && i<=colEnd; i++)
        {
            ans.push_back(matrix[rowStart][i]);
            count++;
        }
        rowStart++;

        //Traverse End Column
        for (int i=rowStart; count<total && i<=rowEnd; i++)
        {
            ans.push_back(matrix[i][colEnd]);
            count++;
        }
        colEnd--;

        //Traverse End Row
        for (int i=colEnd; count<total && i>=colStart; i--)
        {
            ans.push_back(matrix[rowEnd][i]);
            count++;
        }
        rowEnd--;

        //Traverse First Column
        for (int i=rowEnd; count<total && i>=rowStart; i--)
        {
            ans.push_back(matrix[i][colStart]);
            count++;
        }
        colStart++;
    }

    return ans;
}