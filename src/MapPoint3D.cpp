#include "MapPoint3D.h"
#include "CommonIO.h"

namespace My
{
	namespace map3d
	{
		
		using namespace std;
		using namespace My;
		
		MapPoint3D::MapPoint3D()
		{
			m_filetype=0;
		}
		
		MapPoint3D::~MapPoint3D()
		{
			clear();
		}
		
		MapPoint3D::MapPoint3D(const MapPoint3D& p)
		{
			for(int i=0;i<p.size();i++)
			{
				push_back(p[i]);
			}
			
		}
		
		bool MapPoint3D::ReadXYZ(const char* path,int type/*=0*/)
		{
			m_filetype = type;
			
			char* buf = GetFileBuf(path);
			
			if(buf==NULL)
				return false;
			
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
		
		MapPoints3D::~MapPoints3D()
		{
			for(int i=0;i<m_mps.size();i++)
			{
				delete m_mps[i];
			}
			m_mps.clear();
				
		}
		
		bool MapPoints3D::SetOnePatch(MapPoint3D& mp)
		{
			MapPoint3D* mpt = new MapPoint3D(mp);
			
			m_mps.push_back(mpt);
			
			return true;
		}
		
	}
	
}