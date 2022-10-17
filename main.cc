#include<iostream>

#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

Color RayColor(const Ray &r)
{
    Vec3 unitDirection = UnitVector(r.Direction());
    auto t = 0.5*(unitDirection.y()+1.0);
    return (1.0 - t)*Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
}

int main()
{
    //Image
    const auto aspectRatio = 16.0 / 9.0;
    
    const int imageWidth = 400;
    const int imageHeight = static_cast<int>(imageWidth/aspectRatio);

    //Camera
    auto viewPortHeight = 2.0;
    auto viewPortWidth = aspectRatio * viewPortHeight;
    auto focalLength = 1.0;

    auto origin = Point3(0,0,0);
    auto horizontal = Vec3(viewPortWidth,0,0);
    auto vertical = Vec3(0, viewPortHeight,0);

    auto lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0,0,focalLength);

    //Render
    std::cout<<"P3\n"<<imageWidth<<' '<<imageHeight<<"\n255\n";

    for (int j = imageHeight -1 ;  j >=0; --j)
    {
        std::cerr <<"\rScanlines remaining "<<j<<std::flush;
        for (int i = 0; i < imageWidth; i++)
        {
            auto u = double(i)/(imageWidth-1);
            auto v = double(j)/(imageHeight-1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixelColor = RayColor(r);
            WriteColor(std::cout, pixelColor);
        }
        
    }
    std::cerr<<"\nDone\n";
}