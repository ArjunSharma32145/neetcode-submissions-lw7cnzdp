class Solution {
    vector<int> dp;
    bool solve(int index,vector<int> & nums){
        if(index == nums.size() -1) return true;
         
         if(dp[index] != -1) return dp[index];
        int value = nums[index];
        for(int i=1;i<=value;i++){
          if(index + i < nums.size()){
            if(solve(index+i,nums)) return dp[index] =  true;
          }
        }
        return dp[index] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return solve(0,nums);
    }
};
