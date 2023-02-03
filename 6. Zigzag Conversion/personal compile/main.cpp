#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows); 

    string s;
    int numRows;
};

string Solution::convert(string s, int numRows)
{
    vector<string> tmp(numRows);    // to create a "numRows" columns empty vector
    int row = -1;
    int num = -1;

    while(num != s.size()-1)
    {
        if(numRows == 1)
        {
            return s;   // just return
        }
        else
        {
            if(row < numRows-1)
            {
                num++;
                row++;
                tmp[row].push_back(s[num]);     //string.push_back(char)
            }
            else if (row == numRows-1)
            {
                for(int i = 0 ; i < numRows-1 ; i++)
                {
                    if(num == s.size()-1)   break;      // not to out of range

                    num++;
                    row--;
                    tmp[row].push_back(s[num]);  
                }
            }
        }
    }

    string sol;

    for(auto &p : tmp)
    {
        sol+=p;
    }

    return sol;
}

int main()
{
    Solution solution;
    solution.s = "PAYP";
    solution.numRows = 3;

    string sol;

    sol = solution.convert(solution.s, solution.numRows);

    cout << "The solution equals to " << "\"" << sol << "\"" << endl;

}