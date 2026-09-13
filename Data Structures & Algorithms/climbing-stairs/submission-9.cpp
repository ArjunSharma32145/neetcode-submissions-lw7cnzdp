class Solution {
  vector<int> dp;
  int solve(int index,int n){
    if(index == n) return 1;
    if(index > n) return 0;
    //choices
    if(dp[index] != -1) return dp[index];
    int onejump = solve(index+1,n);
    int doublejump = solve(index+2,n);
    return dp[index] = onejump + doublejump;
  }
public:
    int climbStairs(int n) {
      dp.resize(n,-1);
        return solve(0,n);
    }
};
