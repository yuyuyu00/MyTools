#include "CommonFun.h"
#include "DrawPoint2D.h"
#include "MapPoint2D.h"


namespace My
{
		using namespace My::map2d;
		// 这是导出函数的一个示例。
		 int DrawMps(vector<MapPoint*>& mps, CDrawPoint2D& dr)
		{
			for (int i = 0; i < mps.size(); i++)
			{
				//if (mps[i]->isProcessed)
				{
					vector<DrawPoint> pts;
					pts.resize(mps[i]->lt.LaserNums);
					for (int j = 0; j < mps[i]->lt.LaserNums; j++)
					{
						if (mps[i]->lt.laserData[j]>60|| mps[i]->lt.laserData[j]<1.5)
						{
							pts[j].x = 0;
							pts[j].y = 0;
						}
						else
						{
							pts[j].x = mps[i]->lt.laserPoint[j].x;
							pts[j].y = mps[i]->lt.laserPoint[j].y;
						}
						
					}
					dr.SetPointsRuningTime(pts);
					pts.clear();
					pts.resize(1);
					pts[0].x = mps[i]->odom.x;
					pts[0].y = mps[i]->odom.y;
					dr.SetCircleRuningTime(pts,TYPES_GREEN);
					pts.resize(2);
					pts[1].x = mps[i]->odom.x + 5 * cos(mps[i]->odom.thete);
					pts[1].y = mps[i]->odom.y + 5 * sin(mps[i]->odom.thete);
					dr.SetLinesRuningTime(pts, TYPES_RED);
					
					dr.SetWaitKey(1);
					dr.PopBackData();
				}
			}
			dr.SetWaitKey(1);
			
			return 0;
		}
		
		 int Draw2Mps(CDrawPoint2D& dr,MapPoint* mps1, MapPoint* mps2,int waitkeys)
		{
			DrawOneMps(dr, mps1,TYPES_GREEN);
			DrawOneMps(dr, mps2);
			dr.SetWaitKey(waitkeys);
			
			return 0;
		}
		
		 int DrawOneMps(CDrawPoint2D& dr, MapPoint* mps1, TypeColor ty,int waitkey)
		{
			vector<DrawPoint> pts;
			pts.resize(mps1->lt.LaserNums);
			for (int j = 0; j < mps1->lt.LaserNums; j++)
			{
				if (mps1->lt.laserData[j]>60 || mps1->lt.laserData[j] < 1.5)
				{
					pts[j].x = 0;
					pts[j].y = 0;
				}
				else
				{
					pts[j].x = mps1->lt.laserPoint[j].x;
					pts[j].y = mps1->lt.laserPoint[j].y;
				}
				
			}
			dr.SetPointsRuningTime(pts, ty);
			pts.clear();
			pts.resize(1);
			pts[0].x = mps1->odom.x;
			pts[0].y = mps1->odom.y;
			dr.SetCircleRuningTime(pts, TYPES_GREEN);
			pts.resize(2);
			pts[1].x = mps1->odom.x + 5 * cos(mps1->odom.thete);
			pts[1].y = mps1->odom.y + 5 * sin(mps1->odom.thete);
			dr.SetLinesRuningTime(pts, TYPES_RED);
			
			if(waitkey>=0)
				dr.SetWaitKey(waitkey);
			return true;
		}
		
		 int DrawPointTypes(CDrawPoint2D& dr, vector<PointType>& odms, TypeColor ty /*= TYPES_WHITE*/, int waitkey /*= 1*/)
		{
			vector<DrawPoint> pts;
			vector<DrawPoint> psl;
			pts.resize(odms.size());
			double la = odms[odms.size() - 1].x - odms[0].x;
			la /= 5.;
			
			for (int i = 0; i < odms.size();i++)
			{
				pts[i].x = odms[i].x;
				pts[i].y = odms[i].y;
				
				psl.resize(2);
				psl[0].x = odms[i].x;
				psl[0].y = odms[i].y;
				psl[1].x = la*cos(odms[i].thete)+odms[i].x;
				psl[1].y = la*sin(odms[i].thete)+odms[i].y;
				if(i==0)
					dr.SetLinesRuningTime(psl, TYPES_GREEN);
				else
					dr.SetLinesRuningTime(psl, TYPES_RED);
			}
			
			dr.SetLinesRuningTime(psl, TYPES_WHITE);
			dr.SetCircleRuningTime(pts, ty);
			dr.SetLinesRuningTime(pts,TYPES_WHITE);
			dr.SetWaitKey(waitkey);
			
			return waitkey;
			
		}
		
		 int DrawPointTypes2(CDrawPoint2D& dr, vector<PointType>& odms, TypeColor ty /*= TYPES_WHITE*/, int waitkey /*= 1*/)
		{
			vector<DrawPoint> pts;
			pts.resize(odms.size());
			
			for (int i = 0; i < odms.size(); i++)
			{
				pts[i].x = odms[i].x;
				pts[i].y = odms[i].y;
				pts[i].z = 0;
				
				
			}
			
			dr.SetPointsRuningTime(pts, ty);
			dr.SetWaitKey(waitkey);
			
			return waitkey;
		}
		
		 int Draw2PointTypes(vector<PointType>& odms1, vector<PointType>& odms2)
		{
			CDrawPoint2D dr;
			
			DrawPointTypes(dr, odms1, TYPES_BLUE, 1);
			
			DrawPointTypes(dr, odms2, TYPES_GREEN,0);
			
			return 1;
		}
		


}

