#ifndef PLY_H
#define PLY_H
#include "../utilities/Point3D.hpp"
#include <vector>
#include <string.h>
#include <fstream>
using namespace std;


class Ply
{
    public:
        Ply(string name);
        virtual ~Ply();
        std::vector<Point3D> vertices;
        std::vector<std::vector<int>> indi;




    protected:

    private:
};

#endif // PLY_H
