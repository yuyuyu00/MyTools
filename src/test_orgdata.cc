#include "Point2dData.h"
#include "MapPoint2D.h"
#include "DrawPoint2D.h"
#include "CommonFun.h"
#include "MapPoint3D.h"
#include <chrono>
#include <thread>

using namespace My;
using namespace My::map2d;

int main()
{
// 	Point2dData dat;
// 	dat.init("/mnt/hgfs/0.TEATDATA/GreenValley/test4/da.flam");
// 	
// 	MapPoints mps;
// 	mps.InPutDataFast("/mnt/hgfs/0.TEATDATA/GreenValley/test4/reall.odm", "/mnt/hgfs/0.TEATDATA/GreenValley/test4/da.flam");
// 	
// 	CDrawPoint2D dr("img");



#ifdef WIN32
	string datapath("D:/work/program/Cartographer/cartographer/test4/");
#else
	string datapath("/mnt/hgfs/E/data/test4/");
#endif // WIN32

	//path
	//????

	vector<string> str;
	for (int i = 0; i < 2496; i++)
	{
		stringstream ss;
		ss << i;
		string path = datapath + string("sweep") + ss.str() + string(".txt");
		str.push_back(path);
		//cout << str[i] << endl;
	}

	//init read
	My::map3d::MapPoint3D mp;
	//My::IMUDatas imus;
	double imutime, lasertime;
	int imuindex, laserindex;
	imuindex = laserindex = 0;

	CDrawPoint2D dr("img");

	for (int i = 0; i < str.size(); i++)
	{
		mp.clear();
		//bool rdokimu = imus.ReadData((datapath + "rep.txt").c_str());
		bool rdoklaser = mp.ReadXYZ(str[i].c_str(), 1);
		if (!rdoklaser)
		{
			cerr << "read file error" << endl;
			return -1;
		}


		 
		dr.SetMapPoint3RuningTime(mp);
		dr.SetWaitKey(10);
		//dr.ClearData();

	}
	
	My::map3d::MapPoints3D mps;
	mps.SetOnePatch(mp);

	mps.Show();
	mps.Spins();

	
	//DrawMps(mps.mps,dr);
	
	//cout<<dat.GetOneData()<<endl;

}