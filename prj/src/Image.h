#pragma once
#include "DxLib.h"
#include <string>

class Image
{
public:
	// ‰æ‘œƒnƒ“ƒhƒ‹
	int image;

	Image() : image(-1) {}
	~Image() 
	{
		// ‰æ‘œ‚Ì‰ğ•ú
		if (image != -1) {
			DeleteGraph(image);
		}
	}

	// ‰æ‘œ‚Ì“Ç‚İ‚İ
	void Load(const std::string& filename)
	{
		image = LoadGraph(filename.c_str());
	}
};