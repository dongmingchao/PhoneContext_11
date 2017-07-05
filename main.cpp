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
	cout << "help     ---显示此帮助" << endl; //3
	cout << "build    ---输入方式建立通讯录" << endl; //4
	cout << "tree     ---展示当前树" << endl; //5
	cout << "import   ---导入文件" << endl; //6
	cout << "search   ---查找" << endl; //7
	cout << "delete   ---删除" << endl; //8
	cout << "save     ---保存成文件" << endl; //9
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
		case 2: {
			cout << "输入文件名(长度<20):";
			char filename[21];
			list<tnode*> alist;
			cin >> filename;
			alist.readfile(filename);
			while (alist.head) {
				tnode *temp = new tnode;
				alist >> temp;
				if (!temp)
					break;
				now.push(temp->name, temp->phone);
			}
			continue;
		}
		case 3:
			help();
			continue;
		case 4: {
			cout << "输入姓名+电话号码，#结束，回车确认" << endl;
				cout << ">>";
			while (1) {
				char ch = getchar();
				if (ch == '#')
					break;
				else {
					list<char> str;
					list<char> name;
					list<char> phonenumber;
					while (ch != '\n') {
						str << ch;
						ch = getchar();
					}
					name = str.split('+');
					str.queue_pop();
					phonenumber = str;
					now.push(name, phonenumber);
					now.treeprint();
					phonenumber.print();
					cout << "\n>>";
				}
				}
			continue;
		}
		case 5: {
				now.treeprint();
			continue;
		}
		case 6: {
			list<list<char>> l;
			char filename[20];
			cout << "请输入文件名，不超过20个字符" << endl;
			cout << ">>";
			cin >> filename;
			l = importfile(filename);
			list<list<char>>::node *lhead = l.head;
			for (lhead = l.head; lhead; lhead = lhead->next) {
				list<char> name = lhead->e.split('+');
				lhead->e.queue_pop(); //丢掉+
				list<char> phonenumber = lhead->e.split('+');
				now.push(name, phonenumber);
				}
				now.treeprint();
			continue;
			}
		case 7: {
			cout << "请输入要查找的姓名,#退出" << endl;
			cout << ">>";
			while (1) {
				char ch = getchar();
				if (ch == '#')
					break;
				else {
					list<char> ask;
					while (ch != '\n') {
						ask << ch;
						ch = getchar();
					}
					//list<char> phone;//根据phone查找？
					list<char>::node *ask_list = ask.head;
					list<tnode*> orgin = now.tree_level();
					list<tnode*>::node *orgin_list = orgin.head;
					list<tnode> result;
					trie target;
					while (orgin_list) {
						if (orgin_list->e->c == ask_list->e) {
							target.root->value << orgin_list->e;
						}
						if (!orgin_list->next) {
							orgin = target.tree_level();
							orgin_list = orgin.head;
							ask_list = ask_list->next;
							if (!ask_list) {
								while (orgin.head) {
									if (orgin.head->e->name.head) { //	收集结果
										result << *orgin.head->e;
									}
									orgin.head = orgin.head->next;
								} //
								break;
							}
							target = *new trie;
							target.root->value = *new list<tnode*>;
							continue;
						} else {
							orgin_list = orgin_list->next;
						}
					}
					if (!result.head) {
						cout << "查无此人，是否添加？(y/n):";
						char how = getchar();
						if (how == 'y' || how == 'Y') {
							cout << "请补充手机号码:";
							list<char> phonenumber;
							while ((how = getchar()) != '\n')
								phonenumber << how;
							now.push(ask, phonenumber);
						}
						getchar();
					} else
						while (result.head) {
							result.head->e.name.print();
							cout << "\t手机号码:";
							result.head->e.phone.print();
							cout << endl;
							result.head = result.head->next;
						}
					cout << "\n>>";
				}
			}
			continue;
			}
		case 8: {
			cout << "请输入要删除的姓名,#退出" << endl;
			cout << ">>";
			while (1) {
				char ch = getchar();
				if (ch == '#')
					break;
				else {
					list<char> ask;
					while (ch != '\n') {
						ask << ch;
						ch = getchar();
					}
					list<char>::node *ask_list = ask.head;
					list<tnode*> orgin = now.tree_level();
					list<tnode*>::node *orgin_list = orgin.head;
					list<tnode*> result;
					trie target;
					while (orgin_list) {
						if (orgin_list->e->c == ask_list->e) {
							target.root->value << orgin_list->e;
						}
						if (!orgin_list->next) {
							orgin = target.tree_level();
							orgin_list = orgin.head;
							ask_list = ask_list->next;
							if (!ask_list) {
								while (orgin.head) {
									if (orgin.head->e->name.head) { //	收集结果
										result << orgin.head->e;
									}
									orgin.head = orgin.head->next;
								} //
								break;
							}
							target = *new trie;
							target.root->value = *new list<tnode*>;
							continue;
						} else {
							orgin_list = orgin_list->next;
						}
					}
					if (!result.head) {
						cout << "查无此人";
					} else
						while (result.head) {
							result.head->e->name.print();
							cout << "\t手机号码:";
							result.head->e->phone.print();
							cout << endl;
							cout << "是否删除？(y/n):";
							char how = getchar();
							if (how == 'y' || how == 'Y') {
								result.head->e->name.head = NULL;
								cout << "已删除" << endl;
							}
							getchar();
							result.head = result.head->next;
						}
					cout << "\n>>";
				}
				}
			continue;
			}
		case 9: {
			char filename[21];
			list<tnode*> alist = now.tree_level();
			cout << "输入文件名(长度<20):";
			cin >> filename;
			alist.tofile(filename);
			continue;
		}
		}
	} while (1);
	return 0;
}
