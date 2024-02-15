//QUESTION:
//LeetCode Problem 186: Reverse Words in String II
//Given an array of char, reverse the order of words.
//Example: "Hello Blue" to "Blue Hello".
//A word is defined as a sequence of non-space characters.
//The code must solve the problem in-place, without allocating extra space.

//SOLUTION:
//Consider ->  'h', 'e', 'l', 'l', 'o', ' ', 'b', 'l', 'u', 'e'     (hello blue)
//Step 1: Reverse each word -> 
//  'o', 'l', 'l', 'e', 'h', ' ', 'e', 'u', 'l', 'b'    (olleh eulb)
//Step 2: Reverse the array ->
//  'b', 'l', 'u', 'e', ' ', 'h', 'e', 'l', 'l', 'o'    (blue hello)

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

void swap(char& ch1, char& ch2);
//swap char values.
void reverse(vector<char>& ch, int start, int end);
//reverse array within given index start and end.

int main()
{
    vector<char> ch;

    ifstream fin;
    fin.open("./input.dat");

    char temp;
    fin.get(temp);
    do
    {
        ch.push_back(temp);
        fin.get(temp);
    }
    while (temp != '\n');

    int start = 0;
    int end = 0;

    while (start < ch.size())
    {
        while ((!isspace(ch[end])) && end < ch.size())
        {
            end++;
        }
        //Reverse each word before and after space.
        reverse(ch, start, end-1);
        end++;
        start = end;
    }

    //Reverse the complete array after reversing the words.
    reverse(ch, 0, ch.size()-1);

    for (auto i:ch)
    {
        cout << i;
    }
    cout << endl;

    return 0;
}

void swap(char& ch1, char& ch2)
{
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

void reverse(vector<char>& ch, int start, int end)
{
    while (start <= end)
    {
        swap(ch[start++], ch[end--]);
    }
}