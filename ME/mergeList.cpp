#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int x){
        this->data=x;
        this->next;
    }
};


void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
}

Node* mergeTwoLLInSorted(Node* head1, Node* head2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            temp->next = head1;
            head1 = head1->next;
        }else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    while(head1 != NULL){
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }
    while(head2 != NULL){
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    head1->next->next->next->next = new Node(9);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(10);


    mergeTwoLLInSorted(head1, head2);

    printList(head1);
    return 0;
}