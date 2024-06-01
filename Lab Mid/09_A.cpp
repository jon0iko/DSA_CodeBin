//09
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct LinkedListNode{
        LinkedListNode *next;
        int val;
};

struct LinkedList{

    LinkedListNode *head=NULL;
    LinkedListNode *tail=NULL;

    void insert_last(int x)
    {
        //insert int x at last
        LinkedListNode* a=(LinkedListNode*)malloc(sizeof(LinkedListNode));
        a->next=NULL;
        a->val=x;
        if(tail)
        {
            tail->next=a;
            tail=a;
        }
        else
        {
            head=a;
            tail=a;
        }
    }

    void print()
    {
        LinkedListNode *p=head;
        while(p)
        {
            cout<<p->val<<endl;
            p=p->next;
        }
    }
};

struct LinkedListofLinkedListNode{
        LinkedListofLinkedListNode *next;
        LinkedList* list;
};

struct LinkedListofLinkedList{

    LinkedListofLinkedListNode *head=NULL;
    LinkedListofLinkedListNode *tail=NULL;

    void insert_last(LinkedList* x)
    {
        //insert LinkedList x at last
        LinkedListofLinkedListNode *a=(LinkedListofLinkedListNode*)malloc(sizeof(LinkedListofLinkedListNode));
        a->next=NULL;
        a->list=x;
        if(tail)
        {
            tail->next=a;
            tail=a;
        }
        else
        {
            head=a;
            tail=a;
        }
    }
};

LinkedList* sortLinkedListofLinkedList(LinkedListofLinkedList* lol){
    // You code starts here - 001
    LinkedList* new_list=new LinkedList();
    LinkedListofLinkedListNode* temp=lol->head;
    while(temp){
        if(new_list->head==NULL){
            new_list=temp->list;
            temp=temp->next;
            continue;
        }
        LinkedList* ans_list=new LinkedList();
        LinkedListNode* head1=new_list->head;
        LinkedListNode* head2=temp->list->head;
        while(head1||head2){
            if((head2==NULL)||(head1&&head1->val<head2->val)){
                ans_list->insert_last(head1->val);
                head1=head1->next;
            }
            else{
                ans_list->insert_last(head2->val);
                head2=head2->next;
            }
        }
        new_list=ans_list;
        temp=temp->next;
    }
    return new_list;
    // You code ends here - 001
}

int main() {
    
    int n, m, v;
    cin>>n;
    LinkedListofLinkedList* lol = new LinkedListofLinkedList();
    for(int i = 0;i<n;i++){
        LinkedList* l = new LinkedList();
        cin>>m;
        for(int j= 0;j<m;j++){
            cin>>v;
            l->insert_last(v);
        }
        lol->insert_last(l);
    }
    
    LinkedList* sorted = sortLinkedListofLinkedList(lol);

    sorted->print();
    


    return 0;
}

