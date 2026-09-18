class Solution {
    vector<int> dp;
    int solve(int sum,int n){
        if(sum == n) return 0;
        if(sum > n) return 1e9;
          
          if(dp[sum] != -1) return dp[sum];
        int ans= 1e8;
        for(int i=1;i*i <= n- sum;i++){
            if(sum + i*i <= n){
              ans =  min(ans,solve(sum + i*i,n) +1);
            }
        }
        return dp[sum] =  ans;
    }
public:
    int numSquares(int n) {
        dp.resize(n+1,-1);
        if(n == 1) return 1;
        return solve(0,n);
    }
};