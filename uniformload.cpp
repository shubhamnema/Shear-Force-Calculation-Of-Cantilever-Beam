#include <iostream>
#include "load.cpp"
#include "point.cpp"
class uniformload : public load{
protected:
          float  weight;
          float  length;
          point udl_application_point;
public:
        uniformload(point tempP , float tempW , float tempD)
        {
            udl_application_point = tempP;
            weight = tempW;
            length = tempD;
        }
        float computeEffectiveWeight(point x)
        {
         return (udl_application_point.getPoint() >= x.getPoint())? getEffectiveLoad():0;
        }
private:
        float getEffectiveLoad()
          {  return ((weight * length)/2);
                }


};
