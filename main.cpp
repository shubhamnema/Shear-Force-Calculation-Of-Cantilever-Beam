#include <iostream>
#include <string>
#include "point.cpp"
#include "uniformload.cpp"
#include "load.cpp"
#include "cantilever_beam.cpp"
#include "pointload.cpp"


main()
{

int counter , token;
std::string type;
float beamlenght ,distancefromorigin,loadvalue , lenght;
std::cout << "Enter the total number of weight to be added on beam" << std::endl;
std::cin >> counter;
point** pnt = new point*[counter];
pointload** pl = new pointload*[counter];
uniformload** udl = new uniformload*[counter];
std::cout << "Enter the lenght of the beam  " << std::endl;
std::cin >> beamlenght;
cantilever_beam beam = cantilever_beam(beamlenght , counter);

for(int j = 0 ; j <counter ; j++)
{
std::cout << "Enter type of weight Point or UDL" << std::endl;
std::cin >> type;
for(int i = 0;i<type.length();i++)
{
  type[i]=  toupper(type[i]);
}
  if(type == "POINT")
  {
  std::cout << "Enter the distance from pivoted end of the beam " << std::endl;
  std::cin >> distancefromorigin;

  if(distancefromorigin > beamlenght)
  {
    std::cout << "invalid distance" << std::endl;
    return 0;

  }

  pnt [j] = new point(distancefromorigin);
  std::cout << "Enter the load value" << std::endl;
  std::cin >> loadvalue;

  pl[j] =new pointload(*pnt[j] , loadvalue , 1);

  beam.addLoad(*(pl+j));
}
else if(type == "UDL")
{
  std::cout << "Enter the distance from pivoted end of the beam " << std::endl;
  std::cin >> distancefromorigin;

  if(distancefromorigin > beamlenght)
  {
    std::cout << "Invalid application point" << std::endl;
    return 0;

  }

  pnt [j] = new point(distancefromorigin);
  std::cout << "Enter the UDL load value" << std::endl;
  std::cin >> loadvalue;
  std::cout << "Enter the lenght of UDL" << std::endl;
  std::cin >> lenght;
  udl[j] =new uniformload(*pnt[j] , loadvalue , lenght);
  beam.addLoad(*(udl+j));

}


}



float sf = beam.totalShearForce(point(1.0));
std::cout <<"Shear force at the end of the beam  is "<< sf << std::endl;


  return 0;

}
