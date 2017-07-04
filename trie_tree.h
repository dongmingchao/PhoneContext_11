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
#include<math.h>
using std::endl;
using std::cin;
using std::cout;


//template <class T>
class trie {
private:

protected:

public:
	struct tnode {
		char c;
		char *phone;
		int linelevel;
		tnode *parent;
		list<tnode*> value;
	};
	tnode *root;
	int depth;
	trie() {
		root = new tnode;
		root->c = '#';
		root->parent = NULL;
		root->linelevel = 0;
		depth = 0;
	}
	~trie() {

	}
	trie push(char *in, char *phone) {
		tnode *par = root;
		list<tnode*> *table = &(par->value);
		list<tnode*>::node *head = table->head;
		while (head) {
			if (head->e->c == *in) {
				in++;
				if (*in == '\0') {
					cout << "find!";
					return *this;
				} else {
					head->e->parent = par;
					par = head->e;
					table = &(par->value);
					head = table->head;
					continue;
				}
			}
			//else
			head = head->next;
		}
		//叶子节点配置
		//不止一个新节点的加入
		while (*in != '\0') {
			tnode *p = new tnode;
			p->c = *in;
			if (in[1] == '\0')
				p->phone = phone;
			else
				p->phone = NULL;
			p->parent = par;
			p->linelevel = par->linelevel + 1;
			*table << p;
			par = p;
			table = &(par->value);
			in++;
			if (p->linelevel > depth)
				depth = p->linelevel;
		}
		return *this;
	}
	list<tnode*> tree_level() { //层次遍历
		list<tnode*> l;
		if (!root)
			return l;
		list<tnode*> table = root->value;
		//先进入队列
		for (; table.head; table.head = table.head->next)
			l << table.head->e;
		list<tnode*>::node *lhead = l.head;
		do {
			//一个出队列
			table = lhead->e->value;
			//出队列的子树入队列
			for (; table.head; table.head = table.head->next)
				l << table.head->e;
			//判断队列是不是全部出完
			if (lhead->next) {
				lhead = lhead->next;
				table = lhead->e->value;
			} else
				return l;
		} while (lhead);
		return l;
	}
	int NumOfMaxson() {
		list<tnode*> in = tree_level();
		int result = 0;
		while (in.head) {
			int now = 0;
			list<tnode*> table = in.head->e->value;
			while (table.head) {
				table.head = table.head->next;
				now++;
			}
			if (now > result)
				result = now;
			in.head = in.head->next;
		}
		return result;
	}
	void treeprint() {
		list<tnode*> table;
		list<tnode*> par;
		par << root;
		table = par.pop()->value;
		while (table.head) {
			par << table.head->e;
			table.head = table.head->next;
		}
		while (par.head) {
			table.head = par.tail;
			while (table.head) {
				if (table.head->e->linelevel > 1)
					cout << '|';
				if (table.head->e->linelevel > 2) {
					for (int i = table.head->e->linelevel - 2; i; i--)
						cout << ' ';
					cout << '|';
				}
				if (table.head->e->linelevel > 1) {
					cout << endl;
				}
				if (table.head->e->linelevel > 1)
					cout << '|';
				if (table.head->e->linelevel > 2)
					for (int i = table.head->e->linelevel - 2; i; i--)
						cout << ' ';
				if (table.head->e->linelevel > 1)
					cout << '-';
				cout << table.head->e->c << endl;
				table.head = table.head->next;
			}
			table = par.pop()->value;
			while (table.head) {
				par << table.head->e;
				table.head = table.head->next;
			}
		}
	}
};

#endif /* TRIE_TREE_H_ */
