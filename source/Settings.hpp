#pragma once

#include "fileManaging/INIparser.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Simple extension for pi::INIFile class. To get settings simple use Get methods.

	===============================================================================
	*/
class Settings final :
		public pi::INIFile
	{
	public:
		Settings( const Settings& ) = delete;
		Settings& operator=( const Settings& ) = delete;

		static Settings& GetInstance()
		{
			static Settings instance;
			return instance;
		}

		void GenerateDefault( const std::string& path )
		{
			this->AddString( "WINDOW", "TITLE", "'Platform Game'" );
			this->AddInt( "WINDOW", "FPS", 64 );
			this->AddInt( "WINDOW", "X", 1280 );
			this->AddInt( "WINDOW", "Y", 720 );

			this->SaveToFile( path, "; Default config. Don't change if you don't know what are you doing!" );
		}

	private:
		Settings()
		{}
	};
}