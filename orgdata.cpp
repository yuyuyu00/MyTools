#include "orgdata.h"

namespace My 
{
     bool Point2dData::init(const char* path,int type/*=0*/)
      {
	m_type = type;
	m_fd.open(path);
	if(!m_fd)
	  return false;
	  
      }
	
	
   bool Point2dData::GetOneData();
  {
	string tmp;
	PointType2D pd;	
	m_dat.clear();
	
	int year,month,day,hour,min,sec,nsec;
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
	  scanf(tmp.c_str(),"%d%d%d%d%d%d%d%f%f%f%d",&year,&month,&day,&hour,&min,&sec,&nsec,&nums);
	  m_tm = (double)(sec)+(double)(nsec)/1000.;
	  for(int i=0;i<nums;i++)
	  {
	    getline(m_fd,tmp);
	    scanf(tmp.c_str(),"%f%f",&pd.dis,&pd.ang);
	    
	  }
	  m_dat.push_back(pd);
	  break;
	default:
	  break;
	 }
      
	return m_dat.size();
	
      }
      
  
}