#include "Ply.h"
#include <iostream>
#include <string.h>
using namespace std;

Ply::Ply(string name)
{
    string myText;

    ifstream MyReadFile(name);
    bool flag = false;
    int count = 0;
    string temp;
    string countmax;
    string countindices;

    while (MyReadFile >> temp) {

        std::cout << myText<<endl;
        if (temp == "vertex")
        {
            MyReadFile >> temp;
            countmax = temp;
        }
        if (temp == "face")
        {
            MyReadFile >> temp;
            countindices = temp;
        }
        if (temp == "end_header")
        {
            flag = true;
            break;
        }
    }

    while (flag & count < stoi(countmax))
    {
        MyReadFile >> temp;
        float f0 = stof(temp);

        MyReadFile >> temp;
        float f1 = stof(temp);

        MyReadFile >> temp;
        float f2 = stof(temp);

        Point3D vert = Point3D(f1,f2,f0);

        this->vertices.push_back(vert);

        count++;
    }
    int count2 = 0;
    while (count2 < stoi(countindices))
    {
        MyReadFile >> temp;

        MyReadFile >> temp;
        int n1 = stoi(temp);

        MyReadFile >> temp;
        int n2 = stoi(temp);

        MyReadFile >> temp;
        int n3 = stoi(temp);

        std::vector<int> vec;
        vec.push_back(n1);
        vec.push_back(n2);
        vec.push_back(n3);

        this->indi.push_back(vec);
        count2++;
    }

    MyReadFile.close();
}

Ply::~Ply()
{
    //dtor
}
