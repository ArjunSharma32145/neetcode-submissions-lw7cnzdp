class Solution {
  vector<int> dp;
  int solve(int index,vector<int> & nums){
    if(index == nums.size()-1) return 0;
     
    if(dp[index] != -1) return dp[index];
    int value = nums[index];
    int res = 1e9;
    for(int i=1;i<=value;i++){
      if(index + i < nums.size()){
          res = min(res,solve(index+i,nums) + 1);
      }
    }
    return dp[index] =  res;
  }
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      dp.resize(n,-1);
        return solve(0,nums);
    }
};
