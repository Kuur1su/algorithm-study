#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int inf = 1E9;

struct Node {
    int key, height, size, cnt;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), size(1), cnt(1), 
        left(nullptr), right(nullptr) {}
};

int getHeight(Node* p) {
    return p ? p->height : 0;
}

int getSize(Node* p) {
    return p ? p->size : 0;
}

void update(Node* p) {
    if (!p) return;
    p->height = std::max(getHeight(p->left), getHeight(p->right)) + 1;
    p->size = getSize(p->left) + getSize(p->right) + p->cnt;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    update(y);
    update(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    update(x);
    update(y);
    return y;
}

Node* maintain(Node* p) {
    if (!p) return p;
    int balance = getHeight(p->left) - getHeight(p->right);
    if (balance > 1) {
        if (getHeight(p->left->left) >= getHeight(p->left->right)) {
            p = rightRotate(p);
        } else {
            p->left = leftRotate(p->left);
            p = rightRotate(p);
        }
    } else if (balance < -1) {
        if (getHeight(p->right->right) >=getHeight(p->right->left)) {
            p = leftRotate(p);
        } else {
            p->right = rightRotate(p->right);
            p = leftRotate(p);
        }
    }

    return p;
}

Node* insert(Node* p, int key) {
    if (!p) return new Node(key);
    if (key == p->key) {
        p->cnt++;
    } else if (key < p->key) {
        p->left = insert(p->left, key);
    } else if (key > p->key) {
        p->right = insert(p->right, key);
    }

    update(p);
    return maintain(p);
}

Node* getMin(Node* p) {
    while (p->left) p = p->left;
    return p;
}

Node* remove(Node* p, int key) {
    if (!p) return nullptr;
    if (key == p->key) {
        if (p->cnt > 1) {
            p->cnt--;
        } else {
            if (!p->left || !p->right) {
                Node* q = p->left ? p->left : p->right;
                delete p;
                return q;
            } else {
                Node* q = getMin(p->right);
                p->key = q->key;
                p->cnt = q->cnt;
                q->cnt = 1;
                p->right = remove(p->right, q->key);
            }
        }
    } else {
        if (key > p->key) {
            p->right = remove(p->right, key);
        } else {
            p->left = remove(p->left, key);
        }
    }

    update(p);
    return maintain(p);
}

int getRank(Node* p, int key) {
    if (!p) return 0;
    if (key == p->key) {
        return getSize(p->left);
    }
    if (key < p->key) {
        return getRank(p->left, key);
    }
    return getRank(p->right, key) + getSize(p->left) + p->cnt;
}

int getKth(Node* p, int k) {
    if (!p || k <= 0 || k > getSize(p)) return -1;
    if (k <= getSize(p->left)) {
        return getKth(p->left, k);
    }
    if (k <= getSize(p->left) + p->cnt) {
        return p->key;
    }

    return getKth(p->right, k - getSize(p->left) - p->cnt);
}

int getPre(Node* p, int key) {
    int ans = -inf;
    while (p) {
        if (p->key < key) {
            ans = p->key;
            p = p->right;
        } else {
            p = p->left;
        }
    }

    return ans;
}

int getPost(Node* p, int key) {
    int ans = inf;
    while (p) {
        if (p->key > key) {
            ans = p->key;
            p = p->left;
        } else {
            p = p->right;
        }
    }

    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
    int n;
    std::cin >> n;

    Node* root = nullptr;

    while (n--) {
        int op, x;
        std::cin >> op >> x;

        if (op == 1) {
            root = insert(root, x);
        } else if (op == 2) {
            root = remove(root, x);
        } else if (op == 3) {
            std::cout << getRank(root, x) + 1 << "\n";
        } else if (op == 4) {
            std::cout << getKth(root, x) << "\n";
        } else if (op == 5) {
            std::cout << getPre(root, x) << "\n";
        } else if (op == 6) {
            std::cout << getPost(root, x) << "\n";
        }
    }

    return 0;
}