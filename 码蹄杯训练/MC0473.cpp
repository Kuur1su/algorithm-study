#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n;
    std::cin >> n;

    std::vector<std::string> G(2);
    std::vector<std::vector<bool>> vis(2, std::vector<bool>(n));

    for (int i = 0; i < 2; i++) {
        std::cin >> G[i];
    }
    int ans = 0;

    auto bfs = [&](int xx, int yy) -> void {
        std::queue<std::pair<int, int>> q;
        q.push({xx, yy});
        vis[xx][yy] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < 2 && ny >= 0 && ny < n) {
                    if (G[nx][ny] == G[x][y] && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});                    
                    }
                }
            }
        }
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                ans++;
                bfs(i, j);
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}