#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class ScapegoatTree {
private:
    struct Node {
        int key;
        int cnt;
        int l, r;
        int size;
        int diff;
    };

    static const int MAXN = 100000 + 5;
    static Node tr[MAXN];       // 静态数组，放在静态区
    static int collectIdx[MAXN];

    double ALPHA;
    int head;
    int cnt;
    int cost;

    int ci;
    int top;
    int father;
    int side;

    int init(int num) {
        ++cnt;
        tr[cnt].key = num;
        tr[cnt].l = tr[cnt].r = 0;
        tr[cnt].cnt = 1;
        tr[cnt].size = 1;
        tr[cnt].diff = 1;
        return cnt;
    }

    void up(int i) {
        if (i == 0) return;
        int L = tr[i].l, R = tr[i].r;
        tr[i].size = (L ? tr[L].size : 0) + (R ? tr[R].size : 0) + tr[i].cnt;
        tr[i].diff = (L ? tr[L].diff : 0) + (R ? tr[R].diff : 0) + (tr[i].cnt > 0 ? 1 : 0);
    }

    void inorder(int i) {
        if (i == 0) return;
        inorder(tr[i].l);
        if (tr[i].cnt > 0) collectIdx[++ci] = i;
        inorder(tr[i].r);
    }

    int build(int l, int r) {
        if (l > r) return 0;
        int m = (l + r) >> 1;
        int h = collectIdx[m];
        tr[h].l = build(l, m - 1);
        tr[h].r = build(m + 1, r);
        up(h);
        return h;
    }

    void rebuild() {
        if (top == 0) return;
        ci = 0;
        inorder(top);
        if (ci > 0) {
            cost += ci;
            int newSub = build(1, ci);
            if (father == 0) {
                head = newSub;
            } else if (side == 1) {
                tr[father].l = newSub;
            } else {
                tr[father].r = newSub;
            }
        }
    }

    bool balance(int i) {
        if (i == 0) return true;
        int L = tr[i].l, R = tr[i].r;
        int leftDiff = L ? tr[L].diff : 0;
        int rightDiff = R ? tr[R].diff : 0;
        return ALPHA * (double)tr[i].diff >= (double)max(leftDiff, rightDiff);
    }

    void add(int i, int f, int s, int num) {
        if (i == 0) {
            int node = init(num);
            if (f == 0) head = node;
            else if (s == 1) tr[f].l = node;
            else tr[f].r = node;
            return;
        }
        if (tr[i].key == num) {
            tr[i].cnt++;
        } else if (tr[i].key > num) {
            add(tr[i].l, i, 1, num);
        } else {
            add(tr[i].r, i, 2, num);
        }

        up(i);
        if (!balance(i)) {
            top = i;
            father = f;
            side = s;
        }
    }

    int small(int i, int num) {
        if (i == 0) return 0;
        if (tr[i].key >= num) {
            return small(tr[i].l, num);
        } else {
            int L = tr[i].l;
            return (L ? tr[L].size : 0) + tr[i].cnt + small(tr[i].r, num);
        }
    }

    int indexK(int i, int x) {
        if (i == 0) return -2147483648;
        int L = tr[i].l;
        int leftSize = L ? tr[L].size : 0;
        if (x <= leftSize) {
            return indexK(L, x);
        } else if (x > leftSize + tr[i].cnt) {
            return indexK(tr[i].r, x - leftSize - tr[i].cnt);
        } else {
            return tr[i].key;
        }
    }

    void removeAt(int i, int f, int s, int num) {
        if (i == 0) return;
        if (tr[i].key == num) {
            tr[i].cnt--;
        } else if (tr[i].key > num) {
            removeAt(tr[i].l, i, 1, num);
        } else {
            removeAt(tr[i].r, i, 2, num);
        }

        up(i);
        if (!balance(i)) {
            top = i;
            father = f;
            side = s;
        }
    }

public:
    ScapegoatTree(double alpha = 0.7) {
        ALPHA = alpha;
        head = cnt = cost = 0;
        ci = top = father = side = 0;
        memset(tr, 0, sizeof(tr));
        memset(collectIdx, 0, sizeof(collectIdx));
    }

    void insert(int num) {
        side = father = top = 0;
        add(head, 0, 0, num);
        rebuild();
    }

    void erase(int num) {
        if (rankOf(num) != rankOf(num + 1)) {
            side = father = top = 0;
            removeAt(head, 0, 0, num);
            rebuild();
        }
    }

    int rankOf(int num) {
        return small(head, num) + 1;
    }

    int kth(int k) {
        if (head == 0 || k <= 0 || k > tr[head].size) return -2147483648;
        return indexK(head, k);
    }

    int predecessor(int num) {
        int rk = rankOf(num);
        if (rk == 1) return -2147483648;
        return kth(rk - 1);
    }

    int successor(int num) {
        int rk = rankOf(num + 1);
        if (head == 0) return 2147483647;
        if (rk == tr[head].size + 1) return 2147483647;
        return this->kth(rk);
    }

    int height() {
        return deep(head);
    }

    int deep(int i) {
        if (i == 0) return 0;
        return max(deep(tr[i].l), deep(tr[i].r)) + 1;
    }

    void clear() {
        memset(tr, 0, sizeof(tr));
        head = cnt = cost = 0;
    }

    int rebuildCost() const {
        return cost;
    }
};


// 静态成员定义
ScapegoatTree::Node ScapegoatTree::tr[MAXN];
int ScapegoatTree::collectIdx[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::cerr << 1 << "\n";

    ScapegoatTree tree(0.7);
    int maxN = 10000;
    cout << "start\n";

    for (int i = 1; i <= maxN; ++i) {
        tree.insert(i);
    }

    cout << "insert : 1~" << maxN << "\n";
    cout << "balance : 0.7\n";
    cout << "height : " << tree.height() << "\n";
    cout << "rebuild : " << tree.rebuildCost() << "\n";
    cout << "end!\n";

    return 0;
}
