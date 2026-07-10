class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++){
            if(grid[i][0]==1){
              q.push({i,0});
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
            }
        }
        for(int i = 0;i<m;i++){
            if(grid[0][i]==1){
                q.push({0,i});
            }
            if(grid[n-1][i]==1){
                q.push({n-1,i});
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!q.empty()){
            pair<int,int>start = {q.front().first,q.front().second};
            if(!vis[start.first][start.second]){
                dfs(start,vis,grid,n,m);
            } 
           q.pop();
        }
        int landcell = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                  landcell++;
            }
        }
    }
    return landcell;
    }
    void dfs(pair<int,int>&node,vector<vector<int>>&vis,vector<vector<int>>&grid,int n,int m){
        int row = node.first;
        int col = node.second;
        grid[row][col] = 0;
        vis[node.first][node.second] = 1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 &&
                    !vis[nrow][ncol]){
                      pair<int,int>temp = {nrow,ncol};
                      dfs(temp,vis,grid,n,m);
                    }

                }
            }
        }
    
    
}
};