class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =0;
        int p=0;
        sort(nums.begin(),nums.end());
        int prev = -101;
        for(auto it : nums){
            if(it != prev){
                nums[p] = it;
                p++;
                prev = it;
                k++;
            }
        }
        return k;
    }
};