#pragma once
#include "DxLib.h"
#include <string>

class Image
{
public:
	// �摜�n���h��
	int image;

	Image() : image(-1) {}
	~Image() 
	{
		// �摜�̉��
		if (image != -1) {
			DeleteGraph(image);
		}
	}

	// �摜�̓ǂݍ���
	void Load(const std::string& filename)
	{
		image = LoadGraph(filename.c_str());
	}
};