//sort the items in queue is ascending order

#include <iostream>
using namespace std;

struct Queue
{

    struct node
    {
        node *next;
        int val;
    };
    node *head=NULL;
    node *tail=NULL;

    void enqueue(int x)
    {
        
        //Your code starts here #001
        node *a = (node *)malloc(sizeof(node));
        a->val = x;
        a->next = NULL;
        if (head == NULL)
        {
            head = tail = a;
            return;
        }
        tail->next = a;
        tail = a;
        
        //Your code ends here #001
    }

    int dequeue(){
        
        //Your code starts here #002
       if (head == NULL)
        {
            return -1;
        }
        int x = head->val;
        head = head->next;
        return x;
        
        //Your code ends here #002


    }

};

Queue* sortQueue(Queue* q){
    //Your code starts here #003
    Queue::node *tmp=q->head;
        while(tmp!=NULL){
            Queue::node* t2=q->head;
            while(t2!=NULL){
                if(t2->val>tmp->val){
                    swap(t2->val,tmp->val);
                }
                t2=t2->next;
            }
            tmp=tmp->next;
        }
        return q;
    //Your code ends here #003
}

int main()
{
    
    Queue* q = new Queue();
    int i, n;
    cin>>n;
    for(i=0; i<n; i++){
        int value;
        cin>>value;
        q->enqueue(value);
    }
    Queue* sq = sortQueue(q);
    for(i=0; i<n; i++){
        cout<<sq->dequeue()<<endl;
    }
    return 0;


}