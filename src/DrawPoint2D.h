#ifndef DRAWPOINT2D_H
#define DRAWPOINT2D_H

#include <vector>
#include <string>

#include "MapPoint3D.h"

using namespace std;

//用于测试的结构体，调用opencv绘图，仅供自己测试

namespace My 
{
		
		struct DrawPoint
		{
			double x;
			double y;
			double z;
		};
		
		enum PointTypeUnit{POINTS_UNIT,CIRCLES_UNIT,LINES_UNIT,TAGS_UNIT};
		
		enum TypeColor{ TYPE_AUTO,TYPES_WHITE,TYPES_GREEN,TYPES_RED,TYPES_BLUE};
		
		class DrawPts
		{
		public:
			string str;
			DrawPoint* dps;
			int nums;
			PointTypeUnit typ; 
			TypeColor col;
			DrawPts();
			
			~DrawPts();
			
			void clearDate();
			
			DrawPts(const DrawPts& dp);
			DrawPts(vector<DrawPoint>& pts);
			DrawPts(vector<DrawPoint>& pts,PointTypeUnit type);
			DrawPts(vector<DrawPoint>& pts,PointTypeUnit type,TypeColor tp);

			
		};
		
		// 此类是从 DrawPoint2D.dll 导出的
		class  CDrawPoint2D {
		public:
			enum MODE_SHOW{	MODE_AUTO,MODE_INCRES};
			CDrawPoint2D(void);
			
			CDrawPoint2D(char* title);
			
			~CDrawPoint2D()
			{
				// 		for (int i = 0; i < mpss.size();i++)
				// 		{
				// 			mpss[i].~DrawPts();
				// 		}
				//		m_ImgTitle.clear();
			}

			void SetMapPoint3RuningTime(map3d::MapPoint3D& mp3, PointTypeUnit type = POINTS_UNIT, TypeColor tp = TYPE_AUTO);

			void SetDrawPTSRuningTime(DrawPts& pts);
			
			void SetPointsRuningTime(vector<DrawPoint>& pts,TypeColor tr=TYPES_WHITE);
			
			void SetCircleRuningTime(vector<DrawPoint>& pts,TypeColor tr=TYPES_WHITE);
			
			void SetLinesRuningTime(vector<DrawPoint>& pts,TypeColor tr=TYPES_WHITE);
			
			void SetTagsRuningTime(char* cs,TypeColor tr=TYPES_GREEN);
			
			int SetWaitKey(int i=0);;
			
			void ClearData();
			
			void PopBackData()
			{
				mpss.pop_back();
			}
			
			void WriteImg(const char* path);
			
		private:
			void ShowMps(const char* path=NULL);
			
			bool GetMaxMin();
			
			void DrawMat(const char* path=NULL);
			
		private:
			int m_w,m_h;//图像宽高
			
			vector<DrawPts> mpss;
			
			double m_xmax,m_ymax,m_xmin,m_ymin;
			double m_zmax, m_zmin;
			
			double m_stepw,m_steph;//每个像素的距离
			
			string m_ImgTitle;
			
			MODE_SHOW m_showmode;
			
		};
		
		extern  int nDrawPoint2D;
		
		int fnDrawPoint2D(void);
		
}


#endif