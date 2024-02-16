//CODING NINJAS STUDIO Problem: Replace Spaces
//https://www.codingninjas.com/studio/problems/replace-spaces_1172172?interviewProblemRedirection=true
//Given a string 'str', replace all spaces (' ') with '@40'.
//Example: "Hello World" to "Hello@40World".


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string replaceSpace1(string s); //APPROACH 1
// TC -> O(n)
// SC -> O(n)
//Create empty string and copy each character of given string using for loop.
//In case of space (' ') character, copy '@40' instead.

string replaceSpace2(string s); // APPROACH 2
// TC -> O(n)
// SC -> O(1)
//In-place manipulation.
//Count the number of spaces in given string, and allot extra space to string
//accordingly using .resize()
//Manipulate using double pointer approach.

void swap(char& ch1, char& ch2);

int main()
{
    ifstream fin;
    fin.open("./input.dat");

    string str = "";
    while (!fin.eof())
    {
        getline(fin, str);
    }

    cout << "APPROACH 1:\t" << replaceSpace1(str) << endl;
    cout << "APPROACH 2:\t" << replaceSpace2(str) << endl;

    
    return 0;
}

void swap(char& ch1, char& ch2)
{
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

string replaceSpace1(string s)
{
    string temp = "";
    for (int i=0; i<s.length(); i++)
    {
        if (s[i] != ' ')
        {
            //If i points to non-space element, copy as it is.
            temp += s[i];
        }
        else
        {
            //If i points to space, copy '@40' instead.
            temp += "@40";
        }
    }
    return temp;
}

string replaceSpace2(string s)
{
    int spaceCount = 0;
    for (int i=0; i<s.length(); i++)
    {
        if (s[i] == ' ')
        {
            spaceCount++;
        }
    }

    //Create extra space at the end of string.
    s.resize(s.length() + (spaceCount*2), ' ');

    //Set jth index on the first non-space element from the back.
    int j = s.length() - (1 + (spaceCount*2));
    //Set ith index on the last element which is extra space.
    int i = s.length() - 1;

    while (j >= 0 && i >= 0)
    {
        if (s[j] != ' ')
        {
            //When j points to non-space element, swap it with index i
            //which points to space element.
            swap(s[i--], s[j--]);
        }
        else
        {
            //When j points to space, it means the end of a word.
            //Hence, insert '@40' at index i.
            s[i--] = '0';
            s[i--] = '4';
            s[i--] = '@';
            j--;
        }
    }
    return s;
}