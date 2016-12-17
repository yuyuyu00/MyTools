#ifndef POINT2DDATA_H
#define POINT2DDATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

namespace My
{
 struct PointType2D
  {
    union{ double dis;double x;};
    union{ double ang;double y;};
  };
  
  

  class Point2dData
  {
    
public:
      bool init(const char* path,int type=0);
	
      int GetOneData();
      
      
      
public:
    vector<PointType2D> m_dat;
    double m_tm;
    
private:
    fstream m_fd;
    int m_type;
    
  };
  
  
  
  
  
  
}



#endif