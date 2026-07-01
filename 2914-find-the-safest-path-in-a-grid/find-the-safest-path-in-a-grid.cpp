class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safe(n,vector<int>(n,INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    safe[i][j] = 0;
                }
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                if(safe[nx][ny] == INT_MAX){
                    q.push({nx,ny});
                    safe[nx][ny] = safe[x][y] + 1;
                }
            }
        }

        if(safe[0][0] == 0 || safe[n-1][n-1] == 0) return 0;

        vector<vector<int>> dist(n,vector<int>(n,-1));

        priority_queue<pair<int,pair<int,int>>> mn;

        dist[0][0] = safe[0][0];
        mn.push({safe[0][0],{0,0}});

        while(!mn.empty()){
            auto [d,xy] = mn.top();
            auto [x,y] = xy;


            mn.pop();
            if(d < dist[x][y]) continue;

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                if(min(d,safe[nx][ny]) > dist[nx][ny]){
                    mn.push({min(d,safe[nx][ny]),{nx,ny}});
                    dist[nx][ny] = min(d,safe[nx][ny]);
                }
            }
        }

        return dist[n-1][n-1];
    }
};