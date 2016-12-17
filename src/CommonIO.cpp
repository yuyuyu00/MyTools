#include "CommonIO.h"
#include <fstream>
#include "memory.h"

using namespace std;

namespace My
{


	
	char* GetFileBuf( const char* path )
	{
		filebuf* fbuf;
		ifstream fi;
		fi.open(path, ios::binary);
		long long siz;
		char* buf;
		
		if (!fi)
		{
			return NULL;
		}
		fbuf = fi.rdbuf();
		siz = fbuf->pubseekoff(0, ios::end, ios::in);
		fbuf->pubseekpos(0, ios::in);
		buf = new char[(unsigned int)siz];
		fbuf->sgetn(buf, siz);
		fi.close();
		
		return buf;
	}
	
	
	string BufGetLine(char* buf, int& index)
	{
		int i = 0;
		char mybuf[4096];
		memset(mybuf, '\0', 4096);
		for (i=index;buf[i]!='\n';i++)
		{
			if (buf[i]=='\0')
			{
				index = i;
				return string("");
			}
			mybuf[i - index] = buf[i];
		}
		mybuf[i - index] = '\n';
		i++;
		index = i;
		
		return string(mybuf);
	}
	
	
	
	
	
	
	
	

}