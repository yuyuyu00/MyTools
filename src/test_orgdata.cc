#include "Point2dData.h"
#include "MapPoint2D.h"
#include "DrawPoint2D.h"
#include "CommonFun.h"

using namespace My;
using namespace My::map2d;

int main()
{
	Point2dData dat;
	dat.init("/mnt/hgfs/0.TEATDATA/GreenValley/test4/da.flam");
	
	MapPoints mps;
	mps.InPutDataFast("/mnt/hgfs/0.TEATDATA/GreenValley/test4/reall.odm", "/mnt/hgfs/0.TEATDATA/GreenValley/test4/da.flam");
	
	
	
	CDrawPoint2D dr("img");
	DrawMps(mps.mps,dr);
	
	cout<<dat.GetOneData()<<endl;

}