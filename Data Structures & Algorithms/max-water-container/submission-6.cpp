class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int maxiarea = 0;
        int j = n-1;
        while(i<j){
        int b = j-i;
        int l = min(heights[i],heights[j]);
        maxiarea = max(l*b,maxiarea);
        if(heights[i] > heights[j]) j--;
        else i++;
        }
        return maxiarea;
    }
};
