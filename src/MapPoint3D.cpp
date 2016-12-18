#include "MapPoint3D.h"
#include "CommonIO.h"
#include "stdio.h"
#include <boost/thread/thread.hpp>


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
				
				
				if(m_filetype==0)
					ss>>pt.x>>pt.y>>pt.z;
				else if(m_filetype==1)
				{
					long long tm=0;
					sscanf(tmp.c_str(),",%lld, %f, %f, %f",&tm,&pt.x,&pt.y,&pt.z);
					
					m_tm = double(tm)/10000000.;
				}
				
				
				
				this->push_back(pt);
			}
			delete buf;
			
			return true;
		}
		
		MapPoints3D::MapPoints3D()
		{
			initView();
			
		}
		
		
		MapPoints3D::~MapPoints3D()
		{
			for(int i=0;i<m_mps.size();i++)
			{
				if (m_mps[i] != NULL)
				{
					//delete m_mps[i];
					//m_mps[i] = NULL;
				}

			}
			m_mps.clear();
				
		}
		
		bool MapPoints3D::SetOnePatch(MapPoint3D& mp)
		{
			MapPoint3D::Ptr mpt(new MapPoint3D(mp));
			mpt->m_id = m_mps.size();
			m_mps.push_back(mpt);
			AddPointCloud(m_mps[m_mps.size()-1]);
			return true;
		}
		
		bool MapPoints3D::AddPointCloud(MapPoint3D::Ptr p)
		{
			//char* mtcharid=(char*)malloc(sizeof(char)*128);
			char buf[128];
			sprintf(buf,"%d",p->m_id);
			//itoa(p->m_id,mtcharid,10);
			//类型转换
			

			pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(p, 0, 255, 0);
			//m_viewer->removePointCloud("sample cloud");
			m_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, buf);
			m_viewer->addPointCloud<pcl::PointXYZ> (p, single_color, buf);
			
			return true;
		}
		
		bool MapPoints3D::initView()
		{
			
			boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
			m_viewer = viewer;
			m_viewer->setBackgroundColor (0, 0, 0);
			
			m_viewer->addCoordinateSystem (1.0);
			m_viewer->initCameraParameters ();
			
			return true;
		}
		
		bool MapPoints3D::Show()
		{
			if (!m_viewer->wasStopped ())
			{
				m_viewer->spinOnce (100);
				//boost::this_thread::sleep (boost::posix_time::microseconds (100000));
			}
			
			
			return true;
		}
		
		bool MapPoints3D::Spins(int spintime)
		{
			if(!m_viewer->wasStopped())
			{
				if (spintime > 0)
					m_viewer->spinOnce(spintime);
				else if (spintime==0)
					m_viewer->spin();
				else
					return false;
				return true;
			}
			return false;
		}

	}
	
}