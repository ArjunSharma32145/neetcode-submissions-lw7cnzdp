class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p = -1;
        for(int i=n-2;i>=0;i--){
          if(nums[i] < nums[i+1]) {
             p=i;
            break;
          }
 
        }

        if(p>=0){
      int j = n-1;
     while(j>=0){
        if(nums[p] <nums[j]) break;
        j--;
     }
     swap(nums[p],nums[j]);
        }
        int l = p+1;
        int r = n-1;
        while(l<r){
            swap(nums[l++],nums[r--]);
        }
    }
};