#include<iostream>
#include<stack>

using namespace std;
void sortedindex(stack<int> &s,int key);
void sortstack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int top=s.top();
    s.pop();
    sortstack(s);
    sortedindex(s,top);
}

void sortedindex(stack<int> &s,int key)

{

    if (s.empty() || key>s.top()){
        s.push(key);
        return;
    }
    int top=s.top();
    s.pop();
    sortedindex(s,key);

    s.push(top);
}
void printstack(stack<int> &s)
{
    while(!s.empty()){

        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    }
int main()
{
    stack <int> s;
    s.push(30);
    s.push(10);
    s.push(50);
    s.push(20);
    s.push(40);

    printstack(s);
    s.push(30);
    s.push(10);
    s.push(50);
    s.push(20);
    s.push(40);
    sortstack(s);

    printstack(s);


    
}