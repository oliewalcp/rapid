#include "TestImage.h"
#include "Image/BMP.h"
#include "Core/Matrix.h"
#include "Image/RGB.h"
#include "Algorithm/Image.h"
#include <string>
#include <iostream>

static std::string path("C:\\Users\\Administrator\\Desktop\\");
static std::string source_name("test.bmp");
static std::string destination_name("result.bmp");

void rapid::test_BMP_main()
{
    std::cout << "--------" << __func__ << " start---------" << std::endl;
    BMP b;
    b.parse((path + source_name).data());
    Matrix<RGBA> m = b.to_matrix();
    std::cout << "exchange finish" << std::endl;

    std::cout << "magnification" << std::endl;
    m = magnification::bilinear_interpolation(m, 2);
    std::cout << "filter" << std::endl;
//    m.filter({
//                 {1, 2, 1},
//                 {2, 4, 2},
//                 {1, 2, 1}
//             });
    m = filter(m, {
                   {-1, -1, -1},
                   {-1, 8, -1},
                   {-1, -1, -1}
               });
    std::cout << "filter finish" << std::endl;

    BMP bb;
    bb.parse(m);
    bb.write((path + destination_name).data());
    std::cout << "test end" << std::endl;
}
