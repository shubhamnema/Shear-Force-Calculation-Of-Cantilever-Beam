# include <iostream>
#include "load.cpp"
#include "point.cpp"
class cantilever_beam
{
private:
        float length;
       load** l = new load*[loadcounter];
        int counter;
        int loadcounter;
public:
        cantilever_beam(float len , int loadnumber){
          counter = 0;
          length = len;
          loadcounter = loadnumber;
        }

        void addLoad(load *tempL){
          if(counter <= 9){
            l[counter] = tempL;
            counter++;
          }
        }



        float totalShearForce(point x){
          float tempSF = 0;
          for (int count = 0; count <= counter-1; count++){

            tempSF += l[count]->computeEffectiveWeight(x);
          }
          return tempSF;
        }
};
