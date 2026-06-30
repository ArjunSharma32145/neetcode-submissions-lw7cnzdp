class Solution {
    static const int N = 1001;
    int parent[N];
    int size[N];
    void make(int v){
        parent[v]= v;
        size[v] = 1;
    }
    int find(int v){
        if(parent[v] == v) return v;
        //path compression
        return parent[v] = find(parent[v]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] <size[b]) swap(a,b);
            parent[b]= a;
            size[a] += size[b];
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for(int i=0;i<n;i++) make(i);
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.count(accounts[i][j])){
                    Union(i,mpp[accounts[i][j]]);
                }
                else{
                    mpp[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int,set<string>> roottoemail;
        for(auto it : mpp){
            int root = it.second;
            string email = it.first;
            root = find(root);
            roottoemail[root].insert(email);
        }
        vector<vector<string>> ans;
        for(auto it : roottoemail){
            vector<string> entry;
            int root = it.first;
            entry.push_back(accounts[root][0]);
            for(auto x : it.second) entry.push_back(x);
            ans.push_back(entry);
        }
        return ans;
    }
};