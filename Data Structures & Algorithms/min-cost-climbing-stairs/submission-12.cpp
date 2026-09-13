class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        dp[0] = 0; // to reach stair 0 no cost req as we can start from here
        dp[1] = 0; // to reach stair 1 no cost req as we can start from here 
        for(int i=2;i<=n;i++){
          int onejump = dp[i-1] + cost[i-1];
          int twojump = dp[i-2] + cost[i-2];
          dp[i] = min(onejump,twojump);
        }
        return dp[n];
    }
};
