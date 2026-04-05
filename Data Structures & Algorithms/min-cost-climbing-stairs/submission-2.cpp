class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return func(n,cost,dp);
    }
    int func(int i, vector<int> & cost, vector<int> & dp){
      if(i==0 || i==1) return 0;
      if(dp[i] != -1) return dp[i];
      int ekjump = cost[i-1] + func(i-1,cost,dp);
      int dojump = cost[i-2] + func(i-2,cost,dp);
      return dp[i] = min(ekjump,dojump);
    }
};
