#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){  //constructor
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    //val>root->data
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

void preorder(Node* root){
        if(!root) return;
        cout<<root->data<<" ";
        preorder(root->left);   
        preorder(root->right);
    }
void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

int main(){
    Node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        root=insertBST(root,val);
    }
    int key;cin>>key;
    insertBST(root,key);
    inorder(root);
    cout<<endl;


    return 0;
}