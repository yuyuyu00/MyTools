#ifndef ORGDATA_H
#define ORGDATA_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace My
{
 struct PointType2D
  {
    union{ double dis;double x;};
    union{ double ang;double y;};
  };
  
 struct  PointType3D
  {
    double x,y,z;
  };
  
  class Point2dData
  {
  public:
    vector<PointType2D> m_dat;
    double m_tm;
    
  private:
    fstream m_fd;
    int m_type;
  public:
      bool init(const char* path,int type=0);
	
      bool GetOneData();
      
  };
  
  class Point3dData
  {
  public:
    vector<Point2dData> m_dat;
    double m_tm;
  private:
    fstream m_fd;
    
    public:
    
  //private:
    
  };
    
  
  
  
}



#endif