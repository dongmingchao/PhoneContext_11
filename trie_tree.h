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
		char *c;
		list<tnode*> value;
	};
	tnode *root;
public:
	trie() {
		root = new tnode;
		root->c = NULL;
	}
	~trie() {

	}
	trie operator <<(char *in) {
		tnode *p = new tnode;
		p->c = in;
		list<tnode*> table = root->value;
		while (table.head) {
			if (*table.head->e->c == *in) {
				in++;
				if (in == '\0') {
					cout << "find!";
					return *this;
				} else {
					table = table.head->e->value;
					continue;
				}
			}
			table.head = table.head->next;
		}
		table << p;
		return *this;
	}
	list<tnode*> levelqueue() {
		list<tnode*> level;
		level = root->value;
		list<tnode*> *table = &level;
		while (table->head) {
			*table << table->head->e;
			table->head = table->head->next;
		}
		return level;
	}
};

#endif /* TRIE_TREE_H_ */
