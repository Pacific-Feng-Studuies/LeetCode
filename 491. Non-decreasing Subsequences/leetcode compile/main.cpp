class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) ;
        
};

void backtrace(vector<int>& nums, vector<int>& sequence, set<vector<int>>& result, int index)
{   
    if(index == nums.size())
    {
        if(sequence.size() >= 2)                        // If the sequence length >= 2, then this sequence is valid
        {
            result.insert(sequence);
        }
        return;
    }
    
    if(sequence.empty() == true ||  sequence.back() <= nums[index])
    {
        sequence.emplace_back(nums[index]);
        backtrace(nums, sequence, result, index+1);     // Accept the choice of adding the next word
        sequence.pop_back();
    }
    backtrace(nums, sequence, result, index+1);         // Skip the choice of adding the next word
}

vector<vector<int>> Solution::findSubsequences(vector<int>& nums) 
{
    set<vector<int>> result;                            // use "set" for avoiding the repetition 
    vector<int> sequence;

    backtrace(nums, sequence, result, 0);

    return vector(result.begin(), result.end());                        // For c++17 up
    //return vector<vector<int> >(result.begin(), result.end());        // For c++17 lower
}
