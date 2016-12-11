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
			bool ReadXYZ(char* path,int type=0);
			
			
			
		public:
			vector<PointType3D> m_pts;
			
			int m_filetype;
		};
		
		class MapPoints3D
		{
		public:
			bool Show();
			
			
			
			
		public:
			vector<MapPoint3D*> m_mps;
			
			
		private:
			
		
		};
		
		
		
		
	}
}




#endif