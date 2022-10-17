#include<iostream>

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
            auto r = double(i) / image_width;
            auto g = double(j)/image_height;
            auto b = .25;

            int ir = static_cast<int>(255.99*r);
            int ig = static_cast<int>(255.99*g);
            int ib = static_cast<int>(255.99*b);

            std::cout<<ir<<' '<<ig<<' '<<ib<<'\n';
        }
        
    }
    std::cerr<<"\nDone\n";
}