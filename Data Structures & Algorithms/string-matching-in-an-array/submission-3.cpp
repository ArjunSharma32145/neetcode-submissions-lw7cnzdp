class Solution {
    bool check(string a,string b){
        int i = 0;
        int j = 0;
        while(j<b.size() && i<a.size()){
            if(a[i] == b[j]){
             i++;
             j++;
            }
           else{
            i= 0;
            j++;
           }
        }
        return i == a.size();
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