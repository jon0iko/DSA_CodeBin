#include<iostream>
#include<vector>
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


void inorder(Node* root,vector<int> &v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

int kthSmallest(Node* root, int k) {
    vector<int> v;
    inorder(root,v);
    return v[k-1];
}

//better approach

void solve(Node* root,int &cnt,int &ans,int k){
    if(root==NULL) return;
    solve(root->left,cnt,ans,k);
    cnt++;
    if(cnt==k){
        ans=root->data;
        return;
    }
    solve(root->right,cnt,ans,k);
}

int KTHSmallest(Node* root,int k){
    int cnt=0;
    int ans=-1;
    solve(root,cnt,ans,k);
    return ans;
}

int main(){
    Node* root=new Node(20);
    root->left=new Node(15);
    root->right=new Node(25);
    root->left->left=new Node(7);
    root->left->right=new Node(18);
    root->left->left->left=new Node(4);
    cout<<KTHSmallest(root,2)<<endl;

    // Node* root1=new Node(2);
    // root1->left=new Node(2);
    // root1->right=new Node(5);
    // root1->right->left=new Node(5);
    // root1->right->right=new Node(7);
    // cout<<KTHSmallest(root1,2)<<endl;
    return 0;
}
