class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
    int subsetSum = 0;
    int n = nums.size();

    for(auto& p : nums) totalSum += p;

    if(totalSum%2 == 1) return false;

    subsetSum = totalSum/2;

    // dp[i][j] means that whether j can be composed of the first i element
    vector<vector<bool> > dp(n+1, vector<bool>(subsetSum+1, false));    

    for(int i = 0; i < n+1; i++)
    {
        dp[i][0] = true;    // if not choose anyone, then it equal to 0
    }

    for(int i = 1; i < subsetSum+1; i++)
    {
        dp[0][i] = false;   // if not choose anyone, then the sum will only be 0
    }

    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = 1 ; j < subsetSum+1 ; j++)
        {
            dp[i][j] = dp[i-1][j];  // just for not choose i

            if(j>=nums[i-1])
            {
                dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
            }
        }
    }
    return dp[n][subsetSum];    // to choose includes first n element, whether the value will be "subsetSum"
    }
};
