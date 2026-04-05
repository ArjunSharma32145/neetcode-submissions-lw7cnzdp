class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int i=0;
        int j=n-1;
     int   maxarea=0;
     int   currarea=0;
       while(i<j){
        currarea = (j-i)*(min(heights[i],heights[j]));
        maxarea=max(maxarea,currarea);
        if(heights[i]<heights[j]) i++;
        else j--;
       }
       return maxarea;
    }
};
