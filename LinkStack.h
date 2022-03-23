#pragma once
#include<iostream>
using namespace std;

typedef struct node
{
	char num;
	node* next;
	node* last;
}Node;

class LinkStack
{
	Node*pop;
public:
	LinkStack();
	bool Push(char num);
	bool Pop(char&num);
	char GetTop();
	void Distory();
	bool Empty();
	void display();
};

LinkStack::LinkStack()
{
	pop = NULL;
}

bool LinkStack::Push(char num)
{
	Node* temp = new Node;
	temp->num = num;
	temp->next = NULL;
	temp->last = pop;
	if (pop != NULL)
	{
		pop->next = temp;
	}
	pop = temp;
	return true;
}

bool LinkStack::Pop(char&num)
{
	if (pop == NULL)
		return false;
	Node* tem = pop;
	num = tem->num;
	pop = pop->last;
	if (pop != NULL)
		pop->next = NULL;
	delete tem;
	return true;
}

char LinkStack::GetTop()
{
	return pop->num;
}

void LinkStack::Distory()
{
	char num;
	Node* tem = pop;
	while (pop != NULL)
	{
		tem = pop;
		pop = pop->last;
		delete tem;
	}
}

bool LinkStack::Empty()
{
	if (pop == NULL)
		return true;
	else
		return false;
}

void LinkStack::display()
{
	Node* tem = pop;
	while (tem != NULL)
	{
		cout << tem->num << " ";
		tem = tem->last;
	}
	cout << endl;
}