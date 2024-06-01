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

  
};




Node* searchInBST(Node* root,int key){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }

    //data>key
    if(root->data>key){
        return searchInBST(root->left,key);
    }
    //data<key
    if(root->data<key){
        return searchInBST(root->right,key);
    }
}

Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

//delete in bst
Node* deleteInBST(Node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteInBST(root->right,key);
    }

    //key==root->data
    else{
        //one child or no child
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        //right child is null
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        //two children
        Node* temp=inorderSucc(root->right); //temp e minimum value node stored or inorder successor
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}

void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }


int main(){
    // Node* root=NULL;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int val;
    //     cin>>val;
    //     root=root->insertBST(root,val);
    // }
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    inorder(root);
    cout<<endl;
    int key;cin>>key;
    // if(searchInBST(root,key)==NULL){
    //     cout<<"Key doesn't exist"<<endl;
    // }
    // else{
    //     cout<<"Key exists"<<endl;
    // }
    root=deleteInBST(root,key);
    inorder(root);
    cout<<endl;


    return 0;
}