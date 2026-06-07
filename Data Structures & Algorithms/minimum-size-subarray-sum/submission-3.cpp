class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0;
        int minwindow = 1e9;
        int sum = 0;
        int j=0;
        for( j=0;j<nums.size();j++){
            while(sum >= target){
              
                minwindow = min(minwindow,j-l);
                sum -= nums[l];
                l++;
                if(sum >= target) minwindow =min(minwindow,j-l);
            }
            sum += nums[j];
        }
        while(l<=j && sum >= target){
              minwindow = min(minwindow,j-l);
                sum -= nums[l];
                l++;
                if(sum >= target) minwindow =min(minwindow,j-l);
        }
        if(minwindow == 1e9) return 0;
        else return minwindow;
    }
};