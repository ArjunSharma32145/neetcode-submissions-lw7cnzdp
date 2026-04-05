class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0;
        int j = n-1;
        int ans =0;
        while(i<j){
            int breadth = j-i;
            int length = min(heights[i],heights[j]);
            int curarea = length*breadth;
            ans = max(ans,curarea);
            if(heights[i]<heights[j])i++;
            else j--;
        }
        return ans;
    }
};
