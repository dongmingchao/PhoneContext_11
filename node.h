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
using std::endl;
template<class T>
class list {
protected:

public:
	struct node {
		T e;
		node *next;
		node *front;
	};
	node *head;
	node *tail;
	list() {
		head = NULL;
		tail = NULL;
	}
	list operator <<(T in) { //TODO:队列 << 2 << 3 << 4;此时tail指向2
		node *p = new node;
		p->e = in;
		p->next = NULL;
		if (!head) {
			p->front = NULL;
			head = p;
		} else {
			p->front = tail;
			if (tail)
				tail->next = p;
		}
		tail = p;
		return *this;
	}
	list operator >>(T &out) {
		out = head->e;
		node *p = head;
		head = head->next;
		head->front = NULL;
		delete (p);
		return *this;
	}
	T pop() {
		node *temp = tail;
		T res = temp->e;
		tail = tail->front;
		if (tail)
			tail->next = NULL;
		else
			head = NULL;
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
	void tofile(char *filename) {
		node *l = head;
		FILE *f;
		if (!(f = fopen(filename, "wb")))
			cout << "文件创建错误" << endl;
		else {
			while (l) {
				fwrite(l, sizeof(node), 1, f);
				l = l->next;
			}
			fclose(f);
		}
	}
	void readfile(char *filename) {
		FILE *f;
		if (!(f = fopen(filename, "rb")))
			cout << "文件读取错误" << endl;
		else {
			while (!feof(f)) {
				node *p = new node;
				fread(p, sizeof(node), 1, f);
				*this << p;
			}
			fclose(f);
		}
	}
	bool operator ==(list<T> input) {
		node *l = head;
		node *order = input.head;
		while (l) {
			if (l->e != order->e)
				return 0;
			l = l->next;
			order = order->next;
		}
		if (order)
			return 0;
		return 1;
	}
	~list() {

	}
};


#endif /* NODE_H_ */
