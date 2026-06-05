#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

struct Node {
	int key, priority;
	Node* left;
	Node* right;
	Node(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

class Treap {
private:
	Node* root;

	Node* rightRotate(Node* y) {
		Node* x = y->left;
		y->left = x->right;
		x->right = y;
		return x;
	}

	Node* leftRotate(Node* x) {
		Node* y = x->right;
		x->right = y->left;
		y->left = x;
		return y;
	}

	Node* insert(Node* p, int key) {
		if (!p) return new Node(key);

		if (key < p->key) {
			p->left = insert(p->left, key);
			if (p->left->priority < p->priority) {
				p = leftRotate(p);
			}
		} else if (key > p->key) {
			p->right = insert(p->right, key);
			if (p->right->priority < p->priority) {
				p = leftRotate(p);
			}
		}

		return p;
	}

	Node* erase(Node* p, int key) {
		if (!p) return p;

		if (key < p->key) {
			p->left = erase(p->left, key);
		} else if (key > p->key) {
			p->right = erase(p->right, key);
		} else {
			if (!p->left || !p->right) {
				Node* tmp = (p->left ? p->left : p->right);
				delete p;
				return tmp;
			} else {
				if (p->left->priority < p->right->priority) {
					p = rightRotate(p);
					p->right = erase(p->right, key);																															
				} else {
					p = leftRotate(p);
					p->left = erase(p->left, key);
				}
			}
		}
		return p;
	}

	bool search(Node* p, int key) {
		if (!p) return false;

		if (key == p->key) {
			return true;
		} else if (key < p->key) {
			return search(p->left, key);
		} else {
			return search(p->right, key);
		}
	}

	void inorder(Node* p) {
		if (!p) return;
		inorder(p->left);
		std::cout << p->key << " ";
		inorder(p->right);
	}

public:
	Treap() : root(nullptr) {
		srand(time(0));
	}

	void insert(int key) {
		root = insert(root, key);
	}

	void erase(int key) {
		root = erase(root, key);
	}

	bool search(int key) {
		return search(root, key);
	}

	void inorder() {
		inorder(root);
		std::cout << "\n";
	}
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Treap treap;

    int n, q;
    std::cin >> n >> q;

    while (q--) {
    	int op, x;
    	std::cin >> op >> x;

    	if (op == 1) {
    		treap.insert(x);
    	} else if (op == 2) {
    		treap.erase(x);
    	} else if (op == 3) {
    		std::cerr << 1 << "\n";
    		std::cout << (treap.search(x) ? "Yes\n" : "No\n");
    	} else {
    		std::cerr << 1 << "\n";
    		treap.inorder();
    	}
    }

    return 0;
}