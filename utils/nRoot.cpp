//#include <cmath>

namespace math{
    long double abs(long double x);
    long double nRoot(long double base, int n);
}

long double nPow(long double base, int exp);

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