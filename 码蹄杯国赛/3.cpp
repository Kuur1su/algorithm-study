#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 	
 	int n;
 	std::cin >> n;

 	std::vector<std::vector<int>> grid(n, std::vector<int>(4));

 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < 4; j++) {
 			std::cin >> grid[i][j];
 		}
 	}

 	std::vector<int> ans(n);

 	for (int i = 0; i < n; i++) {
 		int cur = 0;
 		for (int j = 0; j < n; j++) {
 			if ((grid[j][0] >= grid[i][0] && grid[j][0] <= grid[i][2] && grid[j][1] >= grid[i][1] && grid[j][1] <= grid[i][3]) || 
 				(grid[j][2] >= grid[i][0] && grid[j][2] <= grid[i][2] && grid[j][3] >= grid[i][1] && grid[j][3] <= grid[i][3]) || 
 				(grid[i][0] >= grid[j][0] && grid[i][0] <= grid[j][2] && grid[i][1] >= grid[j][1] && grid[i][1] <= grid[j][3]) ||
 				(grid[i][2] >= grid[j][0] && grid[i][2] <= grid[j][2] && grid[i][3] >= grid[j][1] && grid[i][3] <= grid[j][3]) ||
 				(grid[j][0] >= grid[i][0] && grid[j][2] <= grid[i][2] && grid[i][1] >= grid[j][1] && grid[i][3] <= grid[j][3]) ||
 				(grid[i][0] >= grid[j][0] && grid[i][2] <= grid[j][2] && grid[j][1] >= grid[i][1] && grid[j][3] <= grid[i][3]) ||
 				(grid[j][0] >= grid[i][0] && grid[j][0] <= grid[i][2] && grid[j][3] >= grid[i][1] && grid[j][3] <= grid[i][3]) || 
 				(grid[j][2] >= grid[i][0] && grid[j][2] <= grid[i][2] && grid[j][1] >= grid[i][1] && grid[j][1] <= grid[i][3]) ||
 				(grid[i][0] >= grid[j][0] && grid[i][0] <= grid[j][2] && grid[i][3] >= grid[j][1] && grid[i][3] <= grid[j][3]) || 
 				(grid[i][2] >= grid[j][0] && grid[i][2] <= grid[j][2] && grid[i][1] >= grid[j][1] && grid[i][1] <= grid[j][3])) {
 				cur++;
 			}
 		}
 		std::cout << cur - 1 << " ";
 	}

 	std::cout << "\n";

    return 0;
}