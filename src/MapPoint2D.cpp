#include "MapPoint2D.h"
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "memory.h"
using namespace std;

namespace My
{

	namespace map2d
	{
	
		int MapPoints::WriteOdmAndFlam(const char* odmpath, const char* laserpath, bool isKeyFrame /*= true*/)
	{
		
		ofstream od(odmpath);
		
		ofstream fl;
		if(laserpath!=NULL)
			fl .open(laserpath);
		
		if (!od||!fl)
		{
			return -1;
		}
		
		for (size_t i=0;i<mps.size();i++)
		{
			if (mps[i]->pointFlag==PF_FRAMEPOINT||i==0)
			{
				od<<setiosflags(ios::fixed)<<setprecision(6)<<mps[i]->tm.tYear<<" "<<mps[i]->tm.tMonth<<" "<<mps[i]->tm.tDay<<" "<<mps[i]->tm.tHour<<" "<<mps[i]->tm.tMinute<<" "<<mps[i]->tm.tSecond<<" "<<mps[i]->tm.tMilliSecond<<"	"<<
				mps[i]->odom.y<<" "<<mps[i]->odom.x<<" "<<mps[i]->odom.thete<< " "<<mps[i]->pointFlag<<endl;
				
				if (laserpath!=NULL)
				{
					fl<<mps[i]->tm.tYear<<" "<<mps[i]->tm.tMonth<<" "<<mps[i]->tm.tDay<<" "<<mps[i]->tm.tHour<<" "
					<<mps[i]->tm.tMinute<<" "<<mps[i]->tm.tSecond<<" "<<mps[i]->tm.tMilliSecond<<" "<<mps[i]->lt.LaserNums<<endl;
					for (int j=0;j<mps[i]->lt.LaserNums;j++)
					{
						fl<<mps[i]->lt.laserData[j]<< " "<<mps[i]->lt.laserPoint[j].thete<<endl;
					}
					fl<<endl;
				}
				
			}
			else if (isKeyFrame)
			{
				od<<setiosflags(ios::fixed)<<setprecision(6)<<mps[i]->tm.tYear<<" "<<mps[i]->tm.tMonth<<" "<<mps[i]->tm.tDay<<" "<<mps[i]->tm.tHour<<" "<<mps[i]->tm.tMinute<<" "<<mps[i]->tm.tSecond<<" "<<mps[i]->tm.tMilliSecond<<" "<<
				mps[i]->odom.y<<" "<<mps[i]->odom.x<<" "<<mps[i]->odom.thete<< " "<<mps[i]->pointFlag<<endl;
				if (laserpath!=NULL)
				{
					fl<<setiosflags(ios::fixed)<<setprecision(6)<<mps[i]->tm.tYear<<" "<<mps[i]->tm.tMonth<<" "<<mps[i]->tm.tDay<<" "<<mps[i]->tm.tHour<<" "<<mps[i]->tm.tMinute<<" "<<mps[i]->tm.tSecond<<" "<<mps[i]->tm.tMilliSecond<<" "<<mps[i]->lt.LaserNums<<endl;
					for (int j=0;j<mps[i]->lt.LaserNums;j++)
					{
						fl<<mps[i]->lt.laserData[j]<< " "<<mps[i]->lt.laserPoint[j].thete<<endl;
					}
					fl<<endl;
				}
				
			}
			
		}
		
		
		return 1;
	}
	
