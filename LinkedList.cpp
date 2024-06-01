#include <iostream>
using namespace std;

struct node 
{
    int val;
    node* next;
};

node* head=NULL;
node* tail=NULL;

void insert_first(int x){
    node* a=(node*)malloc(sizeof(node));
    a->val=x;
    a->next=NULL;
    if(head==NULL){
        head=a;
        tail=a;
    }
    else {
        a->next=head;
        head=a;
    }
}

void insert_last(int x){
    node* a=(node*)malloc(sizeof(node));
    a->val=x;
    a->next=NULL;
    if(tail){
        tail->next=a;
        tail=a;
    }
    else {
        head=a;
        tail=a;
    }
}

void print(){
    node* p=head;
    while(p){
        cout << p->val << " ";
        p=p->next;
    }
}

int delete_first() {
    if(head==NULL) return -1;
    if(head==tail) //ekta element
    {
        int x=head->val;
        free(head);
        head=NULL;
        tail=NULL;
        return x;
    }
    else {
        int x=head->val;
        node* tmp=head;
        head=head->next;
        free(tmp);
        return x;
    }
}

int delete_last(){
    if(head==NULL) return -1;
    if(head==tail){
        int x=head->val;
        free(head);
        head=NULL;
        tail=NULL;
        return x;
    }
    else {
        node* current=head;
        while(current->next!=tail){  //tail er ager tay jaite
                current=current->next;
        }
         int x=tail->val;
         current->next=NULL;
         free(tail);
         tail=current;
         return x;
    }
}


struct doublyNode{
    int val;
    doublyNode* next;
    doublyNode* prev;
}; 
doublyNode* h=NULL;
doublyNode* t=NULL;

void insert_FD(int x){
    doublyNode* a=(doublyNode*)malloc(sizeof(doublyNode));
    a->val=x;
    a->next=NULL;
    a->prev=NULL;
    if(head==NULL){
        h=a;
        t=a;
    }
    else {
        a->next=h;
        h->prev=a;
        h=h->prev;
    }
}

void insert_LD(int x){
    doublyNode* a=(doublyNode*)malloc(sizeof(doublyNode));
    a->val=x;
    a->next=NULL;
    a->prev=NULL;
    if(h==NULL){
        h=a;
        t=a;
    }
    else {
        a->prev=t;
        t->next=a;
        t=t->next;
    }
}

void print_DLL(){
    doublyNode* p=h;
    while(p){
        cout << p->val << " ";
        p=p->next;
    }
}

int del_FD(){
    if(h==NULL) return -1;
    else if(h->next==NULL){ //one element
        int x=h->val;
        free(h);
        h=NULL;
        t=NULL;
        return x;
    } 
    else  {  //more than 1 element
       int x=h->val;
       doublyNode* tbd=h;
       h=h->next;
       free(tbd);
       h->prev=NULL;
       return x;
    } 
}

 int del_LD(){
    if(h==NULL) return -1;
    else if(h->next==NULL){ //one element
        int x=h->val;
        free(h);
        h=NULL;
        t=NULL;
        return x;
    }
    else {
        int x=t->val;
        t=t->prev;
        free(t->next);
        t->next=NULL;
        return x;
    } 
 }

 struct CircularLL{
    int val;
    CircularLL* next;
 };

 CircularLL* hd=NULL;
 CircularLL* tl=NULL;

 void insertAtTail_Circ(int x){
      CircularLL* a=(CircularLL*)malloc(sizeof(CircularLL));
      a->val=x;
      a->next=NULL;
      if(hd==NULL){  //empty list
        hd=a;
        tl=a;
        tl->next=tl;  //creating link to itself
      }
      else {
        a->next=tl->next;
        tl->next=a;
        tl=a;
      }
 }

 void insertFront_Circ(int x){
    CircularLL* a=new (CircularLL);
    a->val=x;
    a->next=NULL;
    if(hd==NULL){  //empty list
        hd=a;
        tl=a;
        tl->next=tl;  //creating link to itself
    }
    else {
        a->next=hd;
        tl->next=a;
        hd=a;
    }
 }

 int delLast_Circ(){
    if(hd==NULL) return -1; //empty list
    else if(hd==tl) {
            free(hd);
            hd=NULL;
            tl=NULL;
            return -1;
    }
    else {
       CircularLL* tmp=hd;
       while(tmp->next!=tl){
        tmp=tmp->next;
       }
       tmp->next=tl->next;
       free(tl);
       tl=tmp;
       return 0;
    }
 }

int delFirst_Circ(){
    if(hd==NULL) return -1; //empty list
    else if(hd==tl) {
            free(hd);
            hd=NULL;
            tl=NULL;
            return -1;
    }
    else {
        CircularLL* tmp=hd;
        hd=hd->next;
        free(tmp);
        tl->next=hd;
        return 0;
    }
}
void print_circ(){
    CircularLL* tmp=hd;
    do{
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    while(tmp!=hd);
    cout<<endl;
}

int main(){
   int n,x;
   cin>>n;
   while(n--){
      cin>>x;
      insertAtTail_Circ(x);
   }
   print_circ();
   delFirst_Circ();
   print_circ();
   delLast_Circ();
   print_circ();
   return 0;
}



