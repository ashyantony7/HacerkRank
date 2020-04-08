#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    // insertion works recursively untill an empty spot is found
    Node * insert(Node * root, int data) {

        if (root==NULL){
            return new Node(data);
        }else{

            // create a new node
            Node* curr_node;

            // if data is less go left
            if (root->data > data){
                curr_node=insert(root->left, data);
                root->left = curr_node;
            }else{ // go right
                curr_node=insert(root->right, data);
                root->right = curr_node;
            }

            return root;
        }
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}