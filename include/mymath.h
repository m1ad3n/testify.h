#ifndef __MYMATH_H
#define __MYMATH_H

namespace MyMath
{
    int abs(int x)
    {
        x = ~x + 1;
        return x;
    }

    double sqrt(double x)
    {
        // this is just an example
        return x / x;
    }
};

#endif