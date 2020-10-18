//표준 라이브러리에서 제공하지 않는 기능이 필요할 때 사용한다.
//1. 서브트리 사이즈 계산
//2. insert
//3. erase (위들은 부가적인 기능)
//4. kth
//5. countLessThan

#ifndef TREAP_H
#define TREAP_H
#include <cmath>
#include <utility>

struct Node;
typedef int KeyType;
typedef std::pair<Node*, Node*> NodePair;


struct Node {
	KeyType key;
	int priority, size;
	Node * left, *right;

	Node(const KeyType& _key) : key(_key), priority(rand()),
		size(1), left(NULL), right(NULL) {}

	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }

	void calcSize() {
		size = 1;
		if (left)
			size += left->size;
		if (right)
			size += right->size;
	}

	NodePair split(Node* root, KeyType key){
		if (root == NULL)
			return NodePair(NULL, NULL);

		if (root->key < key) {
			NodePair rs = split(root->right, key);
			root->setRight(rs.first);
			return NodePair(root, rs.second);
		}

		NodePair ls = split(root->left, key);
		root->setLeft(ls.second);
		return NodePair(ls.first, root);	
	}

	//결과트립의 루트반환
	//사용 : root = insert (root, new Node(value));
	Node * insert(Node* root, Node * node) {
		if (root == NULL)
			return node;

		if (root->priority < node->priority) {
			NodePair splitted = split(root, node->key);
			node->setLeft(splitted.first);
			node->setRight(splitted.second);
			return node;
		}
		else if (node->key < root->key)
			root->setLeft(insert(root->left, node));
		else
			root->setRight(insert(root->right, node));
		return root;
	}

	//a,b가 둘다 트립이고, max(a) < min(n)일 때, 둘을 합친다.
	Node* merge(Node* a, Node * b) {
		if (a == NULL)
			return b;
		if (b == NULL)
			return a;

		if (a->priority < b->priority) {
			b->setLeft(merge(a, b->left));
			return b;
		}

		a->setRight(merge(a->right, b));
		return a;
	}

	//root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다.
	Node* erase(Node* root, KeyType key) {
		if (root == NULL)
			return root;
		if (root->key == key) {
			Node* ret = merge(root->left, root->right);
			delete root;
			return ret;
		}
		if (key < root->key)
			root->setLeft(erase(root->left, key));
		else
			root->setRight(erase(root->right, key));
		return root;
		
	}
	
	//root를 루트로 하는 트리 중에서 k번째 원소를 반환한다.
	Node* kth(Node* root, int k) {
		int leftSize = 0;
		if (root->left != NULL)
			leftSize = root -> left->size;
		if (k <= leftSize)
			return kth(root->left, k);
		if (k == leftSize + 1)
			return root;
		return kth(root->right, k - leftSize - 1);
	}

	//key보다 작은 키값의 수를 반환
	int countLessThan(Node* root, KeyType key) {
		if (root == NULL)
			return 0;
		if (root->key >= key)
			return countLessThan(root->left, key);
		
		int ls = (root->left ? root->left->size : 0);
		return ls + 1 + countLessThan(root->right, key);

	}



};
#endif