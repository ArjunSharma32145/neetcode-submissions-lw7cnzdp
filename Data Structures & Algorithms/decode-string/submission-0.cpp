class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto it : s){
            if(it == ']'){
              string lol;
              while(st.top() != "["){
                lol += st.top();
                st.pop();
              }  
              st.pop();
              int count =0;
              string num;
              while(!st.empty() && isdigit(st.top()[0])){
                num += st.top();
                st.pop();
              }
              reverse(num.begin(),num.end());
              count = stoi(num);
              string repeat;
              while(count--) repeat += lol;
              st.push(repeat);
            }
            else st.push(string(1,it));
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};