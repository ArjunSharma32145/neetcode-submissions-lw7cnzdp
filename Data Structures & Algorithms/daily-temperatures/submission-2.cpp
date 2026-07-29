class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> result(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()) result[i] = 0;
            else if(temperatures[st.top()] > temperatures[i]){
                 result[i] = st.top() - i;
            } 
            else if(temperatures[st.top()] <= temperatures[i]){
                while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
                if(st.empty()) result[i] = 0;
                else result[i] = st.top() - i;
            }

            st.push(i);
        }
        return result;
    }
};
