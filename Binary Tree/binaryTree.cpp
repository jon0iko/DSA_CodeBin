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

int main(){
     struct Node* root=new Node(1);
     root->left=new Node(2);
     root->right=new Node(3);

     root->left->left=new Node(4);
     root->left->right=new Node(5);

    return 0;
}