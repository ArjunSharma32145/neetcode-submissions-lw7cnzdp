class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start <= end){
            int mid  = start  + (end - start)/2;
            if(mid%2 != 0) mid--;
            if(mid != start && nums[mid] == nums[mid-1]){
               end = mid-2;
            }
            else if(mid != end && nums[mid] == nums[mid+1]){
                start = mid+2;
            }
            else{
                return nums[mid];
            }
        }
        return nums[start];
    }
};