/*
 * main.cpp
 *
 *  Created on: 2017年7月1日
 *      Author: dongmingchao
 */
#include"trie_tree.h"
#include"node.h"
#include "order.h"
#include <string.h>
using tnode = trie::tnode;
void help() {
	cout << "通讯录系统" << endl;
	cout << "输入指令执行" << endl;
	cout << "exit     ---退出本系统" << endl; //1
	cout << "readfile ---读取文件" << endl; //2
	cout << "import   ---导入文件" << endl; //6
	cout << "build    ---输入方式建立通讯录" << endl; //4
	cout << "tree     ---展示当前树" << endl; //5
	cout << "save     ---保存成文件" << endl;
	cout << "help     ---显示此帮助" << endl; //3
	cout << "search   ---查找" << endl; //
}
int main() {
	trie now;
	help();
	do {
		list<char> order;
		while (1) {
			char ch = getchar();
			if (ch != '\n')
				order << ch;
			else
				break;
		};
		switch (check(order)) {
		case 1:
			return 0;
		case 2:
			cout << "正在读取文件";
			continue;
		case 3:
			help();
			continue;
		case 4: {
			cout << "输入姓名+电话号码，#结束，回车确认" << endl;
			while (1) {
				cout << ">>";
				char ch[100];
				scanf("%s", ch);
				char *name = strtok(ch, "+");
				char *phonenumber = strtok(NULL, "+");
				if (name[0] == '#')
					break;
				else {
					now.push(name, phonenumber);
				}
				now.treeprint();
				printf("%s", phonenumber);
				}
			continue;
		}
		case 5: {
				now.treeprint();
			list<tnode*> alist = now.tree_level();
			while (alist.head) {
				cout << alist.head->e->c << ':';
				if (alist.head->e->phone)
					printf("%s\n", alist.head->e->phone);
				alist.head = alist.head->next;
			}
			continue;
			}
		case 6: {
			list<char*> l;
			char filename[20];
			cout << "请输入文件名，不超过20个字符" << endl;
			cout << ">>";
			cin >> filename;
			l = importfile(filename);
			list<char*>::node *lhead = l.head;
			for (; lhead; lhead = lhead->next)
				printf("%s\r", lhead->e);
			lhead = l.head;
			/*
			while (lhead) {
				char *name = strtok(l.head->e, "+");
				char *phonenumber = strtok(NULL, "+");
				if (name[0] == '#')
					break;
				else {
					now.push(name, phonenumber);
				}
				lhead = lhead->next;
				printf("%s\n", phonenumber);
				}
			 now.treeprint();*/
			continue;
			}
		}
	} while (1);
	return 0;
}
