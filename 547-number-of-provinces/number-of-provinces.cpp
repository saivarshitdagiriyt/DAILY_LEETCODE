class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       vector<vector<int>>adj(n);
       for(int i =0;i<n;i++){
        vector<int>level;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
            }
       }
       }
    vector<int>vis(n,0);
    int provinces = 0;
    for(int i = 0;i<n;i++){
        if(vis[i]==0){
            provinces++;
            bfs(i,vis,adj);
        }
    }
    return provinces;
    }
    void bfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int bot = q.front();
            q.pop();
            for(auto it : adj[bot]){
                if(vis[it]==0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
};