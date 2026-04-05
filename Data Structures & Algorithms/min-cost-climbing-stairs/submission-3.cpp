class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2;i<=n;i++){
          int ekjump = cost[i-1] + dp[i-1];
          int dojump = cost[i-2] + dp[i-2];
          dp[i] = min(ekjump,dojump);
        }
        return dp[n] ;
    }
};
