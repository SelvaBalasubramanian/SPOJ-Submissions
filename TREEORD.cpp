#include<iostream>
using namespace std;

struct node{
	int data;
	node *left , *right;
};

node* newnode(int data){
	node *temp;
	temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int getIndex(int *inorder , int *preorder , int preIndex ,int start ,  int end){
	int i = start ;
	for( ; i<= end; i++){
		if(inorder[i] == preorder[preIndex]){break;}
	}

	return i;
}



node* buildTree( int *inorder , int *preorder , int start , int end  ){
	if(start > end)return NULL;
	node *root;
	static int preIndex = 0;
	int inIndex = getIndex(inorder ,preorder , preIndex , start , end);


	root = newnode(inorder[inIndex]);
			preIndex++;


	root->left = buildTree(inorder , preorder , start , inIndex-1 );
	root->right = buildTree(inorder , preorder  , inIndex+1 , end  );
		// cout<<root->data<<" "; //will print in post order
	return root;
}
void print(node *root){

	if(root == NULL)return ;
	else{
		cout<<root->data<<" ";
		print(root->left);
		print(root->right);
	}
}

bool isPostorder(node *root , int *postorder){
	static int i = 0;

	if(root == NULL) return true;

	if(isPostorder(root->left , postorder) && isPostorder(root->right , postorder)){
		if(root->data == postorder[i]){
			i++;
			return true;
		}
		else{
			return false;
		}
	}
	
	return false;

}
int main(){

	int n;
	scanf("%d",&n);
	int preorder[n]; 
	int inorder[n];
	int postorder[n];
	for(int i = 0; i< n;i++){
		scanf("%d",&preorder[i]);
	} 
	for(int i = 0; i< n;i++){
		scanf("%d",&postorder[i]);
	} 
	for(int i = 0; i< n;i++){
		scanf("%d",&inorder[i]);
	} 

	node *root ;
	root = NULL;
	int end = sizeof(inorder)/sizeof(int);
	// cout<<"before buildTree\n";

	root = buildTree(inorder , preorder , 0 , end-1);
	// cout<<endl;
	// print(root);
	if(isPostorder(root , postorder)){
		printf("yes\n");
	}
	else printf("no\n");

	return 0;
}