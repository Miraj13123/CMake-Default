#include <iostream>
#include <iomanip>
const long double pi = 3.14159265358979323846;

// sorry i made this repo's code more complex for beginners. u can use easy functions from other file by prototyping. example below

long double nPow(long double base, int exp);     // this a function prototyping, the function exists in utils folder
                                            // use mingw if you wanna dont wanna use namespace or functions name like 'abs' will conflict
                                            // even if u didn't include cmath or any standard lib but clang stictly adds them or checks similarity
                                            //                                      use mingw if u wanna avoid this issue
namespace math{
    long double abs(long double x);
    long double nRoot(long double base, int n);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <base> <exponent>" << std::endl;
        //return 1;
    }

    //long double base = std::stold(argv[1]);
    //int exponent = std::stoi(argv[2]);
    std::cout << std::fixed << std::setprecision(9);
    //std::cout << nRoot(base, exponent);

    long double test[][2] = {
        {144.0, 2.0},
        {169.0, 2.0},
        {1000.0, 3.0},
        {27.0, 3.0},
        {16.0, 4.0},
        {81.0, 2.0},
        {32.0, 5.0},
        {243.0, 5.0},
        {1024.0, 10.0},
        {625.0, 4.0},
        {256.0, 8.0},
        {9.0, 2.0},
        {8.0, 3.0},
        {100.0, 2.0},
        {10000.0, 4.0}
    };

    long double epsilion = 0.0000000000001;
    std::cout << "epsilion = " << epsilion << std::endl;


    for (int i = 0; i < 15; i++) {
        long double a = test[i][0];
        long double b = test[i][1];
        long double root = math::nRoot(a, b);

        std::cout << std::setprecision(0) << b << " root "  << std::setprecision(0) << a << " = " << std::setprecision(3) << root <<" ";

        if( math::abs(nPow(root, b)-a) > epsilion ) {
            std::cout << "is incorrect" << std::endl;
        } else {
            std::cout << "is correct" << std::endl;
        }
    }

    return 0;
}




/*
cmake -S . -B bin -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=g++
            # -G "Unix Makefiles"
            # -G "Ninja"
            # -G "MinGW Makefiles"
            # -G "Visual Studio 17 2022"
cmake --build bin
            # optional --target <target_name>
                # --target run    {to compile and run}
                # --target build_with_intermediates

*/