#include "pch.h"
#include "Stack.h"
#include<assert.h>
using namespace Algo;
namespace Algo {
	class Node
	{
	private:
		T* data;
		Node* next;
	public:
		friend class Stack;

	};
};
void Algo::Stack::push(T* E)
{
	Node* newNode = new Node();
	assert(newNode != 0);//débug
	//tru catch mode release 
	newNode->data=E;
	newNode->next = this->head;
	this->head = newNode;
}

void Algo::Stack::pop()
{
	assert(!this->empty());
	Node* supp = this->head;
	this->head = this->head->next;
	delete supp;
	supp = 0;
}

bool Algo::Stack::empty() const
{
	bool res = (this->head == 0);
	return res;
}

T* Algo::Stack::top() const
{
	assert(!this->empty());
	return this->head->data;
}
Stack* Algo::Stack::creator()
{
	Stack* S = new Stack();
	assert(S);
	return S;
}
void Algo::Stack::garbage(Stack* S)
{
	if(S)
	delete S;
}
 Stack::Stack()
{
	 this->head = 0;
}

 Algo::Stack::~Stack()
 {
	 while (this->head)
	 {
		 this->pop();
	 }
	// delete this->head;
	// this->head = 0;
 }
