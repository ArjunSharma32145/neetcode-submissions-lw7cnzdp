class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int start =0;
        int end = n-1;
        int answer = nums[0];
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[start] <= nums[end] ){
                answer = min(answer,nums[start]);
                break;
            }
            answer = min(answer,nums[mid]);
            if(nums[mid] >= nums[start]){
                start = mid+1;
            }
            else end = mid-1;
        }
        return answer;
    }
};
