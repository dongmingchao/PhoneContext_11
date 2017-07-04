//
//  order.h
//  phone
//
//  Created by 董明超 on 2017/7/4.
//  Copyright © 2017年 董明超. All rights reserved.
//

#ifndef order_h
#define order_h
//exit
int check(list<char> order) {
	list<char> _exit;
	list<char> _readfile;
	list<char> _help;
	list<char> _build;
	list<char> _tree;
	list<char> _import;
	_exit << 'e' << 'x' << 'i' << 't';
	_readfile << 'r' << 'e' << 'a' << 'd' << 'f' << 'i' << 'l' << 'e';
	_help << 'h' << 'e' << 'l' << 'p';
	_build << 'b' << 'u' << 'i' << 'l' << 'd';
	_tree << 't' << 'r' << 'e' << 'e';
	_import << 'i' << 'm' << 'p' << 'o' << 'r' << 't';
	if (order == _exit)
		return 1;
	if (order == _readfile)
		return 2;
	if (order == _help)
		return 3;
	if (order == _build)
		return 4;
	if (order == _tree)
		return 5;
	if (order == _import)
		return 6;
	return 0;
}
list<char*> importfile(char *filename) {
	FILE *f;
	list<char*> result;
	if (!(f = fopen(filename, "rb")))
		cout << "文件读取错误" << endl;
	else {
		while (!feof(f)) {
			char *p = new char;
			fgets(p, 1024, f);
			char *temp = new char;
			for (int i = 0; i < 1024; i++) {
				if (p[i] != '\r') {
					temp[i] = p[i];
					temp[i] = *new char;
				} else {
					temp[i] = '\0';
					result << temp;
					break;
				}
			}
			//printf("line::%s", p);
			//result << strtok(p, "\r");
		}
		fclose(f);
	}
	return result;
}
list<char*> merge(list<char> orgin) { //合并字符成串并去除\r\n
	list<char*> result;
	char *word;
	int i = 0;
	while (orgin.head) {
		if (orgin.head->e != '\r') {
			if (orgin.head->e == '\n') {
				word += i;
				word = new char;
				word[i] = '\0';
				printf("%s", word);
				result << word;
				i = 0;
				word = new char;
			} else {
				word += i;
				word = new char;
				word[i] = orgin.head->e;
			}
			i++;
		}
		orgin.head = orgin.head->next;
	}
	return result;
}
#endif /* order_h */
