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
	list<char> _search;
	list<char> _delete;
	list<char> _save;
	_exit << 'e' << 'x' << 'i' << 't';
	_readfile << 'r' << 'e' << 'a' << 'd' << 'f' << 'i' << 'l' << 'e';
	_help << 'h' << 'e' << 'l' << 'p';
	_build << 'b' << 'u' << 'i' << 'l' << 'd';
	_tree << 't' << 'r' << 'e' << 'e';
	_import << 'i' << 'm' << 'p' << 'o' << 'r' << 't';
	_search << 's' << 'e' << 'a' << 'r' << 'c' << 'h';
	_delete << 'd' << 'e' << 'l' << 'e' << 't' << 'e';
	_save << 's' << 'a' << 'v' << 'e';
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
	if (order == _search)
		return 7;
	if (order == _delete)
		return 8;
	if (order == _save)
		return 9;
	return 0;
}
list<list<char>> importfile(char *filename) {
	FILE *f;
	list<list<char>> result;
	if (!(f = fopen(filename, "rb")))
		cout << "文件读取错误" << endl;
	else {
		list<char> str;
		while (!feof(f)) {
			char point;
			fscanf(f, "%c", &point);
			if (point == '\r' || point == '\0')
				continue;
			if (point != '\n') {
				str << point;
			} else {
				result << str;
				str.head = NULL;
				str.tail = NULL;
				continue;
			}
		}
		fclose(f);
	}
	return result;
}
#endif /* order_h */
