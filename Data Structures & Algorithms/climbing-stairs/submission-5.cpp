class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0); // so here i represent for ith index no of ways
        dp[1] = 1;// jab ek stair ho to kitne ways i guess ek hi tarike hua na
        if(n==1) return dp[1];
        dp[2] = 2; // ya to sidha 2 stair pe jump karo ya fir ek ek karke to obv 2 ways 
        if(n==2) return dp[2];
        for(int i=3;i<=n;i++){
          dp[i] = dp[i-1] + dp[i-2]; // either from step 1 or step 2 we can reach
        } 
     return dp[n]; // for n stair no of ways
    }
};
