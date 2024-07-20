#include<iostream>

#include<stack>


using namespace std;


void reverse(stack<int> &s)
{

    if (s.empty())
    {
        return;
    }
    int top=s.top();
    s.pop();
    reverse(s);

    cout<<top<<" ";
    cout<<endl;
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
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    

    printstack(s);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    


    reverse(s);
}