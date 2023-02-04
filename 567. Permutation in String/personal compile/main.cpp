#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2);

    string s1;
    string s2;
};

bool Solution::checkInclusion(string s1, string s2)
{
    if(s2.size() < s1.size())   return false;

    sort(s1.begin(), s1.end());

    for(int i = 0 ; i <= s2.size() - s1.size() ; i++)
    {
        size_t found = s1.find(s2[i]);
        
        if(found == string::npos)   continue;
        else
        {
            string s2_tmp = s2.substr(i, s1.size());
            sort(s2_tmp.begin(), s2_tmp.end());

            if(s1 == s2_tmp)    return true;
        }
    }

    return false;
}

int main()
{
    Solution solution;
    solution.s1 = "ab";
    solution.s2 = "a";

    string result;
    result = (solution.checkInclusion(solution.s1, solution.s2)) ? "True" : "False";

    cout << result << endl;

    return 0;
}