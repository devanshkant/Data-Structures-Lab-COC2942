#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right, *parent;

    Node(int v) {
        val = v;
        left = right = parent = NULL;
    }
};

class MaxHeap {
    Node* root;
    int count;

    // Navigate to node using binary index
    Node* getNode(int index) {
        if (index == 1) return root;

        int path[32], top = 0;

        while (index > 0) {
            path[top++] = index % 2;
            index /= 2;
        }

        Node* curr = root;

        // skip MSB
        for (int i = top - 2; i >= 0; i--) {
            if (path[i] == 0)
                curr = curr->left;
            else
                curr = curr->right;
        }

        return curr;
    }

    void heapifyUp(Node* node) {
        while (node->parent && node->val > node->parent->val) {
            int temp = node->val;
            node->val = node->parent->val;
            node->parent->val = temp;
            node = node->parent;
        }
    }

    void heapifyDown(Node* node) {
        while (node) {
            Node* largest = node;

            if (node->left && node->left->val > largest->val)
                largest = node->left;

            if (node->right && node->right->val > largest->val)
                largest = node->right;

            if (largest == node) break;

            int temp = node->val;
            node->val = largest->val;
            largest->val = temp;

            node = largest;
        }
    }

public:
    MaxHeap() {
        root = NULL;
        count = 0;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (!root) {
            root = newNode;
            count = 1;
            return;
        }

        int idx = count + 1;
        Node* parent = getNode(idx / 2);

        newNode->parent = parent;

        if (!parent->left)
            parent->left = newNode;
        else
            parent->right = newNode;

        count++;

        heapifyUp(newNode);
    }

    int delRoot() {
        if (!root) {
            cout << "Heap empty\n";
            return -1;
        }

        int removed = root->val;

        if (count == 1) {
            delete root;
            root = NULL;
            count = 0;
            return removed;
        }

        Node* last = getNode(count);

        root->val = last->val;

        if (last->parent->left == last)
            last->parent->left = NULL;
        else
            last->parent->right = NULL;

        delete last;
        count--;

        heapifyDown(root);

        return removed;
    }

    void printLevelOrder() {
        if (!root) return;

        Node* queue[100];
        int front = 0, rear = 0;

        queue[rear++] = root;

        while (front < rear) {
            Node* curr = queue[front++];
            cout << curr->val << " ";

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    cout << "Heap: ";
    h.printLevelOrder();

    cout << "Deleted root: " << h.delRoot() << endl;

    cout << "After deletion: ";
    h.printLevelOrder();
}