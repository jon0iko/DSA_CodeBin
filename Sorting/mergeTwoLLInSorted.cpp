#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

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

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main(){
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);
    head1->next->next->next->next = new Node(50);
    head1->next->next->next->next->next = new Node(60);

    Node* head2 = new Node(15);
    head2->next = new Node(25);
    head2->next->next = new Node(35);
    head2->next->next->next = new Node(45);
    head2->next->next->next->next = new Node(55);
    head2->next->next->next->next->next = new Node(65);

    Node* head = mergeTwoLLInSorted(head1, head2);
    printList(head);
    return 0;
}