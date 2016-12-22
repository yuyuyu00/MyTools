#ifndef IMUDATA_H
#define IMUDATA_H



#include <iostream>
#include <vector>

using namespace std;


namespace My
{

	class IMUData
	{
	public:
// 		IMUData(const IMUData& p);
		
		
		
	public:
		double m_accx,m_accy,m_accz;
		double m_gryx,m_gryy,m_gryz;
		double m_tm;

		int m_imutype;//同IMUDatas
	private:
		
	};


	class IMUDatas
	{
	public:
		IMUDatas();
		~IMUDatas();
		
		bool ReadData(const char* path,int filetype=0);
		
		bool SetOnePatch(IMUData& p,int imutype);
		
	public:
		vector<IMUData*> m_dat;
		int m_filetype = 0;
		int m_imutype=0; // 0.为谷歌imu激光 1.我们的xsens激光 
	};

}


#endif
