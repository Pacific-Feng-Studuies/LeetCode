#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2);

    string string1;
    string string2;
};

string Solution::gcdOfStrings(string str1, string str2)
{
    if(str1+str2 != str2+str1)    // to check whether str1 and str2 has relationship of division
    {
        return "";
    }

    int common = __gcd(str1.size(), str2.size());    // find the max common division number

    return str1.substr(0, common);
}

int main()
{
    Solution solution;
    solution.string1 = "ASDASDASDASDASDASD";
    solution.string2 = "ASDASD";

    string result;
    
    result = solution.gcdOfStrings(solution.string1, solution.string2);
    cout << result << endl;

    return 0;
}