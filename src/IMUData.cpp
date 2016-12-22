#include "IMUData.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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

	bool IMUDatas::SetOnePatch(IMUData& p,int imutype)
	{
		IMUData* im = new IMUData(p);
		im->m_imutype = imutype;
		m_dat.push_back(im);
		
		
		return true;	
	}
	
	bool IMUDatas::ReadData(const char* path,int type/*=0*/)
	{
		fstream fd(path);
		if(!fd)
			return false;
		
		m_filetype = type;
		string tmp;
		
		IMUData da;
		for(int i=0;;i++)
		{
			getline(fd,tmp);
			if(tmp=="")
			{
				break;
			}
			if (i==0)
			{
				int t1, t2, t3;
				double d1, d2, d3,d4;
				sscanf(tmp.c_str(), "%d %d %d %d %lf %lf %lf", &t1, &t2, &t3, &d1, &d2, &d3, &d4);
				m_imutype = t1;
			}
			else
			{
				sscanf(tmp.c_str(), "%lf %lf %lf %lf %lf %lf %lf", &da.m_gryx, &da.m_gryy, &da.m_gryz, &da.m_accx, &da.m_accy, &da.m_accz, &da.m_tm);
				SetOnePatch(da,m_imutype);
			}
			
		}
		
		return true;
		
	}
	

}