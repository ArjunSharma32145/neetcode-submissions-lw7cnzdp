class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
      return func(n-1,nums,dp);
    }
private : 
  int func(int n , vector<int> & nums, vector<int> & dp){
    if(n==0) return nums[n];
    if(n<0) return 0;
     // write all ways thats what we do in recursion hmm yeah if it picks the house then it will jumps to next next house if not picked otherwise it woll go to next adjacent boom take both ways go till end and return the max
     if(dp[n] !=-1) return dp[n];
     int pick = nums[n] + func(n-2,nums,dp);
     int notpick = 0 + func(n-1,nums,dp);
     return dp[n]= max(pick,notpick); 
  }
};
