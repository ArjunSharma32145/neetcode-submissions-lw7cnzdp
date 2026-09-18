class Solution {
    vector<vector<int>> dp;
    int solve(int sum,int n,int prod,int count){
        if(sum == n && count >=2) return 1;
        if(sum > n || (sum == n && count<2) ) return INT_MIN;
         
         if(dp[sum][count] != -1) return dp[sum][count];
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
            if(sum + i <= n){
              ans = max(ans,solve(sum+i,n,prod*i,count+1)*i);
            }
        }
        return dp[sum][count] =  ans;
    }
public:
    int integerBreak(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n,1,0);
    }
};