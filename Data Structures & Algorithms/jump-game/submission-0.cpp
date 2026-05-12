class Solution {
public:
    bool canJump(vector<int>& nums) {
        // acc to greedy approach we just gonna push the goal post and lets see can we move it to starting index or not baby
        int n = nums.size();
        int goal = n-1;
        for(int i=n-2;i>=0;i--){
            if(i + nums[i] >= goal) goal = i;
        }
        if(goal == 0) return true;
        return false;
    }
};
