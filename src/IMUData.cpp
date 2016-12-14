#include "IMUData.h"
#include <fstream>

namespace My
{

// 	IMUData(const IMUData& p)
// 	{
// 		
// 		
// 	}

	IMUDatas::IMUDatas()
	{
		m_dat.clear();
		
	}
	IMUDatas::~IMUDatas()
	{
		if(m_dat.size())
		{
			for(int i=0;i<m_dat.size();i++)
				delete m_dat[i];
		}
	}

	bool IMUDatas::SetOnePatch(IMUData& p)
	{
		IMUData* im = new IMUData(p);
		m_dat.push_back(im);
		
		
		return true;	
	}
	
	bool IMUDatas::ReadData(const char* path,int type/*=0*/)
	{
		fstream fd(path);
		if(!fd)
			return false;
		
		m_type = type;
		string tmp;
		
		IMUData da;
		for(;;)
		{
			getline(fd,tmp);
			if(tmp=="")
			{
				break;
			}
			
			sscanf(tmp.c_str(),"%f %f %f %f %f %f %f",&da.m_gryx,&da.m_gryy,&da.m_gryz,&da.m_accx,&da.m_accy,&da.m_accz,&da.m_tm);
			SetOnePatch(da);
			
		}
		
		return true;
		
	}
	

}