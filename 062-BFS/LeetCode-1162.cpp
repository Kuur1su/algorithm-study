#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> move = {-1, 0, 1, 0, -1};
        vector<vector<bool>> vis(m, vector<bool>(n));

        queue<pair<int, int>> q;
        int seas = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    q.emplace(i, j);
                } else {
                    vis[i][j] = false;
                    seas++;
                }
            }
        }
        if (seas == 0 || seas == m * n) {
            return -1;
        }

        int level;
        while (!q.empty()) {
            int x, y, nx, ny, size;
            size = q.size();
            level++;
            for (int k = 0; k < size; k++) {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    nx = x + move[i];
                    ny = y + move[i + 1];
                    if (nx > 0 && nx <= m && ny > 0 && ny <= n && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        }

        return level;
    }
};
