#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// 类方法实现前缀树
class Trie {
private:
    class TrieNode {
    public:
        int pass;
        int end;
        vector<TrieNode*> nexts;

        TrieNode() : pass(0), end(0), nexts(26, nullptr) {}
        ~TrieNode() {
            for (auto node : nexts) {
                if (node) delete node;
            }
        }
    };

    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}
    ~Trie() {
        delete root;
    }

    void insert(string word) {
        TrieNode* node = root;
        node->pass++;
        for (char c : word) {
            int path = c - 'a';
            if (!node->nexts[path]) {
                node->nexts[path] = new TrieNode();
            }
            node = node->nexts[path];
            node->pass++;
        }
        node->end++;
    }

    void erase(string word) {
        if (countWordsEqualTo(word) > 0) {
            TrieNode* node = root;
            node->pass--;
            for (char c : word) {
                int path = c - 'a';
                TrieNode* next = node->nexts[path];
                if (--next->pass == 0) {
                    node->nexts[path] = nullptr;
                    delete next;
                    return;
                }
                node = next;
            }
            node->end--;
        }
    }

    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int path = c - 'a';
            if (!node->nexts[path]) return 0;
            node = node->nexts[path];
        }
        return node->pass;
    }
};

// 哈希表实现-动态子节点
class Trie2 {
private:
    class TrieNode {
    public:
        int pass;
        int end;
        unordered_map<int, TrieNode*> nexts; // 用哈希表

        TrieNode() : pass(0), end(0) {}
        ~TrieNode() {
            for (auto& [key, node] : nexts) {
                if (node) delete node;
            }
        }
    };

    TrieNode* root;

public:
    Trie2() : root(new TrieNode()) {}
    ~Trie2() {
        delete root;
    }

    void insert(string word) {
        TrieNode* node = root;
        node->pass++;
        for (char c : word) {
            int path = static_cast<int>(c);
            if (!node->nexts.count(path)) {
                node->nexts[path] = new TrieNode();
            }
            node = node->nexts[path];
            node->pass++;
        }
        node->end++;
    }

    void erase(string word) {
        if (countWordsEqualTo(word) > 0) {
            TrieNode* node = root;
            node->pass--;
            for (char c : word) {
                int path = static_cast<int>(c);
                TrieNode* next = node->nexts[path];
                if (--next->pass == 0) {
                    node->nexts.erase(path);
                    delete next;
                    return;
                }
                node = next;
            }
            node->end--;
        }
    }

    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int path = static_cast<int>(c);
            if (!node->nexts.count(path)) return 0;
            node = node->nexts[path];
        }
        return node->end;
    }

    int countWordsStartingWith(string pre) {
        TrieNode* node = root;
        for (char c : pre) {
            int path = static_cast<int>(c);
            if (!node->nexts.count(path)) return 0;
            node = node->nexts[path];
        }
        return node->pass;
    }
};

void solve() {

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
