#include<iostream>
#include<stack>
using namespace std;
void printStack(stack<char> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
   cout <<endl;
}
stack<char> copyStack(const stack<char>& original) {
    stack<char> copiedStack;
    stack<char> tempStack;

    tempStack = original;
    while (!tempStack.empty()) {
        copiedStack.push(tempStack.top());
        tempStack.pop();
    }
  // Return the copied stack
    return copiedStack;
}

void generate(stack<char>s, string word)
{

    stack<char>cp;
    if(s.size()==word.length())
    {
        printStack(s);
        return;
    }
    cp=copyStack(s);
    for(int i=0;i<word.length();i++)
    {
        cp.push(word[i]);
        generate(cp,word);
        cp.pop();
    }
}

int main()
{
    string s="abc";
    stack<char>e;
    generate(e,s);
}