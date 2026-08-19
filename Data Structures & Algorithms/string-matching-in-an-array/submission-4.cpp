class Solution {
    bool check(string a,string b){
       return b.find(a) != string::npos;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
         set<string> st;
        for(int i=0;i<words.size();i++){
            string yo = words[i];
            for(int j=0;j<words.size();j++){
                if(i == j) continue;
                if(check(yo,words[j])) st.insert(yo);
            }
        }
        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};