
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/maximum-subarray/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT32_MIN;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp = max(tmp + nums[i], nums[i]);
            ans = max(ans, tmp);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}