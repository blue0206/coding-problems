#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<vector<int>> generateMatrix(int n);

int main()
{
    while (true)
    {
        int n;
        cout << "Enter a non-zero, positive integer 'n' to generate a spiral matrix: ";
        cin >> n;
        if (n < 1)
        {
            cout << "Error: n < 1 !\n";
            exit(1);
        }

        vector<vector<int>> matrix = generateMatrix(n);
        cout << "n x n spiral matrix:\n";
        for (auto i : matrix)
        {
            for (auto j : i)
            {
                cout << j << ' ';
            }
            cout << '\n';
        }

        char prompt;
        cout << "Run again? (Y/n): ";
        cin >> prompt;
        if (prompt != 'Y' && prompt != 'y')
        {
            exit(0);
        }
    }
}

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));

    int rowStart = 0;
    int colStart = 0;
    int rowEnd = n-1;
    int colEnd = n-1;
    int num = 1;
    int total = n*n;

    while (num <= total)
    {
        //Fill start row
        for (int i=colStart; i<=colEnd; i++)
        {
            matrix[rowStart][i] = num++;
        }
        rowStart++;

        //Fill end column
        for (int i=rowStart; i<=rowEnd; i++)
        {
            matrix[i][colEnd] = num++;
        }
        colEnd--;

        //Fill end row
        for (int i=colEnd; i>=colStart; i--)
        {
            matrix[rowEnd][i] = num++;
        }
        rowEnd--;

        //Fill start column
        for (int i=rowEnd; i>=rowStart; i--)
        {
            matrix[i][colStart] = num++;
        }
        colStart++;
    }

    return matrix;
}