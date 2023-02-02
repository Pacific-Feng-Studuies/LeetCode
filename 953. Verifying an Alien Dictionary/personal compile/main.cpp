#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order);

    vector<string> words;
    string order;
};

bool compare(string s1, string s2, map<char, int> orderMap)
{
    
    string s1_tmp;  // longer string
    string s2_tmp;  // shorter string 
    int length1 = s1.size();
    int length2 = s2.size();

    if(length1 != length2)
    {
        s1_tmp = (length1 > length2)? s1 : s2;
        s2_tmp = (length1 < length2)? s1 : s2;

        for(int i = 0 ; i < s1.size() ; i++)
        {
            if(i != s2_tmp.size())
            {
                if(orderMap[s1[i]] < orderMap[s2[i]])           return true;    // satisfy the order
                else if(orderMap[s1[i]] > orderMap[s2[i]])      return false;   // not satisfy the order
            }
            else
            {
                return false;   // the s2 has become empty set
            }
        }
    }
    else
    {
        for(int i = 0; i < length1; i++)
        {
            if(orderMap[s1[i]] < orderMap[s2[i]])           return true;    // satisfy the order
            else if(orderMap[s1[i]] > orderMap[s2[i]])      return false;   // not satisfy the order

            if(i==length1-1)                                return true;    // 2 string are the same
        }
    }
    return true;
}

bool Solution::isAlienSorted(vector<string>& words, string order)
{
    map<char, int> orderMap;
    bool result = true;

    for(int i = 0 ; i < order.size() ; i++)
    {
        orderMap[order[i]] = i;
    }

    for(int i = 1 ; i < words.size() ; i++)
    {
        result = compare(words[i-1], words[i], orderMap);

        if(result == false)
        {
            return false;
        }
        else
        {
            if(i == words.size() - 1)
            {
                return true;
            }
        }
    }
    return true;
}

int main()
{
    Solution solution;
#if 0
    solution.words = {"hello","leetcode"};
    solution.order = "hlabcdefgijkmnopqrstuvwxyz";
#endif

#if 0
    solution.words = {"word","world","row"};
    solution.order = "worldabcefghijkmnpqstuvxyz";
#endif

#if 1
    solution.words = {"apple","app"};
    solution.order = "abcdefghijklmnopqrstuvwxyz";
#endif

    string result = (solution.isAlienSorted(solution.words, solution.order))? "true" : "false";

    cout << result << endl;
    return 0;
}