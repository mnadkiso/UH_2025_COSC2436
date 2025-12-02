class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int dist = 1;
        int dirs[] = {-1, 0, 1, 0, -1, -1, 1, 1, -1};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                if (x == n-1 && y == n-1) return dist;
                for (int d = 0; d < 8; d++) {
                    int nx = x + dirs[d], ny = y + dirs[d+1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !grid[nx][ny]) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};