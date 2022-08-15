
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/coin-change/
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<uint> dp(amount + 1, UINT32_MAX);

        dp[0] = 0;

        for (int a = 1; a < amount + 1; a++)
        {
            for (auto &c : coins)
            {
                if (a >= c)
                {
                    uint tmp = dp[a - c] == UINT32_MAX ? UINT32_MAX : dp[a - c] + 1;
                    dp[a] = min(tmp, dp[a]);
                }
            }
        }

        return dp[amount] == UINT32_MAX ? -1 : dp[amount];
    }
};

int main()
{
    Solution sol;
    vector<int> coin({2});
    int amount = 3;
    cout << sol.coinChange(coin, amount) << endl;

    return 0;
}