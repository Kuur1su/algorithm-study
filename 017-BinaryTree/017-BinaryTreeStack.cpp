#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v)
		: val(v), left(nullptr), right(nullptr)
	{}
};

void preOrder(TreeNode* head) {
	if (head) {
		vector<TreeNode*> stk;
		stk.emplace_back(head);
		while (!stk.empty()) {
			head = stk.back();
			stk.pop_back();
			cout << head->val << " ";
			if (head->right) stk.emplace_back(head->right);
			if (head->left) stk.emplace_back(head->left);
		}
		cout << "\n";
	}
}

void inOrder(TreeNode* head) {
	if (head) {
		vector<TreeNode*> stk;
		while (!stk.empty() || head) {
			if (head) {
				stk.emplace_back(head);
				head = head->left;
			} else {
				head = stk.back();
				stk.pop_back();
				cout << head->val << " ";
				head = head->right;
			}
		}
		cout << "\n";
	}
}

// 用两个栈实现后序遍历
void posOrderTraversalTwoStacks(TreeNode* head) {
	if (head) {
		vector<TreeNode*> stk;
		vector<TreeNode*> collect;
		stk.emplace_back(head);
		while (!stk.empty()) {
			head = stk.back();
			stk.pop_back();
			collect.emplace_back(head);
			if (head->left) stk.emplace_back(head->left);
			if (head->right) stk.emplace_back(head->right);
		}
		while (!collect.empty()) {
			cout << collect.back()->val << " ";
			collect.pop_back();
		}
		cout << "\n";
	}
}

// 用一个栈实现后序遍历
void posOrderTraversalOneStack(TreeNode* head) {
	if (head) {
		vector<TreeNode*> stk;
		stk.emplace_back(head);
		while (!stk.empty()) {
			TreeNode* cur = stk.back();
			if (cur->left && head != cur->left && head != cur->right) {
				stk.emplace_back(cur->left);
			} else if (cur->right && head != cur->right) {
				stk.emplace_back(cur->right);
			} else {
				cout << cur->val << " ";
				head = stk.back();
				stk.pop_back();
			}
		}
	}
}

void freeTree(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	freeTree(head->left);
	freeTree(head->right);
	delete head;	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    TreeNode* head = new TreeNode(1);
    head->left        = new TreeNode(2);
    head->right       = new TreeNode(3);
    head->left->left  = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left  = new TreeNode(6);
    head->right->right = new TreeNode(7);

    preOrder(head);
    cout << endl;
    cout << "先序遍历递归版" << endl;

    inOrder(head);
    cout << endl;
    cout << "中序遍历递归版" << endl;

    posOrderTraversalOneStack(head);
    cout << endl;
    cout << "后序遍历递归版" << endl;

    freeTree(head);

	return 0;
}