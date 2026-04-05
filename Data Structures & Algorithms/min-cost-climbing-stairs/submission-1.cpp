class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
        vector<int> dp(n+1,-1);
        return func(n,dp,cost);
    }
    int func(int index,vector<int> & dp,vector<int> & lol){
      if(index == 0 || index == 1) return 0;
      if(dp[index] != -1) return dp[index];
      int oneway = lol[index-1] + func(index-1,dp,lol);
      int secway = lol[index-2] + func(index-2,dp,lol);
      return dp[index] = min(oneway,secway);
    }
};
