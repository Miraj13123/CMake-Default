#include <iostream>
#include <iomanip>
const long double pi = 3.14159265358979323846;

// sorry i made this repo's code more complex for beginners. u can use easy functions from other file by prototyping. example below

long double nPow(long double base, int exp)
{
    long double result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

namespace math{
    long double abs(long double x);
    long double nRoot(long double base, int n);
}

long double math::abs(long double x) // returns the positive value if negative
{
    return (x < 0) ? -x : x;
}

long double math::nRoot(long double base, int n)
{
    long double low = 0;
    long double high = base;
    long double epsilion = 0.0000000000001;
    long double guess;
    int itt = 0;
    int max_itt = 1000;

    while(itt < max_itt)
    {
        guess = (low + high) / 2;
        if( abs(nPow(guess, n)-base) < epsilion )
            return guess;
        else if(nPow(guess, n) < base)
            low = guess;
        else
            high = guess;
    }
    return -1; // If no root is found within the iterations

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