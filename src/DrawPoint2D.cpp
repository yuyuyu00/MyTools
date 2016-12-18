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
			new (this)CDrawPoint2D("img");
		}
		
		CDrawPoint2D::CDrawPoint2D( char* title )
		{
			m_ImgTitle = string(title);
			m_stepw=m_steph=1.;
			
			m_h = 800;
			m_xmax = -DBL_MAX;
			m_ymax = -DBL_MAX;
			m_xmin = DBL_MAX;
			m_ymin = DBL_MAX;

			m_zmax = -DBL_MAX;
			m_zmin = DBL_MAX;

			m_showmode = MODE_AUTO;
		}
		
		

		void CDrawPoint2D::SetMapPoint3RuningTime(map3d::MapPoint3D& mp3, PointTypeUnit type /*= POINTS_UNIT*/, TypeColor tp /*= TYPES_WHITE*/)
		{
			DrawPts p;
			p.col=tp;
			p.typ = type;
			p.nums = mp3.size();
			p.dps = NULL;
			if (p.nums > 0)
			{
				p.dps = new DrawPoint[p.nums];
				for (int i = 0; i < p.nums; i++)
				{
					p.dps[i].x = mp3[i].x;
					p.dps[i].y = mp3[i].y;
					p.dps[i].z = mp3[i].z;
				}
			}

			mpss.push_back(p);
			ShowMps();
		}

		void CDrawPoint2D::SetDrawPTSRuningTime(DrawPts& pts)
		{
			DrawPts p(pts);
			mpss.push_back(p);
			ShowMps();
		}

		void CDrawPoint2D::SetPointsRuningTime(vector<DrawPoint>& pts, TypeColor tr)
		{
			DrawPts p(pts,POINTS_UNIT,tr);
			
			mpss.push_back(p);
			
			ShowMps();
		}
		
		void CDrawPoint2D::ClearData()
		{
			m_h = 800;
			
			m_xmax = -DBL_MAX;
			m_ymax = -DBL_MAX;
			m_xmin = DBL_MAX;
			m_ymin = DBL_MAX;
			
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
					if (mpss[i].col == TYPE_AUTO)
					{
						if (m_zmax < mpss[i].dps[j].z)
						{
							m_zmax = mpss[i].dps[j].z;
						}
						if (m_zmin > mpss[i].dps[j].z)
						{
							m_zmin = mpss[i].dps[j].z;
						}
					}


					if (m_xmax<mpss[i].dps[j].x)
					{
						m_xmax = mpss[i].dps[j].x;
					}
					if (m_xmin>mpss[i].dps[j].x)
					{
						m_xmin = mpss[i].dps[j].x;
					}
					if (m_ymax<mpss[i].dps[j].y)
					{
						m_ymax = mpss[i].dps[j].y;
					}
					if (m_ymin>mpss[i].dps[j].y)
					{
						m_ymin = mpss[i].dps[j].y;
					}
				}
				
			}
			double diffx = m_xmax-m_xmin;
			double diffy = m_ymax-m_ymin;
			
			if (diffx>0&&diffy>0)
			{
				int tmpw = (int)floor(m_h*diffx/diffy);
				
				
				if (m_showmode == MODE_INCRES && tmpw > m_w)
					m_w = tmpw;
				else
					m_w = tmpw;
				if (m_w>1500)
				{
					m_w=1500;
				}
				m_steph = diffy/m_h;
				m_stepw = diffx/m_w;
				
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
			if (m_w<=0)
			{
				return;
			}
			Mat img = Mat::zeros(m_h,m_w,CV_8UC3);
			
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
						int x1 = (int)floor((mpss[i].dps[j].x-m_xmin)/m_stepw);
						int x2 = (int)floor((mpss[i].dps[j+1].x-m_xmin)/m_stepw);
						int y1 = (int)floor((mpss[i].dps[j].y-m_ymin)/m_steph);
						int y2 = (int)floor((mpss[i].dps[j+1].y-m_ymin)/m_steph);
						x1 = MIN(MAX(x1,0),m_w-1);
						x2 = MIN(MAX(x2,0),m_w-1);
						y1 = MIN(MAX(y1,0),m_h-1);
						y2 = MIN(MAX(y2,0),m_h-1);
						line(img,Point(x1,y1),Point(x2,y2),GetColor(mpss[i].col),1);
					}
				}
				
				if(POINTS_UNIT == mpss[i].typ)
				{
					if (mpss[i].col == TYPE_AUTO)
					{
						double diffz = m_zmax - m_zmin;
						for (int j = 0; j < mpss[i].nums; j++)
						{
							int x = (int)floor((mpss[i].dps[j].x - m_xmin) / m_stepw);
							int y = (int)floor((mpss[i].dps[j].y - m_ymin) / m_steph);
							x = MIN(MAX(x, 0), m_w - 1);
							y = MIN(MAX(y, 0), m_h - 1);

							if (diffz > 0)
							{
								double zz = (mpss[i].dps[j].z - m_zmin)/diffz;
								int ca = (int)floor(255.*zz);
								int cb = 255 - ca;
								img.at<Vec3b>(y, x) = Vec3b(uchar(cb),uchar(80),uchar(ca));

							}
							else
								img.at<Vec3b>(y, x) = Vec3b(255,255,255);
							//circle(img,Point(x,y),1,GetColor(mpss[i].col));
						}
					}
					else
					{
						Scalar c = GetColor(mpss[i].col);
						for (int j = 0; j < mpss[i].nums; j++)
						{
							int x = (int)floor((mpss[i].dps[j].x - m_xmin) / m_stepw);
							int y = (int)floor((mpss[i].dps[j].y - m_ymin) / m_steph);
							x = MIN(MAX(x, 0), m_w - 1);
							y = MIN(MAX(y, 0), m_h - 1);

							img.at<Vec3b>(y, x) = Vec3b(c.val[0], c.val[1], c.val[2]);
							//circle(img,Point(x,y),1,GetColor(mpss[i].col));
						}
					}
				}
				
				if(CIRCLES_UNIT == mpss[i].typ)
				{
					for (int j=0;j<mpss[i].nums;j++)
					{
						int x = (int)floor((mpss[i].dps[j].x-m_xmin)/m_stepw);
						int y = (int)floor((mpss[i].dps[j].y-m_ymin)/m_steph);
						x = MIN(MAX(x,0),m_w-1);
						y = MIN(MAX(y,0),m_h-1);
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


		DrawPts::DrawPts(const DrawPts& dp)
		{
			col = dp.col;
			typ = dp.typ;
			nums = dp.nums;
			str = dp.str;

			dps = NULL;
			if (nums > 0)
			{
				dps = new DrawPoint[nums];
				for (int i = 0; i < nums; i++)
				{
					dps[i] = dp.dps[i];
				}
			}
		}

		DrawPts::DrawPts(vector<DrawPoint>& pts)
		{
			col = TYPES_WHITE;
			typ = POINTS_UNIT;
			nums = pts.size();

			dps = NULL;
			if (nums > 0)
			{
				dps = new DrawPoint[nums];
				for (int i = 0; i < nums; i++)
				{
					dps[i] = pts[i];
				}
			}
		}

		DrawPts::DrawPts(vector<DrawPoint>& pts, PointTypeUnit type)
		{
			col = TYPES_WHITE;
			typ = type;
			nums = pts.size();

			dps = NULL;
			if (nums > 0)
			{
				dps = new DrawPoint[nums];
				for (int i = 0; i < nums; i++)
				{
					dps[i] = pts[i];
				}
			}
		}

		DrawPts::DrawPts(vector<DrawPoint>& pts, PointTypeUnit type, TypeColor tp)
		{
			typ = type;
			col = tp;
			nums = pts.size();

			dps = NULL;
			if (nums > 0)
			{
				dps = new DrawPoint[nums];
				for (int i = 0; i < nums; i++)
				{
					dps[i] = pts[i];
				}
			}
		}


		DrawPts::DrawPts()
		{
			dps = NULL; nums = 0;
		}

		DrawPts::~DrawPts()
		{
			nums = 0;
			if (dps)
			{
				delete[] dps;
				dps = NULL;
			}
		}

		void DrawPts::clearDate()
		{
			nums = 0;
			if (dps)
			{
				delete[] dps;
				dps = NULL;
			}
		}

}
