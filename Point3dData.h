#ifndef POINT3DDATA_H
#define POINT3DDATA_H
#include "Point2dData.h"



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

namespace My
{
	
	
	struct  PointType3D
	{
		double x,y,z;
	};
	
	
	class Point3dData
	{
	public:
		vector<Point2dData> m_dat;
		double m_tm;
	private:
		fstream m_fd;
		
	public:

		
	};
	

}
#endif
