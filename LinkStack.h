#pragma once
#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
class LinkStack{
public:
    struct LinkNode
    {
        char ch;
        LinkNode *next;
        LinkNode():next(nullptr){}
    };
    
    LinkNode *head;
    int size;
    
    LinkStack(){
        head=new LinkNode;
        size=0;
    }

    void push_in(const LinkNode &node){
        LinkNode *new_node=new LinkNode;
        new_node->ch=node.ch;
        new_node->next=head->next;
        head->next=new_node;
        size++;
    }

    const LinkNode* get_top(){
        return head->next;
    }

    void pop_out(){
        if(size==0){
            cout<<"已经为空！"<<endl;
            return ;
        }
        LinkNode *pop_node=head->next;
        head->next=head->next->next;
        delete pop_node;
        size--;
    }

    bool is_null(){
        return head->next==nullptr;
    }
    ~LinkStack(){
        LinkNode *tool=head;
        while(tool!=nullptr){
            LinkNode *toolnext=tool->next;
            delete tool;
            tool=toolnext;
        }
    }


};
