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

    void postorder(Node* root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
   
    void find(Node *p,int x,bool& found){
        found=false;
        if(!p) return;
        if(p->data==x){
            found=true;
            return;
        }
        if(!found) find(p->left,x,found);
        if(!found) find(p->right,x,found);
    }
//kono ekta value khuje tar right e arekta value insert korte hole
    void searchAndInsert(Node* p,int target,int newVal,bool& found){
        find(p,target,found);
        if(found){
            if(p-right==NULL){
                p->right=new Node(newVal);
                cout<<"inserted"<<endl;
            }
            else {
                cout<<"replacing value"<<endl;
                p->right->data=newVal;
            }
            
            return;
        }
    }

};





int main(){
   Node* root=NULL;
   int n;cin>>n;
   if(n<=0){
    cout<<"invalid<<endl";
    return 0;
   }
    int rootData;cin>>rootData;
    root=new Node(rootData);
    for(int i=0;i<n-1;i++){
        int parentData;
        int childData;
        char direction;
        cout<<"enter parent data, child data and direction"<<endl;
        cin>>parentData>>childData;
        cin>>direction;
        Node* temp=root;
        while(temp){
            if(temp->data==parentData){
                if(direction=='L'){
                    temp->left=new Node(childData);
                } else {
                    temp->right=new Node(childData);
                }
                break;
            }
            else if(temp->left && temp->left->data==parentData){
                temp=temp->left;
            }
            else if(temp->right && temp->right->data==parentData){
                temp=temp->right;
            }
            else {
                cout<<"parent node not found"<<endl;
            }
        }
    }
    cout<<"preorder traversal"<<endl;
    root->preorder(root);
    cout<<endl;
    cout<<"inorder traversal"<<endl;
    root->inorder(root);    
    cout<<endl;
    cout<<"postorder traversal"<<endl;
    root->postorder(root);
    cout<<endl;

    int x;cin>>x;
    bool found=false;
    root->searchAndInsert(root,x,12,found);
    // if(found) cout<<"found"<<endl;
    // else cout<<"not found"<<endl;
    root->preorder(root);
    cout<<endl;

   return 0;
}