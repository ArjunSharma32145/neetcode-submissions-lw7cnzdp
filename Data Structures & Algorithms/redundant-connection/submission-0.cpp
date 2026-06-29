class Solution {
   static const int n = 101;
    int parent[n];
    int size[n];

    void make(int v){
        parent[v] = v;
        size[v]= 1;
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
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i=1;i<=n;i++) make(i);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(find(u) == find(v)) return {u,v};
            Union(u,v);
        }
        return {};
    }
};
