#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int flip(int n) {
    return n ^ 1;
}

int sign(int n) {
    return flip(n >> 31) & 1;
}

int getMax(int a, int b) {
    int c = a - b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);

    int diffAB = sa ^ sb;
    int sameAB = flip(diffAB);

    int returnA = diffAB * sa + sameAB * sc;
    int returnB = flip(returnA);
    return a * returnA + b * returnB;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << getMax(a, b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
