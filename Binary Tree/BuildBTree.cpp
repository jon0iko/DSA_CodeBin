#include<iostream>
#include <algorithm>
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

int search(int inorder[],int st,int ed,int curr){
    for(int i=st;i<=ed;i++){
        if(inorder[i]==curr) 
            return i;
    }
    return -1;
}

Node* buildTreeFromPreAndIn(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    //base case
    if(start>end) return NULL;

    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){  //inorder e ektai element
         return node;
    }
    int pos=search(inorder,start,end,curr); // Fix: Add missing function declaration for 'search'
    node->left=buildTreeFromPreAndIn(preorder,inorder,start,pos-1);
    node->right=buildTreeFromPreAndIn(preorder,inorder,pos+1,end);
    return node;
}

Node* buildTreeFromPostAndIn(int postorder[],int inorder[],int start,int end){
    static int idx=end; //start from end
    //base case
    if(start>end) return NULL;
    int curr=postorder[idx];
    idx--;
    Node* node=new Node(curr);
    if(start==end){  //inorder e ektai element
         return node;
    }
    int pos=search(inorder,start,end,curr); // Fix: Add missing function declaration for 'search'
    node->right=buildTreeFromPostAndIn(postorder,inorder,pos+1,end);
    node->left=buildTreeFromPostAndIn(postorder,inorder,start,pos-1);
    return node;

}

void inorderPrint(Node* root){
    if(!root) return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int n;cin>>n;
    // int preorder[n];
    // for(int i=0;i<n;i++) cin>>preorder[i];
    int inorder[n];
    for(int i=0;i<n;i++) cin>>inorder[i];
    int postorder[n];
    for(int i=0;i<n;i++) cin>>postorder[i];
    
    Node* root=buildTreeFromPostAndIn(postorder,inorder,0,n-1);
    inorderPrint(root);

    return 0;
}