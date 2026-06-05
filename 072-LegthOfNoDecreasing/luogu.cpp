#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	int N, K;
	std::cin >> N >> K;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
    
	std::vector<int> right(N, 0), ends(N, 0);

    // 构建 right：以 A[i] 为开头的最长不下降子序列长度
    auto build_right = [&]() {
        int len = 0;
        for (int i = N - 1; i >= 0; --i) {
            // 在降序的 ends[0..len) 中找第一个 < A[i]
            int pos = std::upper_bound(ends.begin(), ends.begin() + len, A[i], std::greater<int>()) - ends.begin();
            if (pos == len) {
                ends[len++] = A[i];
                right[i] = len;
            } else {
                ends[pos] = A[i];
                right[i] = pos + 1;
            }
        }
    };

    build_right();

    int len = 0;         // 重新用于维护升序 ends 的不下降子序列结构
    int ans = 0;

    for (int i = 0, j = K; j < N; ++i, ++j) {
        // 计算当前窗口 [i, j-1] 左侧贡献 + 修改 K 段 + 右侧贡献
        // 左侧贡献：在升序 ends[0..len) 中找第一个 > A[j]
        int pos = std::upper_bound(ends.begin(), ends.begin() + len, A[j]) - ends.begin();
        int left = (pos == len ? len : pos);
        ans = std::max(ans, left + K + right[j]);

        // 把 A[i] 纳入左侧结构（维护不下降子序列的 ends）
        pos = std::upper_bound(ends.begin(), ends.begin() + len, A[i]) - ends.begin();
        if (pos == len) ends[len++] = A[i];
        else ends[pos] = A[i];
    }
    ans = std::max(ans, len + K);

    std::cout << ans << '\n';
    return 0;
}