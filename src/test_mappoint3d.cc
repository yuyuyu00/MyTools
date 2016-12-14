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


#ifdef WIN32

#define mpath "E://data//cartodata//"
#else
#define mpath "/mnt/hgfs/E/data/cartodata/"
#endif // WIN32


int main (int argc, char** argv)
{
	MapPoint3D pt;
	fstream fd((string(mpath)+string("1.txt")).c_str());
	string tmp;
	MapPoints3D mp;
	
	
	while(true)
	{
		
		
		getline(fd,tmp);
		if(tmp=="")
			break;
		string path;
		
		#ifdef WIN32
		path = string(mpath) + string("re_pts1//") + tmp.substr(0, tmp.length());
		#else
		path = string(mpath) + string("re_pts1//") + tmp.substr(0, tmp.length() - 1);
		#endif // WIN32
		
		
		//fi.open(path);
		cout<<path<<endl;
		fstream fdd(path.c_str());/*"/mnt/hgfs/E/data/cartodata/re_pts1/laser635954624413020553.xyz");*/
		if(!fdd)
			cout<<"error open"<<endl;
		fdd.close();
		pt.clear();
		pt.ReadXYZ(path.c_str());
		
		mp.SetOnePatch(pt);
		mp.Show();
		boost::this_thread::sleep (boost::posix_time::microseconds (100000));
		
	}
}