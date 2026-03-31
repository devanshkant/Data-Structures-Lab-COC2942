#include<iostream>

using namespace std;
struct Node{
	int key;
	Node *left, *right;
	int height;
	Node(int value){
		key = value;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};
class avl{
	Node *root;
	int getHeight(Node *n){
		return n ? n->height : 0;
	}
	int getBalanceFactor(Node *n){
		return n? getHeight(n->left) - getHeight(n->right) : 0;
	}
    
    // RIGHT ROTATION (used in LL imbalance case)
	Node* rightRotate(Node *y){
	    // Step 1: Identify nodes
	    Node *x = y->left;        // x becomes new root of this subtree
	    Node *temp = x->right;    // temp subtree will be repositioned

	    // Step 2: Perform rotation
	    x->right = y;             // move y down to right of x
	    y->left = temp;           // attach temp as left child of y

	    // Step 3: Update heights (bottom-up)
	    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	    // Step 4: Return new root
	    return x;
	}
	
	// LEFT ROTATION (used in RR imbalance case)
	Node* leftRotate(Node *x){
	    // Step 1: Identify nodes
	    Node *y = x->right;       // y becomes new root of this subtree
	    Node *temp = y->left;     // temp subtree will be repositioned

	    // Step 2: Perform rotation
	    y->left = x;              // move x down to left of y
	    x->right = temp;          // attach temp as right child of x

	    // Step 3: Update heights (bottom-up)
	    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 
	    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	    // Step 4: Return new root
	    return y;
	}
	Node* insert(Node* n, int key){
		if(not n)
			return new Node(key);

		if(key < n->key)
			n->left = insert(n->left, key);
		else if(key > n->key)
			n->right = insert(n->right, key);
		else
			return n;
		n->height = 1 + max(getHeight(n->left), getHeight(n->right));

		int balance = getBalanceFactor(n);

		//LL
		if(balance > 1 and key < n->left->key)
			return rightRotate(n);

		//RR
		if(balance < -1 and key > n->right->key)
			return leftRotate(n);

		//LR
		if(balance > 1 and key > n->left->key){
			n->left = leftRotate(n->left);
			return rightRotate(n);
		}

		//RL
		if(balance < -1 and key < n->right->key){
			n->right = rightRotate(n->right);
			return leftRotate(n);
		}
		return n;
	}
	Node* minValueNode(Node *n){
		Node* current = n;
		while(current->left)
			current = current->left;
		return current;
	}
	Node* deleteNode(Node *root, int key){
		if(not root)
			return root;

		if(key < root->key)
			root->left = deleteNode(root->left, key);
		else if(key > root->key)
			root->right = deleteNode(root->right, key);
		else{
			if(not root->left or not root->right){
				Node *temp = root->left? root->left : root->right;
				if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
			}
			else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
		}
		if (!root) 
			return root;
		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
		int balance = getBalanceFactor(root);

		 // LL
        if (balance > 1 and getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        // LR
        if (balance > 1 and getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RR
        if (balance < -1 and getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        // RL
        if (balance < -1 and getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
	}
	void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
public: 
	avl(){
		root = nullptr;
	}
	void insert(int key){
		root = insert(root, key);
	}
	void deleteKey(int key){
		root = deleteNode(root, key);
	}
	void inorder(){
		inorder(root);
		cout  << endl;
	}
	void preorder(){
		preorder(root);
		cout << endl;
	}
};

int main(){
    avl tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    tree.inorder();

    return 0;
}