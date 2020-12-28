#include "Image.hpp"
#include "RGBColor.hpp"
#include "../world/ViewPlane.hpp"
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <string>

Image::Image(int hres, int vres) //creating array
{
    this->hres = hres;
    this->vres = vres;

    this->colors = new RGBColor*[this->hres];

    for (int i = 0; i < (this->hres); i++)
    {
        colors[i] = new RGBColor[this->vres];
    }
}

Image::Image(const ViewPlane &vp)
{
    this->hres = vp.get_hres();
    this->vres = vp.get_vres();

    this->colors = new RGBColor*[this->hres];

    for (int i = 0; i < (this->hres); i++)
    {
        colors[i] = new RGBColor[this->vres];
    }
}

Image::~Image()
{
    for (int i = 0; i < this->hres; i++)
    {
        delete [] this->colors[i];
    }
    delete [] this->colors;
}

void Image::set_pixel(int x, int y, const RGBColor& color)
{
    this->colors[y][x] = color;
}

void Image::write_ppm(std::string path) const
{
    std::ofstream file(path);
    file << "P3" << "\n";
    file << hres << " " << vres << "\n";
    file << 255 << "\n";
    double maxCol = 0.0;

    for (int i = 0; i < this->vres; i++) //finding max of rgbs
    {
        for(int j = 0; j < this->hres; j++)
        {
            double curCol = std::max({this->colors[i][j].r, this->colors[i][j].g, this->colors[i][j].b});
            if (curCol > maxCol)
            {
                maxCol = curCol;
            }
        }
    }
    if (maxCol < 1)
        maxCol = 1;
    double scale = 255/maxCol;
    for (int i = 0; i < this->vres; i++) //scaling rgbs
    {
        for(int j = 0; j < this->hres; j++)
        {
            file << std::to_string(scale * this->colors[i][j].r) << " " << std::to_string(scale * this->colors[i][j].g) << " " << std::to_string(scale * this->colors[i][j].b) << "\t";
        }
        file << "\n";
    }
    file.close();

}
