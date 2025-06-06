long double nPow(long double base, int exp)
{
    long double result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}