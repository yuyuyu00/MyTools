#ifndef COMMONFUN_H
#define COMMONFUN_H

#include "MapPoint2D.h"
#include "DrawPoint2D.h"
#include <vector>

using namespace My::map2d;
using namespace My;

namespace My
{

		
		
		int DrawMps(vector<MapPoint*>& mps, CDrawPoint2D& dr);
		
		int Draw2Mps(CDrawPoint2D& dr, MapPoint* mps1, MapPoint* mps2,int waitkeys=0);
		
		int DrawOneMps(CDrawPoint2D& dr, MapPoint* mps1, TypeColor ty = TYPES_WHITE, int waitkey = 1);
		
		int DrawPointTypes(CDrawPoint2D& dr, vector<PointType>& odms, TypeColor ty = TYPES_WHITE, int waitkey = 1);
		
		int DrawPointTypes2(CDrawPoint2D& dr, vector<PointType>& odms, TypeColor ty = TYPES_WHITE, int waitkey = 1);
		
		int Draw2PointTypes(vector<PointType>& odms1, vector<PointType>& odms2);
		

}


#endif