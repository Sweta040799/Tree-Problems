#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *left,*right;
};

Node* newNode(int item) 
{ 
    Node* temp = new Node(); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

Node* insert(Node* node, int data) 
{ 
    
    if (node == NULL) 
        return newNode(data); 
  
    
    if (data <= node->data) 
        node->left = insert(node->left, data); 
    else
        node->right = insert(node->right, data); 
  
   
    return node; 
} 

int minValue(Node* root){
	Node* current=root;
	
	while(current->left!=NULL){
		current=current->left;
	}
	
	return (current->data);
}

int main(){
	 Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    
    int t=minValue(root);
    cout<<t;
}
