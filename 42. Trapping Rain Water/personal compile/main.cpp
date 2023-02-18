#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height);

    vector<int> height;
};

int Solution::trap(vector<int>& height)
{
    // The curr found maximun value of each sides
    int max_left = 0;
    int max_right = 0;

    // The curr position of each sides
    int l_pos = 0;
    int r_pos = height.size()-1;

    // The result amount of the water
    int res = 0; 

    while(r_pos > l_pos)
    {
        if(height[r_pos] > height[l_pos])       
        {
            max_left = max(max_left, height[l_pos]);
            res += max_left - height[l_pos];
            l_pos++;
        }
        else
        {   max_right = max(max_right, height[r_pos]);
            res += max_right - height[r_pos];
            r_pos--;
        }
    }

    return res;
}


int main()
{
    Solution solution;

    solution.height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = solution.trap(solution.height);

    cout << "The result = " << result << endl;

    return 0;
}