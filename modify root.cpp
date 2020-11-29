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

void RecurSumNode(Node* root,int *sum){
	
	if(root==NULL)
	 return;
	
	RecurSumNode(root->right,sum);
	
	*sum=*sum+root->data;
	root->data=*sum;
	
   	RecurSumNode(root->left,sum);	
} 

void SumNode(Node* root){
	int sum=0;
	RecurSumNode(root,&sum);
}

void inorder(Node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
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
    
    SumNode(root);
    
    inorder(root);
	
	return 0;
}
