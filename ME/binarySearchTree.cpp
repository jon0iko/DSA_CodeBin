#include <bits/stdc++.h>
using namespace std;


struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void printPreOrder(node* node)
{
    if (node == NULL)
        return;
 
    cout << node->key << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}


void printInOrder(node* node)
{
    if (node == NULL)
        return;

    printInOrder(node->left);
    cout << node->key << " ";
    printInOrder(node->right);
}

void printPostOrder(node* node)
{
    if (node == NULL)
        return;

    printPreOrder(node->left);
    printPreOrder(node->right);
    cout << node->key << " ";
}


struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
 
    if (root->key < key)
        return search(root->right, key);
 
    return search(root->left, key);
}


struct node* deleteNode(struct node* root, int k) {
    if (root == NULL)
        return root;

    if (k < root->key) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (k > root->key) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    if (root->left == NULL) {
        struct node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct node* temp = root->left;
        free(root);
        return temp;
    }

    struct node* succParent = root;
    struct node* succ = root->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    root->key = succ->key;

    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;
    free(succ);
    return root;


    // inorder predecessor
    // struct node* predParent = root;
    // struct node* pred = root->left;
    // while (pred->right != NULL) {
    //     predParent = pred;
    //     pred = pred->right;
    // }
    // root->key = pred->key;

    // if (predParent->right == pred)
    //     predParent->right = pred->left;
    // else
    //     predParent->left = pred->left;

    // free(pred);
}


int main()
{

	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// printInOrder(root);
    // deleteNode(root, 60);
    // cout<<endl;
    // printInOrder(root);
    // cout<<endl;
    // search(root, 40) ? cout << "Yes" : cout << "No";

    printPreOrder(root);

	return 0;
}
