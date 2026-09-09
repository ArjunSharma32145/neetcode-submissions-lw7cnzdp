class Solution {
public:
    bool isValid(string s) {
        // logic yehi hai open bracket hai to dalte jao aur agar close to pop kardo
        stack<char> st;
        for(auto c : s){
            if(c == '}' || c == ']' || c == ')'){
                if(st.empty()) return false;
                if(c == ')' && st.top() == '(') st.pop();
                else if(c == ']' && st.top() == '[') st.pop();
                else if(c == '}' && st.top() == '{') st.pop();
                else return false;
            }
            else st.push(c);
        }
        return st.empty();
    }
};
