#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::string> G(n + 2, std::string(m + 2, '.'));
    for (int i = 1; i <= n; i++) {
    	std::string s;
    	std::cin >> s;

    	for (int j = 1; j <= m; j++) {
    		G[i][j] = s[j - 1];
    	}
    }

    int ans = 0;

    std::queue<std::pair<int, int>> Q;
    std::vector<std::vector<int>> vis(n + 2, std::vector<int>(m + 2));

    auto push = [&](int x, int y) {
    	if (x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1 && !vis[x][y] && G[x][y] == '.') {
    		vis[x][y] = 1;
    		Q.push({x, y});

    		if (x >= 1 && x <= n && y >= 1 && y <= m) {
    			ans++;
    		}
    	}
    };

    auto bfs = [&]() {
    	while (!Q.empty()) {
    		auto [x, y] = Q.front();
    		Q.pop();

    		for (int i = 0; i < 4; i++) {
    			int nx = x + dx[i];
    			int ny = y + dy[i];
    			push(nx, ny);
    		}
    	}
    };

    push(0, 0);
    bfs();

    while (q--) {
    	int x, y;
    	std::cin >> x >> y;

    	if (G[x][y] == '#') {
    		G[x][y] = '.';

    		bool ok = false;
    		for (int i = 0; i < 4; i++) {
    			int nx = x + dx[i];
    			int ny = y + dy[i];

    			if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && vis[nx][ny]) {
    				ok = true;
    				break;
    			}
    		}

    		if (ok) {
    			push(x, y);
    			bfs();
    		}
    	}

    	std::cout << ans << "\n";
    }


    return 0;
}