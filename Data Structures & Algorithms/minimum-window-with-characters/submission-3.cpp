class Solution {
public:
    string minWindow(string s, string t) {
     // ok so two strings are given find shortest substring of s 
        // but i can also do it in this way too right
        if(t.size() > s.size()) return "";

        vector<int> counto(128,0);
        vector<int> tracko(128,0);
        string ans = "";
        int anslen = INT_MAX;
        int start = -1;
        for(auto it : t) counto[it]++;
        int need = 0;
        for(auto it : counto) if(it > 0) need++;
        int have = 0;
        int l = 0;
        for(int i=0;i<s.size();i++){
            int curr = s[i];
            tracko[curr]++;
            if(counto[curr] == tracko[curr]){
                have++;
            }
            while(have == need){
                if((i-l+1) < anslen ){
                    anslen = i-l+1;
                    start = l;
                }
                tracko[s[l]]--;
                if(tracko[s[l]] < counto[s[l]]) have--;
                l++;
            }
        }
        if(anslen != INT_MAX){
            ans = s.substr(start,anslen);
        }
        return ans;

    }
};
