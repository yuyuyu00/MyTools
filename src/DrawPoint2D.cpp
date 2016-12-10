#include "DrawPoint2D.h"
#include "float.h"
#include "opencv2/opencv.hpp"
#include <string>

using namespace cv;
using namespace std;



namespace My 
{
		
		
		// 这是导出变量的一个示例
		int nDrawPoint2D=0;
		
		// 这是导出函数的一个示例。
		int fnDrawPoint2D(void)
		{
			return 42;
		}
		
		// 这是已导出类的构造函数。
		// 有关类定义的信息，请参阅 DrawPoint2D.h
		CDrawPoint2D::CDrawPoint2D()
		{
			m_ImgTitle = string("img");
			stepw=steph=1.;
			
			h = 780;
			// 	xmax = -DBL_MAX;
			// 	ymax = -DBL_MAX;
			// 	xmin = DBL_MAX;
			// 	ymin = DBL_MAX;
			return;
		}
		
		CDrawPoint2D::CDrawPoint2D( char* title )
		{
			m_ImgTitle = string(title);
			stepw=steph=1.;
			
			h = 800;
			xmax = -DBL_MAX;
			ymax = -DBL_MAX;
			xmin = DBL_MAX;
			ymin = DBL_MAX;
		}
		
		
		
		void CDrawPoint2D::SetPointsRuningTime( vector<DrawPoint>& pts ,TypeColor tr)
		{
			DrawPts p(pts,POINTS_UNIT,tr);
			
			mpss.push_back(p);
			
			ShowMps();
		}
		
		void CDrawPoint2D::ClearData()
		{
			h = 800;
			
			xmax = -DBL_MAX;
			ymax = -DBL_MAX;
			xmin = DBL_MAX;
			ymin = DBL_MAX;
			
			mpss.clear();
			// 	for (int i=0;i<mpss.size();i++)
			// 	{
			// 		delete &mpss[i];
			// 	}
			return;
		}
		
		int CDrawPoint2D::SetWaitKey( int i )
		{
			
			return waitKey(i);
		}
		
		void CDrawPoint2D::ShowMps(const char* path)
		{
			if(GetMaxMin())
			{
				DrawMat(path);
			}
			
		}
		
		bool CDrawPoint2D::GetMaxMin()
		{
			for (int i=0;i<mpss.size();i++)
			{
				for (int j=0;j<mpss[i].nums;j++)
				{
					if (xmax<mpss[i].dps[j].x)
					{
						xmax = mpss[i].dps[j].x;
					}
					if (xmin>mpss[i].dps[j].x)
					{
						xmin = mpss[i].dps[j].x;
					}
					if (ymax<mpss[i].dps[j].y)
					{
						ymax = mpss[i].dps[j].y;
					}
					if (ymin>mpss[i].dps[j].y)
					{
						ymin = mpss[i].dps[j].y;
					}
				}
				
			}
			double diffx = xmax-xmin;
			double diffy = ymax-ymin;
			if (diffx>0&&diffy>0)
			{
				w = (int)floor(h*diffx/diffy);
				if (w>1500)
				{
					w=1500;
				}
				steph = diffy/h;
				stepw = diffx/w;
				
			}
			else
				return false;
			
			return true;
			
			
		}
		
		Scalar GetColor(TypeColor tr)
		{
			Scalar sl;
			if (tr==TYPES_WHITE)
			{
				sl = Scalar(255,255,255);
			}
			if (tr==TYPES_BLUE)
			{
				sl = Scalar(255,0,0);
			}
			if (tr==TYPES_GREEN)
			{
				sl = Scalar(0,255,0);
			}
			if (tr==TYPES_RED)
			{
				sl = Scalar(0,0,255);
			}
			return sl;
		}
		
		
		
		void CDrawPoint2D::DrawMat(const char* path)
		{
			if (w<=0)
			{
				return;
			}
			Mat img = Mat::zeros(h,w,CV_8UC3);
			
			int textPos = 0;
			
			for (int i=0;i<mpss.size();i++)
			{
				if (TAGS_UNIT == mpss[i].typ)
				{
					putText(img,mpss[i].str.c_str(),Point(50+textPos*10,50),FONT_HERSHEY_SIMPLEX,0.8,GetColor(mpss[i].col));
					textPos++;
				}
				if(LINES_UNIT == mpss[i].typ)
				{
					for (int j=0;j<mpss[i].nums-1;j++)
					{
						int x1 = (int)floor((mpss[i].dps[j].x-xmin)/stepw);
						int x2 = (int)floor((mpss[i].dps[j+1].x-xmin)/stepw);
						int y1 = (int)floor((mpss[i].dps[j].y-ymin)/steph);
						int y2 = (int)floor((mpss[i].dps[j+1].y-ymin)/steph);
						x1 = MIN(MAX(x1,0),w-1);
						x2 = MIN(MAX(x2,0),w-1);
						y1 = MIN(MAX(y1,0),h-1);
						y2 = MIN(MAX(y2,0),h-1);
						line(img,Point(x1,y1),Point(x2,y2),GetColor(mpss[i].col),1);
					}
				}
				
				if(POINTS_UNIT == mpss[i].typ)
				{
					Scalar c = GetColor(mpss[i].col);
					for (int j=0;j<mpss[i].nums;j++)
					{
						int x = (int)floor((mpss[i].dps[j].x-xmin)/stepw);
						int y = (int)floor((mpss[i].dps[j].y-ymin)/steph);
						x = MIN(MAX(x,0),w-1);
						y = MIN(MAX(y,0),h-1);
						img.at<Vec3b>(y,x) = Vec3b(c.val[0],c.val[1],c.val[2]);
						//circle(img,Point(x,y),1,GetColor(mpss[i].col));
					}
				}
				
				if(CIRCLES_UNIT == mpss[i].typ)
				{
					for (int j=0;j<mpss[i].nums;j++)
					{
						int x = (int)floor((mpss[i].dps[j].x-xmin)/stepw);
						int y = (int)floor((mpss[i].dps[j].y-ymin)/steph);
						x = MIN(MAX(x,0),w-1);
						y = MIN(MAX(y,0),h-1);
						circle(img,Point(x,y),4,GetColor(mpss[i].col));
					}
				}
			}
			
			//对图像进行坐标系转换  左下角坐标
			flip(img, img, 0);
			
			imshow(m_ImgTitle.c_str(),img);
			if(path!=NULL)
				imwrite( path,img);
		}
		
		void CDrawPoint2D::SetCircleRuningTime( vector<DrawPoint>& pts ,TypeColor tr)
		{
			
			DrawPts p(pts);
			p.col = tr;
			p.typ = CIRCLES_UNIT;
			mpss.push_back(p);
			ShowMps();
		}
		
		void CDrawPoint2D::SetLinesRuningTime( vector<DrawPoint>& pts,TypeColor tr/*=TYPES_WHITE*/ )
		{
			DrawPts p(pts);
			p.col = tr;
			p.typ = LINES_UNIT;
			mpss.push_back(p);
			ShowMps();
		}
		
		void CDrawPoint2D::SetTagsRuningTime( char* cs ,TypeColor tr)
		{
			DrawPts p;
			p.col = tr;
			p.typ = TAGS_UNIT;
			p.str = string(cs);
			mpss.push_back(p);
			ShowMps();
			
		}
		
		void CDrawPoint2D::WriteImg( const char* path )
		{
			ShowMps(path);
		}

}
