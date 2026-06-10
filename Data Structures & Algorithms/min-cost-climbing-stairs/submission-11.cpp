class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       vector<int> dp(n+2,0);
       dp[0] = 0;
       dp[1] =  0;
       if(n==1) return dp[1];
       dp[2] = 0;

      for(int i=3;i<=n+1;i++){
        int oneway = dp[i-1] + cost[i-2];
        int secway = dp[i-2] + cost[i-3];
        dp[i] = min(oneway,secway);
      }
      return dp[n+1];
    }
};
