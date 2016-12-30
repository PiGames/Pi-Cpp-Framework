#include "WorldGenerator.hpp"

int WorldGenerator::actualTextureNumber = 1;
int WorldGenerator::width, WorldGenerator::height, WorldGenerator::accuracy= 6;

float WorldGenerator::calculateWeight(int i)
{
    float v = 0.5f;
    for(int j = 0; j<6-i; j++)
    {
        v = v / 2.f;
    }
    return v;
}

void WorldGenerator::changeContrast(float* source, int width, int height, float power)
{
    int * LUT = new int[255];
    for (int i=0; i<256; i++)
    {
    float newValue = (power*(i-127)+127);
    if (newValue > 255)
        LUT[i] = 255;
    else if (newValue < 0)
        LUT[i] = 0;
    else
        LUT[i] = newValue;
    }

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            int index = (i*width+j);
            source[index] = ((float)LUT[(int)(source[index] * 255)]/255.f);
        }
    }

}

float * WorldGenerator::Generate(int width, int height, int seed, int accurancy)
{
        height = height;
        width = width;
        accuracy = accurancy;

        float * basicTex = new float[width*height];
        float * finalTex = new float[width*height];

        Math::PerlinNoiseInit();
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                float val = Math::PerlinNoise(x / (float)width * seed, y / (float)height * seed,1);
                basicTex[y*width+x] = val;
                finalTex[y*width+x] = val * calculateWeight(1);
            }
        }

        doMagicalStuff(basicTex, finalTex,width,height);
        changeContrast(finalTex,width,height, 5.f);

        return finalTex;
        delete basicTex;

}

void WorldGenerator::bilinearInterpolation(int sourceWidth, int sourceHeight, int destWidth, int destHeight, float* source, float* newImage)
{
    float ratiox = (float)sourceWidth/(float)destWidth;
    float ratioy = (float)sourceHeight/(float)destHeight;

    for (int i=0; i<destHeight; i++)
    {
          for (int j=0; j<destWidth; j++)
          {
              float x = j*ratiox;
              float y = i*ratioy;
              float x0 = floor(x);
              float y0 = floor(y);
              float dx = x - x0;
              float dy = y - y0;
              int x1 = x0 + 1;
              int y1 = y0 + 1;
              if (x1 >= sourceWidth) x1 = x0;
              if (y1 >= sourceHeight) y1 = y0;
              int indexSrc00 = (y0*sourceWidth+x0);
              int indexSrc01 = (y0*sourceWidth+x1);
              int indexSrc10 = (y1*sourceWidth+x0);
              int indexSrc11 = (y1*sourceWidth+x1);
              int indexDst = (i*destWidth+j);

              newImage[indexDst] = (1.0-dy) * ((1.0-dx)*source[indexSrc00] + dx*source[indexSrc01]) +
              dy* ((1.0-dx)*source[indexSrc10] + dx*source[indexSrc11]);
          }
    }

}


void WorldGenerator::doMagicalStuff(float* mainTex, float* finalTex, int width, int height)
{

        float* smallNewTex = new float[width*height/4];
        float* smallNewTexCopy = new float[width*height/4];

        for(int y = 0; y<(height/2); y++)
            for(int x = 0; x<(width/2); x++)
            {
                smallNewTex[y*(width/2)+x] = mainTex[y*width+x];
                smallNewTexCopy[y*(width/2)+x] = mainTex[y*width+x];
            }



        actualTextureNumber++;

        float* newTex = new float[width*height];
        bilinearInterpolation(width/2,height/2,width,height,smallNewTex,newTex);

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                float newValue = newTex[y*width+x]*calculateWeight(actualTextureNumber) + finalTex[y*width+x];
                finalTex[y *width + x] = newValue;
            }
        }
        delete smallNewTex;

        if (actualTextureNumber < accuracy)
        {
            doMagicalStuff(smallNewTexCopy,finalTex,width/4,height/4);
        }
        else
        {
            delete smallNewTexCopy;
        }

}
