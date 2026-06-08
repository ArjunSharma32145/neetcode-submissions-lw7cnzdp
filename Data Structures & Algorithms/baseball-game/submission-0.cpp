class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto it : operations){
            if(it == "+" || it == "D" || it == "C"){
                if(it == "C") st.pop();
                else if(it == "D"){
                    int x = st.top();
                    st.push(2*x);
                }
                else{
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.push(x);
                    st.push((x+y));
                }
            }
            else st.push(stoi(it));
        }
        int totalsum = 0;
        while(!st.empty()){
            totalsum += st.top();
            st.pop();
        }
        return totalsum;
    }
};