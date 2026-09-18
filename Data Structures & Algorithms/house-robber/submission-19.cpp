class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
       int prev1 = nums[0];
        int curr = prev1;
        for(int i=2;i<=n;i++){
            int loot = nums[i-1] + prev2;
            int notloot =  0 + prev1;
             curr = max(loot,notloot);
             prev2 = prev1;
             prev1 = curr;
        }
        return curr;
    }
};
