#include <iostream>
#include <vector>
#include <algorithm>

class ScapegoatTree {
private:
	struct Node {
		int key;
		int cnt;
		int size;
		Node* left;
		Node* right;
		Node(int k) : key(k), cnt(1), size(1), left(nullptr), right(nullptr) {}
	};

	Node* root;
	double ALPHA;

	int getSize(Node* p) {
		return p ? p->size : 0;
	}

	void update(Node* p) {
		if (!p) return;
		p->size = p->cnt + getSize(p->left) + getSize(p->right);
	}

	bool isBalance(Node* p) {
		if (!p) return true;
		int lsz = getSize(p->left);
		int rsz = getSize(p->right);
		return (lsz <= ALPHA * p->size && rsz <= ALPHA * p->size);
	}

	void inorder(Node* p, std::vector<Node*>& nodes) {
		if (!p) return;
		inorder(p->left, nodes);
		if (p->cnt > 0) nodes.emplace_back(p);
		inorder(p->right, nodes);
	}

	Node* build(std::vector<Node*>& nodes, int l, int r) {
		if (l > r) return nullptr;
		int m = (l + r) >> 1;
		Node* n = nodes[m];
		n->left = build(nodes, l, m - 1);
		n->right = build(nodes, m + 1, r);

		update(n);
		return n;
	}

	Node* rebuild(Node* p) {
		std::vector<Node*> nodes;
		nodes.reserve(p->size);
		inorder(p, nodes);
		return build(nodes, 0, (int)nodes.size() - 1);
	}

	Node* insert(Node* p, int key, bool& needR) {
		if (!p) return new Node(key);
		if (key == p->key) {
			p->cnt++;
		} else if (key < p->key) {
			p->left = insert(p->left, key, needR);
		} else {
			p->right = insert(p->right, key, needR);
		}

		update(p);
		if (!isBalance(p)) needR = true;
		return p;
	}

	Node* erase(Node* p, int key, bool& needR) {
		if (!p) return nullptr;
		if (p->key == key) {
			if (p->cnt > 1) {
				p->cnt--;
			} else {
				if (!p->left || !p->right) {
					Node* tmp = p->left ? p->left : p->right;
					delete p;
					return tmp;
				} else {
					Node* succ = p->right;
					while (succ->left) succ = succ->left;
					p->key = succ->key;
					p->cnt = succ->cnt;
					succ->cnt = 1;
					p->right = erase(p->right, succ->key, needR);
				}
			}
		} else if (key < p->key) {
			p->left = erase(p->left, key, needR);
		} else {
			p->right = erase(p->right, key, needR);
		}

		update(p);
		if (!isBalance(p)) needR = true;
		return p;
	}

	int kth(Node* p, int k) {
		if (!p) return INT_MIN;
		int lsz = getSize(p->left);
		if (k <= lsz) return kth(p->left, k);
		else if (k > lsz + p->cnt) return kth(p->right, k - lsz - p->cnt);
		else return p->key;
	}

	int rankOf(Node* p, int key) {
		if (!p) return 0;
		if (key <= p->key) {
			return rankOf(p->left, key);
		} else {
			return getSize(p->left) + p->cnt + rankOf(p->right, key);
		}
	}

	int height(Node* p) {
		if (!p) return 0;
		int lh = height(p->left);
		int rh = height(p->right);
		return (lh > rh ? lh : rh) + 1;
	}

	void clear(Node* p) {
		if (!p) return;
		clear(p->left);
		clear(p->right);
		delete p;
	}

public:
	ScapegoatTree(double alpha = 0.7) : root(nullptr), ALPHA(alpha) {}

	~ScapegoatTree() {
		clear(root);
	}
	
	int rebuildtimes = 0;

	void insert(int key) {
		bool needR = false;
		root = insert(root, key, needR);
		if (needR) {
			root = rebuild(root);
			rebuildtimes++;
		}
	}

	int kth(int key) {
		return kth(root, key);
	}

	int rankOf(int key) {
		return rankOf(root, key) + 1;
	}

	int height() {
		return height(root);
	}
};

int main() {
	ScapegoatTree tree(0.7);
	int maxN = 10000;

	std::cout << "insert start!" << "\n";

	for (int i = 1; i <= maxN; i++) {
		tree.insert(i);
	}

    std::cout << "insert complete: 1~" << maxN << "\n";
    std::cout << "balance: 0.7\n";
    std::cout << "height: " << tree.height() << "\n";
    std::cout << "rebuildtimes " << tree.rebuildtimes << "\n";
    std::cout << "5000th: " << tree.kth(5000) << "\n";
    std::cout << "rankOf 6000: " << tree.rankOf(6000) << "\n";
    std::cout << "end!\n";
}