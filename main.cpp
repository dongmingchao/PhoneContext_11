/*
 * main.cpp
 *
 *  Created on: 2017年7月1日
 *      Author: dongmingchao
 */
#include"trie_tree.h"
#include"node.h"
int main() {
	list<int> test;
	//TODO:test << 2 << 3 << 4;此时tail指向2
	test << 1;
	test << 5;
	test << 9;
	cout << test.pop();
	test.print();
	trie tree;
	char *c = "a";
	tree << c;
	tree.levelqueue().print();
	return 0;
}
