#ifndef MAPPOINT3D_H
#define MAPPOINT3D_H

#include <vector>
#include <iostream>

#include <pcl/common/common_headers.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;

namespace My
{
	namespace map3d
	{
		
		
		typedef  pcl::PointXYZ PointType3D;


		class MapPoint3D: public pcl::PointCloud<pcl::PointXYZ>
		{

		public:
			typedef boost::shared_ptr<MapPoint3D> Ptr;


			MapPoint3D();
			~MapPoint3D();
			MapPoint3D(const MapPoint3D& p);
			
			
			bool ReadXYZ(const char* path,int type=0);
			
			
		public:
			double m_tm;
			int m_id;
			int m_filetype;
		};


		
		class MapPoints3D
		{
		public:
			
			MapPoints3D();
			~MapPoints3D();
			
			
			bool Show();

			bool Spins(int spintime=0);
			
			bool AddPointCloud(MapPoint3D::Ptr p);
			
			bool SetOnePatch(MapPoint3D& mp);
			
			
		private:
			bool initView();
			
		public:
			vector<MapPoint3D::Ptr> m_mps;
			
			
		private:
			boost::shared_ptr<pcl::visualization::PCLVisualizer> m_viewer; //视图
			
		
		};
		
		
		
		
	}
}




#endif