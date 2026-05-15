#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct tree{
	int val;
	tree *left, *right;
	tree(const int value) : val(value) , left(nullptr), right(nullptr){}
};
int get_num(const string s, int start, const int end){
	int ans = 0;
	while(start <= end){
		int digit = s[start] - '0';
		ans = ans*10 + digit;
		start++;
	}
	return ans;
}
tree* add_two_trees(tree *a, tree *b){
	if(!a) return b;
	if(!b) return a;
	tree *ans = new tree(a->val + b->val);
	ans->left = add_two_trees(a->left, b->left);
	ans->right = add_two_trees(a->right, b->right);
	return ans;
}
void preorder(tree *a){
	if(a == nullptr){
		return;
	}
	cout << a->val << ' ';
	preorder(a->left);
	preorder(a->right);
}
int main(){
	ifstream fin;
	fin.open("tree1.txt");
	string line;
	getline(fin, line);
	int root_value = get_num(line, 0, line.size() - 1);
	auto *tree1 = new tree(root_value);
	while(getline(fin, line)){
		size_t i = 0;
		auto *temp = tree1;

		while(i < line.size() && (line[i] == 'L' || line[i] == 'R')){
		    
		    if(i == line.size()-1 || isdigit(line[i+1])){

		        if(line[i] == 'L'){
		            temp->left = new tree(get_num(line, i+1, line.size()-1));
		        }
		        else{
		            temp->right = new tree(get_num(line, i+1, line.size()-1));
		        }

		        break;
		    }

		    if(line[i] == 'L'){
		        temp = temp->left;
		    }
		    else{
		        temp = temp->right;
		    }

		    ++i;
		}
	}
	fin.close();
	fin.open("tree2.txt");
	getline(fin, line);
	root_value= get_num(line, 0, line.size() - 1);
	auto *tree2 = new tree(root_value);
	while(getline(fin, line)){
		size_t i = 0;
		auto *temp = tree2;

		while(i < line.size() && (line[i] == 'L' || line[i] == 'R')){
		    
		    if(i == line.size()-1 || isdigit(line[i+1])){

		        if(line[i] == 'L'){
		            temp->left = new tree(get_num(line, i+1, line.size()-1));
		        }
		        else{
		            temp->right = new tree(get_num(line, i+1, line.size()-1));
		        }

		        break;
		    }

		    if(line[i] == 'L'){
		        temp = temp->left;
		    }
		    else{
		        temp = temp->right;
		    }

		    ++i;
		}
	}
	fin.close();
	auto *answer = add_two_trees(tree1, tree2);
	preorder(answer);

}
