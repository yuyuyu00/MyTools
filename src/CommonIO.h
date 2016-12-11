#ifndef COMMONIO_H
#define COMMONIO_H
#include <iostream>
#include <string>

using namespace std;

namespace My
{
	
	//读取文件至内存
	char* GetFileBuf(const char* path);

	//根据索引获取缓存的一行，放回当前位置
	string BufGetLine(char* buf, int& index);



}

#endif