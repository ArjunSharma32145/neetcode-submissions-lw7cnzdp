class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
int func(int m,vector<int> & dp){
  if(m==0) return 1;
  if(m==1) return 1;
  if(dp[m] != -1) return dp[m];
  int oneWay = func(m-1,dp);
  int secWay = func(m-2,dp);
  return dp[m] = oneWay + secWay;
} 
};
