#include "MapPoint3D.h"
#include "CommonIO.h"

namespace My
{
	namespace map3d
	{
		
		using namespace std;
		using namespace My;
		
		bool MapPoint3D::ReadXYZ(char* path,int type/*=0*/)
		{
			m_filetype = type;
			
			char* buf = GetFileBuf(path);
			
			int index=0;
			
			PointType3D pt;
			
			for(;;)
			{
				string tmp =  BufGetLine(buf,index);
				if(tmp=="")
					break;
				stringstream ss(tmp);
				ss>>pt.x>>pt.y>>pt.z;
				this->push_back(pt);
			}
			delete buf;
			
			return true;
		}
		
	}
	
}