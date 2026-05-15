#include<iostream>
#include<fstream>
using namespace std;

class MaxHeap {
private:
    int* data;
    int size;
    int capacity;

    static int parent(const int i) { return (i - 1) / 2; }
    static int leftChild(const int i) { return 2 * i + 1; }
    static int rightChild(const int i) { return 2 * i + 2; }

    static void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // MaxHeap comparison
    bool compare(int a, int b) {
        return a > b;
    }
    bool isLeaf(int i) {
        return leftChild(i) >= size && rightChild(i) >= size;
    }
    void heapifyUp(int index) {
        while (index > 0 && compare(data[index], data[parent(index)])) {
            swap(data[index], data[parent(index)]);
            index = parent(index);
        }
    }
    void printLeftBoundary(int i){
    	if(i >= size or isLeaf(i))
    		return;
    	cout << data[i] << ' ';

    	if(leftChild(i) < size)	
    		printLeftBoundary(leftChild(i));
    	else
    		printLeftBoundary(rightChild(i));
    }
    void printLeaves(int i){
    	if(i >= size)
    		return;
    	
    	printLeaves(leftChild(i));
    	
    	if(isLeaf(i))
    		cout << data[i] << ' ';

    	printLeaves(rightChild(i));
    }
    void printRightBoundary(int i){
	    if(i >= size || isLeaf(i))
	        return;

	    if(rightChild(i) < size)
	        printRightBoundary(rightChild(i));
	    else
	        printRightBoundary(leftChild(i));

	    cout << data[i] << ' ';
	}
public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    ~MaxHeap() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) return;
        data[size] = value;
        heapifyUp(size);
        size++;
    }

    int getSize() const {
        return size;
    }
    void inorder(int i = 0){
	    if(i >= size)
	        return;

	    inorder(leftChild(i));
	    cout << data[i] << ' ';
	    inorder(rightChild(i));
	}
    void preorder(int i = 0){
    	if(i >= size){
    		return;
    	}
    	cout << data[i] << ' ';
    	preorder(leftChild(i));
    	preorder(rightChild(i));
	    }
    void postorder(int i = 0){
    	if(i >= size){
    		return;
    	}
    	postorder(leftChild(i));
    	postorder(rightChild(i));
    	cout << data[i] << ' ';
    }
    //outer boundary elements
    void boundary(){
	    if(size == 0)
	        return;

	    cout << data[0] << ' ';

	    // left boundary
	    printLeftBoundary(leftChild(0));

	    // leaves
	    printLeaves(leftChild(0));
	    printLeaves(rightChild(0));

	    // right boundary
	    printRightBoundary(rightChild(0));

	    cout << '\n';
	}
	void printData(){
		for(int i = 0; i < size; ++i){
			cout << data[i] << ' ';
		}
	}
};	
int main(){
	ifstream fin;
	fin.open("input_lab7.txt");
	int num, n;
	fin >> n;
	MaxHeap h(n);
	while(fin >> num){
		h.insert(num);
	}
	cout << "Original Heap\n";
	h.printData();
	cout << '\n';
	h.inorder();
	cout << '\n';
	h.postorder();
	cout << '\n';
	h.preorder();
	cout << '\n';
	h.boundary();

}