class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == ')' || it == '}' || it == ']'){
                if(it == ')' && !st.empty() && st.top() == '(') st.pop();
                else if(it == '}' && !st.empty() && st.top() == '{') st.pop();
                else if(it == ']' && !st.empty() && st.top() == '[') st.pop();
                else return false;
            }
            else st.push(it);
        }
        return st.empty();
    }
};
