#pragma once

#include <cstdarg>
#include <iostream>
#include <cmath>
#include "engine/Math.hpp"

class WorldGenerator
{
    public:
        WorldGenerator();
        virtual ~WorldGenerator();

        float * Generate(int width, int height, int seed, int accuracy);
    protected:

    private:
        int actualTextureNumber = 1;
        int width,height, accuracy = 6;

        void doMagicalStuff(float* mainTex, float* finalTex, int width, int height);
        inline float calculateWeight(int i);
        void bilinearInterpolation(int sourceWidth, int sourceHeight, int destWidth, int destHeight, float* source, float* newImage);
        void changeContrast(float* source, int width, int height, float power);


};
