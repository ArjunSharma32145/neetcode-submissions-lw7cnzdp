class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2,0); // so for reaching ith floor min cost
       dp[1] = 0; // for reaching 1st floor
       dp[2] = 0; // as we can start from here too so just take that
      
       for(int i=3;i<=n+1;i++){
            dp[i] = min(dp[i-1] + cost[i-2],dp[i-2] + cost[i-3]);
       }
       return dp[n+1];
    }
};
