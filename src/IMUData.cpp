#include "IMUData.h"


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
		
		
		
		return true;	
	}
	

}