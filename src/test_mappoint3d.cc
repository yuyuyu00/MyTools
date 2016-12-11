/* \author Geoffrey Biggs */
#include <iostream>
#include <fstream>
#include <string>

#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>

#include "MapPoint3D.h"

using namespace My;
using namespace My::map3d;

using namespace std;


// --------------
// -----Help-----
// --------------
void printUsage (const char* progName)
{
	std::cout << "\n\nUsage: "<<progName<<" [options]\n\n"
	<< "Options:\n"
	<< "-------------------------------------------\n"
	<< "-h           this help\n"
	<< "-s           Simple visualisation example\n"
	<< "-r           RGB colour visualisation example\n"
	<< "-c           Custom colour visualisation example\n"
	<< "-n           Normals visualisation example\n"
	<< "-a           Shapes visualisation example\n"
	<< "-v           Viewports example\n"
	<< "-i           Interaction Customization example\n"
	<< "\n\n";
}




boost::shared_ptr<pcl::visualization::PCLVisualizer> customColourVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
	// --------------------------------------------
	// -----Open 3D viewer and add point cloud-----
	// --------------------------------------------
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
	viewer->setBackgroundColor (0, 0, 0);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 0, 255, 0);
	viewer->addPointCloud<pcl::PointXYZ> (cloud, single_color, "sample cloud");
	viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
	viewer->addCoordinateSystem (1.0);
	viewer->initCameraParameters ();
	return (viewer);
}




int main (int argc, char** argv)
{
	MapPoint3D pt;
	fstream fd("/mnt/hgfs/E/data/cartodata/1.txt");
	string tmp;
	getline(fd,tmp);
	string path = string("/mnt/hgfs/E/data/cartodata/re_pts1/")+tmp.substr(0,tmp.length()-1);;
	
	//fi.open(path);
	cout<<path<<endl;
	fstream fdd(path.c_str());/*"/mnt/hgfs/E/data/cartodata/re_pts1/laser635954624413020553.xyz");*/
	if(!fdd)
		cout<<"error open"<<endl;
	fdd.close();
	
	pt.ReadXYZ(path.c_str());
	
// 	MapPoints3D mp;
// 	mp.SetOnePatch(pt);
// 	mp.Show();
	
	pcl::PointCloud<pcl::PointXYZ>* pointbase = dynamic_cast< pcl::PointCloud<pcl::PointXYZ>*>(&pt);
	pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr(pointbase);
	
	

	if (pcl::console::find_argument (argc, argv, "-h") >= 0)
	{
		printUsage (argv[0]);
		return 0;
	}
	bool simple(false), rgb(false), custom_c(false), normals(false),
	shapes(false), viewports(false), interaction_customization(false);

	if (pcl::console::find_argument (argc, argv, "-c") >= 0)
	{
		custom_c = true;
		std::cout << "Custom colour visualisation example\n";
	}
	else
	{
		printUsage (argv[0]);
		return 0;
	}
	
// 	// ------------------------------------
// 	// -----Create example point cloud-----
// 	// ------------------------------------
// 	pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
// 	uint8_t r(255), g(15), b(15);
// 	for (float z(-1.0); z <= 1.0; z += 0.05)
// 	{
// 		for (float angle(0.0); angle <= 360.0; angle += 5.0)
// 		{
// 			pcl::PointXYZ basic_point;
// 			basic_point.x = 0.5 * cosf (pcl::deg2rad(angle));
// 			basic_point.y = sinf (pcl::deg2rad(angle));
// 			basic_point.z = z;
// 			basic_cloud_ptr->points.push_back(basic_point);
// 		}
// 	}
// 	basic_cloud_ptr->width = (int) basic_cloud_ptr->points.size ();
// 	basic_cloud_ptr->height = 1;
	
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

	if (custom_c)
	{
		viewer = customColourVis(basic_cloud_ptr);
	}

	//--------------------
	// -----Main loop-----
	//--------------------
	while (!viewer->wasStopped ())
	{
		viewer->spinOnce (100);
		boost::this_thread::sleep (boost::posix_time::microseconds (100000));
	}
}