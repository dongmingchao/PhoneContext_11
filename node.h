/*
 * node.h
 *
 *  Created on: 2017年7月1日
 *      Author: dongmingchao
 */

#ifndef NODE_H_
#define NODE_H_
#include<iostream>
using std::cout;
template<class T>
class list {
protected:
	struct node {
		T e;
		node *next;
		node *front;
	};
public:
	node *head;
	node *tail;
	list() {
		head = NULL;
		tail = NULL;
	}
	list operator <<(T in) {
		node *p = new node;
		p->e = in;
		p->next = NULL;
		if (!head) {
			p->front = NULL;
			head = p;
		} else {
			p->front = tail;
			tail->next = p;
		}
		tail = p;
		return *this;
	}
	list operator >>(T &out) {
		out = head->e;
		head = head->next;
		return *this;
	}
	T pop() {
		node *temp = tail;
		T res = temp->e;
		tail = tail->front;
		tail->next = NULL;
		delete (temp);
		return res;
	}
	void print() {
		if (!head)
			return;
		for (node *i = head; i; i = i->next)
			cout << i->e;
	}

	void findtail() {
		node *i = head;
		for (; i->next; i = i->next)
			;
		tail = i;
	}
	~list() {

	}
};


#endif /* NODE_H_ */
