#include<iostream>
#include"LinkStack.h"
using namespace std;
#define Max 50
int main(){
    //读入一串字符串，若遇到（则入栈，遇到)判断若为空则不合法，否则出栈
    cout<<"请输入:"<<endl;
    char ch[Max];
    cin>>ch;
    int i=0;
    LinkStack l;
    while(ch[i]!='\0'){
        if(ch[i]=='('){
            LinkStack::LinkNode node;
            node.ch=ch[i];
            l.push_in(node);
        }else if(ch[i]==')'){
            if(l.size==0){
                cout<<"不合法!"<<endl;
                exit(0);
            }
            else{
                l.pop_out();
            }
        }
        i++;
    }
    if(l.is_null()==true){
        cout<<"合法!"<<endl;
    }
    else{
        cout<<"不合法!"<<endl;
    }
}
