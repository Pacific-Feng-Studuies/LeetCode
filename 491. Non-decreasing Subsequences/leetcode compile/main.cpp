class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) ;
        
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

    return vector(result.begin(), result.end());
}
