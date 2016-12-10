#ifndef MAPPOINT2D_H
#define MAPPOINT2D_H
#include "Point2dData.h"

#include "math.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

namespace My
{
	namespace map2d
	{
		
		//最大字符串长度 可根据实际情况修改
		#define MAXSTRINGLENGTH 1024
		
		//最大构图数据节点 可根据实际情况修改
		#define MAXMAPPOINT 10000
		
		//最大一圈激光扫描点数  可根据实际情况修改
		#define MAXLASERPOINT 960
		
		//最大粒子数 可根据实际情况修改
		#define MAXPARTICLES 150
		
		//最大激光距离
		#define MAXLASERRANGE 100;
		
		
		
		//公共类型 2D Pos类型
		struct PointType
		{
			float x;
			float y;
			float thete;
			PointType(){x=y=thete=0;}
			PointType(float x, float y, float t){this->x=x;this->y=y;this->thete=t;}
			
			PointType operator +=(const PointType& p)
			{
				this->x += p.x;
				this->y += p.y;
				this->thete += p.thete;
				return (*this);
			}
			
			PointType operator -=(const PointType& p)
			{
				this->x -= p.x;
				this->y -= p.y;
				this->thete -= p.thete;
				return (*this);
			}
			PointType operator -(const PointType& p)
			{
				PointType t;
				t.x = this->x - p.x;
				t.y = this->y - p.y;
				t.thete = this->thete - p.thete;
				return t;
			}
			
			PointType operator +(const PointType& p)
			{
				PointType t;
				t.x = this->x + p.x;
				t.y = this->y + p.y;
				t.thete = this->thete + p.thete;
				return t;
			}
			PointType operator /(const int& p)
			{
				PointType t;
				t.x = this->x / p;
				t.y = this->y / p;
				t.thete = this->thete / p;
				return t;
			}
			PointType operator *(const int& p)
			{
				PointType t;
				t.x = this->x * p;
				t.y = this->y * p;
				t.thete = this->thete * p;
				return t;
			}
			
		};
		
		//激光数据类型
		class LaserType
		{
		public:
			int LaserNums;
			//static const int MaxLaserNums = MAXLASERPOINT;
			float* laserData;
			
			//需解析的数据
			PointType* laserPoint;
			
			LaserType(){LaserNums=0;}
			
			//根据给定的激光数，对激光数据初始化。
			void init(int lNums){LaserNums=lNums;laserData = new float[lNums];laserPoint=new PointType[lNums];}
			
			//处理完后，用于激光数据销毁
			void destroy()
			{
				LaserNums = 0;
				if(laserData)
				{
					delete laserData;
					laserData = NULL;
				}
				if(laserPoint)
				{
					delete laserPoint;
					laserPoint = NULL;
				}
			}
			
			~LaserType(){
				if(laserData)
				{
					delete laserData;
					laserData = NULL;
				}
				if(laserPoint)
				{
					delete laserPoint;
					laserPoint = NULL;
				}
			}
		};
		
		//时间类型
		struct TimeType
		{
			unsigned int tYear;
			unsigned int tMonth;
			unsigned int tDay;
			unsigned int tHour;
			unsigned int tMinute;
			unsigned int tSecond;
			unsigned int tMilliSecond;
		};
		
		//帧类型, GMapping处理的帧包括 普通帧,关键帧,停止帧
		enum FrameType { PF_COMMONPOINT,PF_FRAMEPOINT,PF_STOPPOINT};
		
		//图的单个节点类型
		struct MapPoint
		{
			TimeType tm;		//每圈激光的时间
			PointType odom;		//每圈激光对应的位姿
			LaserType lt;		//激光数据
			FrameType pointFlag;		//当前结点是否被跳过 用于结果显示。
			bool isProcessed;	//当前帧是否处理标记
			
			//默认构造函数，没有初始化激光数据和粒子数据，需要手动初始化其值
			MapPoint(){pointFlag = PF_COMMONPOINT;isProcessed=false;};
			//根据激光和粒子数据进行初始化
			MapPoint(int lNums){pointFlag = PF_COMMONPOINT;isProcessed=false;lt.init(lNums);};
			
			~MapPoint(){};
			
			//根据数据解析每个激光坐标
			void Parse()
			{
				float tmp = 0;//+M_PI/2;
				for (int i=0;i<lt.LaserNums;i++)
				{
					lt.laserPoint[i].x =odom.x + lt.laserData[i]*cos(tmp+odom.thete+lt.laserPoint[i].thete);
					lt.laserPoint[i].y =odom.y + lt.laserData[i]*sin(tmp+odom.thete+lt.laserPoint[i].thete);
				}
			}
		};
		
		class MapPoints
		{
		public:
			MapPoints()
			{
				minRange = 0.1;
				maxRange = 80;
			}
			//输入数据进MapPoint
			int InPutDataFast(const char* odmpath,const char* laserpath, bool iskeyframe = false,int Nums = 0);
			
			//写出关键帧数据
			int WriteOdmAndFlam(const char* odmpath,const char* laserpath=NULL,bool isKeyFrame = true);
			
			
			
			bool WriteOdmFile(vector<MapPoint*> mps,const char* odmpath);
			
		private:
			//以MapPoint数据类型输入
			int SetOnePatch(MapPoint* p);
			
			//输入结束结点
			int SetStopPatch();
			
			//读取文件至内存
			char* GetFileBuf(const char* path);
			
			string BufGetLine(char* buf, int& index);
			
			vector<MapPoint*> ReadOdmfile(const char* odmpath);


			
		public:
			//激光数
			unsigned int laserNums;
			
			//构图数据
			vector<MapPoint*> mps;
			
			//初始odom，GMapping坐标系，写结果时转置。
			PointType baseOdom;
			
			
		private:
			double minRange;//激光最近距离
			
			double maxRange; // 激光最远有效距离
		};
		
	
		
		
	}
}




#endif