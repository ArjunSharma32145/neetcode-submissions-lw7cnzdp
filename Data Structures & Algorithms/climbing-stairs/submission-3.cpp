class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
    int func(int i,vector<int> & dp){
      if(i==0) return 1;
      if(dp[i] != -1) return dp[i];
      int ekjump = func(i-1,dp);
      int dojump = func(i-2,dp);
      return dp[i] = ekjump + dojump;
    }
};
