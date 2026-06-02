class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p =0;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                 k++;
                swap(nums[i],nums[p]);
                p++;
            }
        }
        return k;
    }
};