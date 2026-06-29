class Solution {
    static const int N = 1001;
    int parent[N];
    int size[N];

    void make(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v){
        if(parent[v] == v) return v;
        //path compression
        return parent[v] = find(parent[v]);
    }

    void Union(int a,int b){
        a = find(a);
        b= find(b);
        if( a != b){
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=i;j<points.size();j++){
                if(i == j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int cost = abs(x1-x2) + abs(y1-y2);
                edges.push_back({cost,{i,j}}); 
            }
        }
        for(int i=0;i<points.size();i++) make(i);
        int ans = 0;
        sort(edges.begin(),edges.end());
        for(auto it : edges){
         int u = it.second.first;
         int v = it.second.second;
         int cost = it.first;
         if(find(u) == find(v)) continue;
         Union(u,v);
         ans += cost;
        }
        return ans;
    }
};
