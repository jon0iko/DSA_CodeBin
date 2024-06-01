#include <iostream>

using namespace std;

const int Max_size = 100;

struct Stack
{
    int arr[Max_size];
    int top=-1;

    
    void push(int x)
    {
        if (top == Max_size - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top += 1;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
          //  cout << "empty stack" << endl;
            return -1;
        }
        int ans = arr[top];
        top--;
        return ans;
    }
    int peek()
    {
        if (top == -1)
        {
          //  cout << "empty" << endl;
            return -1;
        }
        return arr[top];
    }
    void print(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{ for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
        }
        cout<<endl;
    }
};


int main(){
    Stack s;
    s.push(5);
    s.push(6);
    s.push(3);
    s.pop();
   // s.peek();
    s.print();
    s.pop();
   // s.peek();
    s.print();
    s.pop();
   
    s.peek();
    s.print();



}