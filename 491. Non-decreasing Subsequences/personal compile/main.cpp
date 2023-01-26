
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) ;
    
    vector<int> nums;
};

void backtrace(vector<int>& nums, vector<int>& sequence, set<vector<int>>& result, int index)
{   
    if(index == nums.size())
    {
        if(sequence.size() >= 2)
        {
            result.insert(sequence);
        }
        return;
    }
    
    if(sequence.empty() == true ||  sequence.back() <= nums[index])
    {
        sequence.emplace_back(nums[index]);
        backtrace(nums, sequence, result, index+1);
        sequence.pop_back();
    }
    backtrace(nums, sequence, result, index+1);
}

vector<vector<int>> Solution::findSubsequences(vector<int>& nums) 
{
    set<vector<int>> result;
    vector<int> sequence;

    backtrace(nums, sequence, result, 0);

    return vector<vector<int> >(result.begin(), result.end());
}

int main()
{
    Solution solution;

    vector<int>nums{4, 6, 7, 7, 1};
    solution.nums = nums;

    vector<vector<int> > result;
    result = solution.findSubsequences(solution.nums);

    cout << "[";

    for(int i = 0 ; i < result.size(); i++)
    {
        cout << "[" ;
        for(int j = 0 ; j < result[i].size() ; j++)
        {
            cout << result[i][j] ;

            if(j != result[i].size()-1)
            {
                cout << " ," ;
            }
        }
        cout << "]" ;

        if(i == result.size()-1)
        {
            cout << "]" << endl;
        }
    }
}