	bool MapPoints::WriteOdmFile(vector<MapPoint*> mps,const char* odmpath)
	{
		ofstream od(odmpath);
		
		if (!od)
		{
			return false;
		}
		
		for (size_t i=0;i<mps.size();i++)
		{
			if (mps[i]->pointFlag!=PF_STOPPOINT)
			{
				od << setiosflags(ios::fixed) << setprecision(6) << mps[i]->tm.tYear << " " << mps[i]->tm.tMonth << " " << mps[i]->tm.tDay << " " << mps[i]->tm.tHour << " " << mps[i]->tm.tMinute << " " << mps[i]->tm.tSecond << " " << mps[i]->tm.tMilliSecond << " " <<
				mps[i]->odom.y << " " << mps[i]->odom.x << " " << mps[i]->odom.thete << " " << mps[i]->pointFlag << endl;
			}
			
		}
		
		return true;
	}
	
	
	vector<MapPoint*> MapPoints::ReadOdmfile( const char* odmpath )
	{
		vector<MapPoint*> odms;
		
		char* odbuf = GetFileBuf(odmpath);
		
		stringstream od(odbuf);
		
		if (!od)
			return odms;
		
		
		string isOd;
		
		int maxData = 0;
		for (int i=0;;i++)
		{
			getline(od,isOd);
			if( od.eof())
			{
				if (isOd == "")
				{
					maxData = i;
				}
				else
				{
					maxData = i + 1;
				}
				break;
			}
		}
		od.clear();
		od.seekg(0,ios::beg);
		//mps.reserve(maxData+1);
		
		for (int i=0;i<maxData;i++)
		{
			MapPoint* p = new MapPoint(0);
			
			isOd.clear();
			std::getline(od,isOd);
			
			sscanf(isOd.c_str(),"%d%d%d%d%d%d%d%f%f%f%d",&p->tm.tYear,&p->tm.tMonth,&p->tm.tDay,&p->tm.tHour,
					 &p->tm.tMinute,&p->tm.tSecond,&p->tm.tMilliSecond,&p->odom.y,&p->odom.x,&p->odom.thete,&p->pointFlag);
			
			odms.push_back(p);
			
		}
		
		delete odbuf;
		
		return odms;
	}
	
	
	int MapPoints::SetOnePatch(MapPoint* mp)
	{
		MapPoint* p = new MapPoint(mp->lt.LaserNums);
		p->isProcessed = mp->isProcessed;
		p->pointFlag = mp->pointFlag;
		p->odom = mp->odom;
		//将坐标转置，使之符合GMapping的坐标系
		p->odom.x = mp->odom.y;
		p->odom.y = mp->odom.x;
		
		
		p->tm = mp->tm;
		
		for (int i=0;i<mp->lt.LaserNums;i++)
		{
			p->lt.laserData[i] = mp->lt.laserData[i];
			p->lt.laserPoint[i] = mp->lt.laserPoint[i];
			
			if (p->lt.laserData[i]>maxRange||p->lt.laserData[i]<minRange)
			{
				p->lt.laserData[i] = MAXLASERRANGE;
				mp->lt.laserData[i] = MAXLASERRANGE;
			}
			
			//新设备的角度过滤
			// 		 if (p->lt.laserPoint[i].thete < -M_PI*0.77 ||
			// 			 p->lt.laserPoint[i].thete>M_PI*0.77	||
			// 			(p->lt.laserPoint[i].thete > -M_PI*0.66 && p->lt.laserPoint[i].thete<-M_PI*0.48) || 
			// 			(p->lt.laserPoint[i].thete > M_PI*0.48  && p->lt.laserPoint[i].thete<M_PI*0.66) )
			// 		 {
			// 			 p->lt.laserData[i] = MAXLASERRANGE;
			// 			 mp->lt.laserData[i] = MAXLASERRANGE;
			// 		 }
			
		}
		

		if (mps.size()==0)
		{
			baseOdom = p->odom;
		}
		
		while(p->odom.thete<0.)
			p->odom.thete+=float(2*M_PI);
		while(p->odom.thete>= float(2*M_PI))
			p->odom.thete-= float(2*M_PI);
		
		// 	 p->odom.x -=baseOdom.x;
		// 	 p->odom.y -=baseOdom.y;
		// 	 p->odom.thete -=baseOdom.thete;
		
		p->Parse();
		// mp->Parse();
		mps.push_back(p);
		
		return 1;
	}
	
