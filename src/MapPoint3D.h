#ifndef MAPPOINT3D_H
#define MAPPOINT3D_H

#include <vector>
#include <iostream>

#include <pcl/common/common_headers.h>

using namespace std;

namespace My
{
	namespace map3d
	{
		
		
		typedef  pcl::PointXYZ PointType3D;


		class MapPoint3D: public pcl::PointCloud<pcl::PointXYZ>
		{
		public:
			MapPoint3D();
			~MapPoint3D();
			MapPoint3D(const MapPoint3D& p);
			
			
			bool ReadXYZ(const char* path,int type=0);
			
			
		public:
			
			int m_filetype;
		};
		

		
		class MapPoints3D
		{
		public:
			
			~MapPoints3D();
			
			
			bool Show();
			
			bool SetOnePatch(MapPoint3D& mp);
			
			
			
		public:
			vector<MapPoint3D*> m_mps;
			
			
		private:
			
		
		};
		
		
		
		
	}
}




#endif