class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map <int,vector <pair<int,int>>> adj;
        for(auto &i: roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});

        }
        priority_queue <pair<long,int>, vector <pair<long,int>>, greater<pair<long,int>>> q;
        vector <long> dist(n,LONG_MAX);
        vector <bool> vis(n,false);
        vector <int> count(n,0);

        q.push({0,0});
                
        dist[0] = 0;
        count[0] = 1;
        int mod = 1e9+7;
        while(!q.empty()) {
            auto curr = q.top();
            q.pop();
            int u = curr.second;
            if(vis[u])
                continue;
            vis[u] = true;
            for(auto &next:adj[u]) {
                int v = next.first; 
                int w = next.second;
                if(!vis[v]){
                    if(dist[v]>dist[u]+w){
                        dist[v] = dist[u]+w;
                        q.push({dist[v],v});
                        count[v] = count[u]%mod;
                    }
                    else if(dist[v]==dist[u]+w) {
                        count[v] = (count[v] + count[u])%mod;
                    }
                }
                       
            }

        }
        
        return count[n-1];
    }
};