#include "WorldHeightmapGenerator.hpp"

namespace pi
{
	uint8_t WorldHeightmapGenerator::subMapsToGenerate = 6;
	uint8_t WorldHeightmapGenerator::alreadyGeneratedSubMapsCount = 1;
	uint16_t WorldHeightmapGenerator::width;
	uint16_t WorldHeightmapGenerator::height;

	float WorldHeightmapGenerator::calculateWeight( uint8_t i )
	{
		float valueToReturn = 0.5f;
		for ( int j = 0; j < WorldHeightmapGenerator::subMapsToGenerate - i; ++j )
		{
			valueToReturn = valueToReturn / 2.f;
		}
		return valueToReturn;
	}

	void WorldHeightmapGenerator::changeContrast( float* source, int width, int height, float power )
	{
		uint8_t * lookUpTable = new uint8_t[256];

		for ( uint16_t i = 0; i < 256; ++i )
		{
			float newValue = ( power*( i - 127 ) + 127 );
			if ( newValue > 255 )
				lookUpTable[i] = 255;
			else if ( newValue < 0 )
				lookUpTable[i] = 0;
			else
				lookUpTable[i] = newValue;
		}

		for ( uint16_t i = 0; i < height; ++i )
		{
			for ( uint16_t j = 0; j < width; ++j )
			{
				uint16_t index = ( i*width + j );
				source[index] = ( (float)lookUpTable[(int)( source[index] * 255 )] / 255.f );
			}
		}
		delete[] lookUpTable;

	}

	float * WorldHeightmapGenerator::Generate( int width, int height, int seed, int accurancy )
	{
		WorldHeightmapGenerator::height = height;
		WorldHeightmapGenerator::width = width;
		WorldHeightmapGenerator::subMapsToGenerate = accurancy;

		float * secondaryHeightmap = new float[width*height];
		float * finalHeightmap = new float[width*height];

		Math::PerlinNoiseInit();
		for ( int y = 0; y < height; ++y )
		{
			for ( int x = 0; x < width; ++x )
			{
				float heightValue = Math::PerlinNoise( x / (float)width * seed, y / (float)height * seed, 1 );
				secondaryHeightmap[y * width + x] = heightValue;
				finalHeightmap[y * width + x] = heightValue * calculateWeight( 1 );
			}
		}

		mergeMaps( secondaryHeightmap, finalHeightmap, width, height );
		changeContrast( finalHeightmap, width, height, 5.f );

		delete[] secondaryHeightmap;
		return finalHeightmap;

	}

	void WorldHeightmapGenerator::bilinearInterpolation( int sourceWidth, int sourceHeight, int destinationWidth, int destinationHeight, float* source, float* newImage )
	{
		float ratioX = (float)sourceWidth / (float)destinationWidth;
		float ratioY = (float)sourceHeight / (float)destinationHeight;

		for ( int i = 0; i < destinationHeight; ++i )
		{
			for ( int j = 0; j < destinationWidth; ++j )
			{
				float x = j*ratioX;
				float y = i*ratioY;
				float x0 = floor( x );
				float y0 = floor( y );
				float dx = x - x0;
				float dy = y - y0;
				int x1 = x0 + 1;
				int y1 = y0 + 1;
				if ( x1 >= sourceWidth ) x1 = x0;
				if ( y1 >= sourceHeight ) y1 = y0;
				int indexSrc00 = ( y0*sourceWidth + x0 );
				int indexSrc01 = ( y0*sourceWidth + x1 );
				int indexSrc10 = ( y1*sourceWidth + x0 );
				int indexSrc11 = ( y1*sourceWidth + x1 );
				int indexDst = ( i*destinationWidth + j );

				newImage[indexDst] = ( 1.0 - dy ) * ( ( 1.0 - dx )*source[indexSrc00] + dx*source[indexSrc01] ) +
					dy* ( ( 1.0 - dx )*source[indexSrc10] + dx*source[indexSrc11] );
			}
		}

	}


	void WorldHeightmapGenerator::mergeMaps( float* mainHeightmap, float* finalHeightmap, int width, int height )
	{

		float* smallerPartOfMainHeightmap = new float[width*height / 4];
		float* smallerPartOfMainHeightmapCopy = new float[width*height / 4];

		for ( int y = 0; y < ( height / 2 ); y++ )
			for ( int x = 0; x < ( width / 2 ); x++ )
			{
				smallerPartOfMainHeightmap[y*( width / 2 ) + x] = mainHeightmap[y*width + x];
				smallerPartOfMainHeightmapCopy[y*( width / 2 ) + x] = mainHeightmap[y*width + x];
			}



		alreadyGeneratedSubMapsCount++;

		float* newTex = new float[WorldHeightmapGenerator::width*WorldHeightmapGenerator::height];
		bilinearInterpolation( width / 2, height / 2, WorldHeightmapGenerator::width, WorldHeightmapGenerator::height,
			smallerPartOfMainHeightmap, newTex );

		for ( int y = 0; y < WorldHeightmapGenerator::height; y++ )
		{
			for ( int x = 0; x < WorldHeightmapGenerator::width; x++ )
			{
				float newValue = newTex[y*WorldHeightmapGenerator::width + x] *
					calculateWeight( alreadyGeneratedSubMapsCount ) + finalHeightmap[y*WorldHeightmapGenerator::width + x];
				finalHeightmap[y * WorldHeightmapGenerator::width + x] = newValue;
			}
		}
		delete[] smallerPartOfMainHeightmap;

		if ( alreadyGeneratedSubMapsCount < WorldHeightmapGenerator::subMapsToGenerate )
		{
			mergeMaps( smallerPartOfMainHeightmapCopy, finalHeightmap, width / 4, height / 4 );
		} else
		{
			delete[] smallerPartOfMainHeightmapCopy;
		}

	}
}

