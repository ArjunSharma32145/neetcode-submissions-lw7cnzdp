class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,-1);
        return func(n,cost,dp);
    }
private :
  int func(int ind,vector<int> & lol,vector<int> & dp){
    if(ind ==0 || ind ==1) return 0;

    if(dp[ind] != -1) return dp[ind];
    int oneWay = lol[ind-1] + func(ind-1,lol,dp);
    int secWay =0;
    if(ind>1) secWay = lol[ind-2] + func(ind-2,lol,dp);
    return dp[ind] = min(oneWay,secWay);
  }
};
