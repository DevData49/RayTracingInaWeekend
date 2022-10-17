#include<iostream>

#include "Vec3.h"
#include "Color.h"

int main()
{
    //Image
    const int image_width = 255;
    const int image_height = 255;

    //Render
    std::cout<<"P3\n"<<image_width<<' '<<image_height<<"\n255\n";

    for (int j = image_height -1 ;  j >=0; --j)
    {
        std::cerr <<"\rScanlines remaining "<<j<<std::flush;
        for (int i = 0; i < image_width; i++)
        {
            Color pixelColor = Vec3(
                double(i)/image_width,
                double(j)/image_height,
                .25
            );
            WriteColor(std::cout, pixelColor);
        }
        
    }
    std::cerr<<"\nDone\n";
}