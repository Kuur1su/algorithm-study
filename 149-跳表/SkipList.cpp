#include <bits/stdc++.h>

struct Node {
	int key;
	int cnt;
	int level;
	std::vector<int> nxt;
	std::vector<int> len;

	Node(int maxL = 20) {
		key = 0;
		cnt = 0;
		level = 0;
		nxt.assign(maxL + 1, 0);
		len.assign(maxL + 1, 0);
	}
};

struct SkipList {
	static const int MAXL = 20;
	static const int MAXN = 100000;
	std::vector<Node> nodes;
	int cnt;

	SkipList() {
		nodes.resize(MAXN + 5, Node(MAXL));
		build();
	}

	void build() {
		cnt = 1;
		nodes[cnt].key = INT_MIN;
		nodes[cnt].level = MAXL;
	}

	int randomLevel() {
		int ans = 1;
		while ((double)rand() / RAND_MAX < 0.5 && ans < MAXL) ans++;
		return ans;
	}

	int find(int i, int h, int num) {
		while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < num) {
			i = nodes[i].nxt[h];
		}
		if (h == 1) {
			if (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key == num) {
				return nodes[i].nxt[h];
			} else return 0;
 		} else {
 			return find(i, h - 1, num);
 		}
	}

	void add(int num) {
		if (find(1, MAXL, num)) {
			addCount(1, MAXL, num);
		} else {
			++cnt;
			nodes[cnt].key = num;
			nodes[cnt].cnt = 1;
			nodes[cnt].level = randomLevel();
			addNode(1, MAXL, cnt);
		}
	}

	void addCount(int i, int h, int num) {
		while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < num) {
			i = nodes[i].nxt[h];
		}
		if (h == 1) {
			nodes[nodes[i].nxt[h]].cnt++;
		} else {
			addCount(i, h - 1, num);
		}
		nodes[i].len[h]++;
	}

	// important

	int addNode(int i, int h, int j) {
		int rightCnt = 0;
		while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < nodes[j].key) {
			rightCnt += nodes[i].len[h];
			i = nodes[i].nxt[h];
		}
		if (h == 1) {
			nodes[j].nxt[h] = nodes[i].nxt[h];
			nodes[i].nxt[h] = j;
			nodes[j].len[h] = nodes[nodes[j].nxt[h]].cnt;
			nodes[i].len[h] = nodes[nodes[i].nxt[h]].cnt;
			return rightCnt;
		} else {
			int downCnt = addNode(i, h - 1, j);
			if (h > nodes[j].level) {
				nodes[i].len[h]++;
			} else {
				nodes[j].nxt[h] = nodes[i].nxt[h];
				nodes[i].nxt[h] = j;
				nodes[j].len[h] = nodes[i].len[h] + 1 - downCnt - nodes[j].cnt;
				nodes[i].len[h] = downCnt + nodes[j].cnt;
			}
			return rightCnt + downCnt;
		}
	}

	void remove(int num) {
		int j = find(1, MAXL, num);
		if (j) {
			if (nodes[j].cnt > 1) {
				removeCount(1, MAXL, num);
			} else {
				removeNode(1, MAXL, j);
			}
		}
	}

	void removeCount(int i, int h, int num) {
		while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < num) {
			i = nodes[i].nxt[h];
		}
		if (h == 1) {
			nodes[nodes[i].nxt[h]].cnt--;
		} else {
			removeCount(i, h - 1, num);
		}
		nodes[i].len[h]--;
	}

	void removeNode(int i, int h, int j) {
		if (h >= 1) {
			while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < nodes[j].key) {
				i = nodes[i].nxt[h];
			}
			if (h > nodes[j].level) {
				nodes[i].len[h]--;
			} else {
				nodes[i].nxt[h] = nodes[j].nxt[h];
				nodes[i].len[h] += nodes[j].len[h] - 1;
			}
			removeNode(i, h - 1, j);
		}
	}

	int rank(int num) {
		return small(1, MAXL, num) + 1;
	}

	int small(int i, int h, int num) {
		int rightCnt = 0;
		while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < num) {
			rightCnt += nodes[i].len[h];
			i = nodes[i].nxt[h];
		}
		return h == 1 ? rightCnt : rightCnt + small(i, h - 1, num);
	}

	int index(int x) {
		return index(1, MAXL, x);
	} 

	int index(int i, int h, int x) {
		int c = 0;
		while (nodes[i].nxt[h] && c + nodes[i].len[h] < x) {
			c += nodes[i].len[h];
			i = nodes[i].nxt[h];
		}
		return h == 1 ? nodes[nodes[i].nxt[h]].key : index(i, h - 1, x - c);
	}

	int pre(int num) {
		return pre(1, MAXL, num);
	}

	int pre(int i, int h, int num) {
		while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < num) {
			i = nodes[i].nxt[h];
		}
		if (h == 1) {
			return i == 1 ? INT_MIN : nodes[i].key;
		} else {
			return pre(i, h - 1, num);
		}
	}

	int post(int num) {
		return post(1, MAXL, num);
	}

	int post(int i, int h, int num) {
		while (nodes[i].nxt[h] && nodes[nodes[i].nxt[h]].key < num) {
			i = nodes[i].nxt[h];
		}
		if (h == 1) {
			if (!nodes[i].nxt[h]) {
				return INT_MAX;
			} else if (nodes[nodes[i].nxt[h]].key > num) {
				return nodes[nodes[i].nxt[h]].key;
			} else {
				i = nodes[i].nxt[h];
				if (!nodes[i].nxt[h]) return INT_MAX;
				else {
					return nodes[nodes[i].nxt[h]].key;
				}
			}
		} else {
			return post(i, h - 1, num);
		}
	}
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    SkipList sl;
    int n;
    std::cin >> n;
    while (n--) {
        int op, x;
        std::cin >> op >> x;
        if (op == 1) sl.add(x);
        else if (op == 2) sl.remove(x);
        else if (op == 3) std::cout << sl.rank(x) << "\n";
        else if (op == 4) std::cout << sl.index(x) << "\n";
        else if (op == 5) std::cout << sl.pre(x) << "\n";
        else std::cout << sl.post(x) << "\n";
    }
    return 0;
}