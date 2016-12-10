#ifndef DRAWPOINT2D_H
#define DRAWPOINT2D_H

#include <vector>
#include <string>
using namespace std;

//���ڲ��ԵĽṹ�壬����opencv��ͼ�������Լ�����

namespace My 
{
		
		struct DrawPoint
		{
			double x;
			double y;
			double z;
		};
		
		enum PointTypeUnit{POINTS_UNIT,CIRCLES_UNIT,LINES_UNIT,TAGS_UNIT};
		
		enum TypeColor{TYPES_WHITE,TYPES_GREEN,TYPES_RED,TYPES_BLUE};
		
		class DrawPts
		{
		public:
			string str;
			DrawPoint* dps;
			int nums;
			PointTypeUnit typ; 
			TypeColor col;
			DrawPts(){dps = NULL;nums = 0;}
			
			~DrawPts()
			{
				nums = 0;
				if (dps)
				{
					delete [] dps;
					dps = NULL;
				}
			}
			
			inline void clearDate()
			{
				nums = 0;
				if (dps)
				{
					delete [] dps;
					dps = NULL;
				}
			}
			
			
			DrawPts(const DrawPts& dp)
			{
				col = dp.col;
				typ = dp.typ;
				nums = dp.nums;
				str  = dp.str;
				
				dps = NULL;
				if (nums>0)
				{
					dps = new DrawPoint[nums];
					for (int i=0;i<nums;i++)
					{
						dps[i] = dp.dps[i];
					}
				}
				
			}
			DrawPts(vector<DrawPoint>& pts)
			{
				col = TYPES_WHITE;
				typ = POINTS_UNIT;
				nums = pts.size();
				
				dps = NULL;
				if (nums>0)
				{
					dps = new DrawPoint[nums];
					for (int i=0;i<nums;i++)
					{
						dps[i] = pts[i];
					}
				}
				
			}
			
			DrawPts(vector<DrawPoint>& pts,PointTypeUnit type)
			{
				col = TYPES_WHITE;
				typ = type;
				nums = pts.size();
				
				dps = NULL;
				if (nums>0)
				{
					dps = new DrawPoint[nums];
					for (int i=0;i<nums;i++)
					{
						dps[i] = pts[i];
					}
				}
				
			}
			DrawPts(vector<DrawPoint>& pts,PointTypeUnit type,TypeColor tp)
			{
				typ = type;
				col = tp;
				nums = pts.size();
				
				dps = NULL;
				if (nums>0)
				{
					dps = new DrawPoint[nums];
					for (int i=0;i<nums;i++)
					{
						dps[i] = pts[i];
					}
				}
				
			}
			
		};
		
		// �����Ǵ� DrawPoint2D.dll ������
		class  CDrawPoint2D {
		public:
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
			int w,h;//ͼ����
			
			vector<DrawPts> mpss;
			
			double xmax,ymax,xmin,ymin;
			
			double stepw,steph;//ÿ�����صľ���
			
			string m_ImgTitle;
			
			
		};
		
		extern  int nDrawPoint2D;
		
		int fnDrawPoint2D(void);
		
}


#endif