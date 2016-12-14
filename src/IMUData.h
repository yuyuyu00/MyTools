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
		
	private:
		
	};


	class IMUDatas
	{
	public:
		IMUDatas();
		~IMUDatas();
		
		bool ReadData(const char* path);
		
		bool SetOnePatch(IMUData& p);
		
	public:
		vector<IMUData*> m_dat;
		
	};

}


#endif
