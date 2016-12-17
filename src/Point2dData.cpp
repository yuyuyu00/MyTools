#include "Point2dData.h"

namespace My 
{
	bool Point2dData::init(const char* path,int type/*=0*/)
	{
		m_type = type;
		m_fd.open(path);
		
		if(m_fd)
			return true;
		else
			return false;
	}
	
	int Point2dData::GetOneData()
	{
		string tmp;
		PointType2D pd;	
		m_dat.clear();
		
		int year,month,day,hour,min,nsec;
		long long sec;
		int nums;
		switch(m_type)
		{
			case 0:
				getline(m_fd,tmp);
				if(tmp=="")
				{
					m_fd.close();
					return false;
				}
				sscanf(tmp.c_str(),"%d %d %d %d %d %lld %d %d\n",&year,&month,&day,&hour,&min,&sec,&nsec,&nums);
				m_tm = (double)(sec)+(double)(nsec)/1000.;
				for(int i=0;i<nums;i++)
				{
					getline(m_fd,tmp);
					sscanf(tmp.c_str(),"%lf%lf",&pd.dis,&pd.ang);
					m_dat.push_back(pd);
					
				}
				break;
			default:
				break;
		}
		
		return m_dat.size();
		
	}
	
	
}