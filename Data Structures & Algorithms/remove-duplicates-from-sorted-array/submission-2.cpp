class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =0;
        int prev = -101;
        for(auto it : nums){
            if(it != prev){
                nums[k] = it;
  
                prev = it;
                k++;
            }
        }
        return k;
    }
};