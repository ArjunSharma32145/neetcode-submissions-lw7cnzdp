class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 1) return strs[0];
        string check = strs[0];
        vector<int> common;
        for(int i=1;i<strs.size();i++){
            string cont = strs[i];
            int k = 0;
            int count = 0;
            int j =0;
            while(j<check.size() && k<cont.size()){
                if(check[j] == cont[k]){
                    j++;
                    k++;
                    count++;
                }
                else break;
            }
            common.push_back(count);
        }
        int req = *min_element(common.begin(),common.end());
        for(int i=0;i<req;i++){
            ans += check[i];
        }
        return ans;
    }
};