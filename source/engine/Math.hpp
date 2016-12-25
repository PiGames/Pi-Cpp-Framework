#ifndef MATH_H
#define MATH_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

class Math
{
    public:
        Math();
        virtual ~Math();

        static double PerlinNoise(double x, double y, double z);
    protected:

    private:


        static double fade(double t);
        static double lerp(double t, double a, double b);
        static double grad(int hash, double x, double y, double z);
};

#endif // MATH_H
