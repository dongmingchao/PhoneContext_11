/*
 * main.cpp
 *
 *  Created on: 2017年7月1日
 *      Author: dongmingchao
 */
#include"trie_tree.h"
#include"node.h"
int main() {

	trie tree;
	char *c = "a";
	tree << c;
	c = "b";
	tree << c;
	c = "ab";
	tree << c;
	c = "ac";
	tree << c;
	c = "abc";
	tree << c;
	tree.tree_level().print();
	return 0;
}
