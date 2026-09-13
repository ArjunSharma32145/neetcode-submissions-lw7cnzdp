class Solution {
  int solve(int start,int end,vector<int> & nums){
   int prev2 = nums[start];
   int prev = max(nums[start],nums[start+1]);
   int curr = prev;
    for(int i=start+2;i<end;i++){
       int loot = nums[i] + prev2;
       int notloot = 0 + prev;
       curr = max(loot,notloot);
       prev2 = prev;
       prev = curr;
    }
    return curr;
  }
public:
    int rob(vector<int>& nums) {
        // as they are in circles so both houses first and last cant be robbed at same time
        int n = nums.size();
         if(n == 1) return nums[0];
         if(n == 2) return max(nums[0],nums[1]);
        return max(solve(0,n-1,nums),solve(1,n,nums));
    }
};
