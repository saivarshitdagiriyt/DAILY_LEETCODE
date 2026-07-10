class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
         vector<vector<int>>dist(n,vector<int>(m,0));
         queue<pair<pair<int,int>,int>>q;
         for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
         }
         while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            dist[row][col] = t;
            q.pop();
            for(int i = -1;i<=1;i++){
                for(int j = -1;j<=1;j++){
                   if(abs(i)+abs(j)==1){
                     int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                        q.push({{nrow,ncol},t+1});
                        vis[nrow][ncol]=1;
                    }
                   }
                    
                }
         }          
      }             
     return dist;
}
};