class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxleft= 0;
        int i= 0;
        int j= n-1;
        int maxright = 0;
        int totalwater = 0;
        while(i<j){
            if(height[i]<=height[j]){
                 maxleft = max(maxleft,height[i]);
                totalwater += maxleft-height[i];
                i++;
            }
            else{
                maxright = max(maxright,height[j]);
                totalwater += maxright-height[j];
                j--;
            }
        }
        return totalwater;
    }
};