	int MapPoints::SetStopPatch()
	{
		int endidx = mps.size();
		if (!endidx)
		{
			return -1;
		}
		if (mps[endidx-1]->pointFlag!=PF_STOPPOINT)
		{
			MapPoint* p = new MapPoint(this->laserNums);
			p->pointFlag = PF_STOPPOINT;
			mps.push_back(p);
			return 1;
		}
		else
		{
			return 0;
		}
		
		
		return 1;
	}
	
	
	
	char* MapPoints::GetFileBuf( const char* path )
	{
		filebuf* fbuf;
		ifstream fi;
		fi.open(path, ios::binary);
		long long siz;
		char* buf;
		
		if (!fi)
		{
			return NULL;
		}
		fbuf = fi.rdbuf();
		siz = fbuf->pubseekoff(0, ios::end, ios::in);
		fbuf->pubseekpos(0, ios::in);
		buf = new char[(unsigned int)siz];
		fbuf->sgetn(buf, siz);
		fi.close();
		
		return buf;
	}
	
	
	string MapPoints::BufGetLine(char* buf, int& index)
	{
		int i = 0;
		char mybuf[4096];
		memset(mybuf, '\0', 4096);
		for (i=index;buf[i]!='\n';i++)
		{
			if (buf[i]=='\0')
			{
				index = i;
				return string("");
			}
			mybuf[i - index] = buf[i];
		}
		mybuf[i - index] = '\n';
		i++;
		index = i;
		
		return string(mybuf);
	}
	
	
	int MapPoints::InPutDataFast(const char* odmpath,const char* laserpath , bool iskeyframe,int nNums)
	{
		
		char* odbuf = GetFileBuf(odmpath);
		char* lpbuf = GetFileBuf(laserpath);
		
		int index = 0;
		
		stringstream od(odbuf);
		//stringstream lp(lpbuf);
		
		if (!od)
			return -1;
		
		string isOd,isLm;
		
		int maxData = 0;
		for (int i=0;;i++)
		{
			getline(od,isOd);
			if(isOd == ""||od.eof())
			{
				maxData = i;
				break;
			}
		}
		od.clear();
		od.seekg(0,ios::beg);
		//mps.reserve(maxData+1);
		
		//getline(lp,isLm);
		isLm = BufGetLine(lpbuf, index);
		stringstream iss(isLm);
		int nbeams;
		iss>>nbeams>>nbeams>>nbeams>>nbeams>>nbeams>>nbeams>>nbeams>>nbeams;
		//	 lp.clear();
		//	 lp.seekg(0,ios::beg);
		laserNums = nbeams;
		
		if (nNums>0)
		{
			maxData = maxData>nNums?nNums:maxData;
		}
		for (int i=0;i<maxData;i++)
		{
			MapPoint* p = new MapPoint(nbeams);
			
			
			isOd.clear();isLm.clear();
			std::getline(od,isOd);
			// std::getline(lp,isLm);
			isLm = BufGetLine(lpbuf, index);
			
			
			int flag = 0;
			
			
			sscanf(isOd.c_str(),"%d%d%d%d%d%d%d%f%f%f%d",&p->tm.tYear,&p->tm.tMonth,&p->tm.tDay,&p->tm.tHour,
					 &p->tm.tMinute,&p->tm.tSecond,&p->tm.tMilliSecond,&p->odom.x,&p->odom.y,&p->odom.thete,&p->pointFlag);
			
			
			for (int j=0;j<nbeams;j++)
			{
				//std::getline(lp,isLm);
				isLm = BufGetLine(lpbuf, index);
				
				sscanf(isLm.c_str(),"%f%f",&p->lt.laserData[j],&p->lt.laserPoint[j].thete);
				
			}
			isLm = BufGetLine(lpbuf, index);
			
			if (iskeyframe)
			{
				if (p->pointFlag)
				{
					SetOnePatch(p);
				}
			}
			else
			{
				SetOnePatch(p);
			}
			
			
			delete p;
			
		}
		
		SetStopPatch();
		
		
		delete odbuf;
		delete lpbuf;
		return 1;
	}

	}
		
}