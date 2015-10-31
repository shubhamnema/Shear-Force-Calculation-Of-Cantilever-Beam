#include <iostream>
#include "load.cpp"



class pointload : public load
{

protected:
          point p;
          float weight;
          int direction;
public:
        pointload(point tempP , float tempW , int tempD = 1)
        {
              p = tempP;
              weight = tempW;
              direction = tempD;
        }


        float computeEffectiveWeight(point x)
        {
         return (p.getPoint() >= x.getPoint())? getEffectiveLoad():0;
        }
private:
        float getEffectiveLoad(){
          
          return weight * direction;
        }

        // pointweightException invalidDirectionException = pointweightException("invalid point weight direction , expected +1 or -1");
};
