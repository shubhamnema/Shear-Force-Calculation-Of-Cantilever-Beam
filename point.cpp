#ifndef point_cpp
#define point_cpp
#include <iostream>

class point{
private:
        float distance_from_origin;
public:
        point(){};

        point(const point &p){
          distance_from_origin = p.distance_from_origin;
        };

        point (float x)
        {
          distance_from_origin = x;
        }

        int getPoint(){
          return distance_from_origin;
        }
};
#endif
