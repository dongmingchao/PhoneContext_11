/*
 * trie_tree.h
 *
 *  Created on: 2017年7月1日
 *      Author: dongmingchao
 */

#ifndef TRIE_TREE_H_
#define TRIE_TREE_H_

#include<iostream>
#include"node.h"
using std::endl;
using std::cin;
using std::cout;


//template <class T>
class trie {
private:

protected:
	struct tnode {
		char c;
		list<tnode*> value;
	};
public:
	tnode *root;
	trie() {
		root = new tnode;
		root->c = '#';
	}
	~trie() {

	}
	trie operator <<(char *in) {
		tnode *p = new tnode;
		list<tnode*> *table = &(root->value);
		list<tnode*>::node *head = table->head;
		while (head) {
			//cout << *(head->e->c);
			if (head->e->c == *in) {
				in++;
				if (*in == '\0') {
					cout << "find!";
					return *this;
				} else {
					table = &(head->e->value);
					head = table->head;
					continue;
				}
			}
			//else
			head = head->next;
		}
		p->c = *in;
		*table << p;
		return *this;
	}
	list<char> tree_level() { //层次遍历
		list<char> result;
		if (!root)
			return result;
		list<tnode*> table = root->value;
		list<tnode*> l;
		//先进入队列
		for (; table.head; table.head = table.head->next)
			l << table.head->e;
		do {
			//一个出队列
			result << l.head->e->c;
			//cout<<l.head->e->c<<'\t';
			table = l.head->e->value;
			//出队列的子树入队列
			if (table.head) {
				tnode *blank = new tnode;
				blank->c = '\n';
				l << blank;
			}
			for (; table.head; table.head = table.head->next)
				l << table.head->e;
			//判断队列是不是全部出完
			if (l.head->next) {
				l.head = l.head->next;
				table = l.head->e->value;
			} else
				return result;
		} while (l.head);
		return result;
	}

};

#endif /* TRIE_TREE_H_ */
