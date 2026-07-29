class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ans;
        stack<int> st;
        int n = heights.size();
        for(int i=0;i<n;i++){
            if(st.empty()) ans.push_back(-1);
            else if(heights[st.top()] >= heights[i]){
                while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
            }
            else ans.push_back(st.top());

            st.push(i);
        }
        while(!st.empty()) st.pop();
        int an = 0;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                an = max((n - ans[i] -1)*heights[i],an);
            }
            else if(heights[st.top()] >= heights[i]){
                while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                if(st.empty()) an = max((n - ans[i] -1)*heights[i],an);
                else an = max((st.top() - ans[i] - 1)*heights[i],an);
            }
            else an = max((st.top() - ans[i] - 1)*heights[i],an);
            st.push(i);
        }
        return an;
    }
};
