struct tree{
	int val;
	tree *left, *right;
	tree(int value) : val(value), left(nullptr), right (nullptr){}
};
struct list{
	tree *tr;
	list *next;
	list(tree *x){
		tr = x;
		next = nullptr;
	}
};
class Queue{
	list *front, *rear;
public:
	Queue() {
		front = rear = nullptr;
	}
	bool empty(){
		return front == nullptr;
	}
	void push(tree *tr){
		list *newNode = new list(tr);
		// edge case : the queue was initially empty
		if(rear == nullptr){
			front = rear = newNode;
			return;
		}

		rear->next = newNode;
		rear = newNode;
	}
	tree* pop(){
		if(empty()){
			return nullptr;
		}
		list *temp = front;
		tree *dq = temp->tr;
		front = front->next;
		if(front == nullptr)
			rear == nullptr;
		delete temp;
		return dq;
	}
};

void BFS(TreeNode* root) {
    if(root == nullptr)
        return;

    Queue q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.pop();

        cout << curr->val << " ";

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }
}