#include "Element.h"
#include "WinMain.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::shared_ptr<Wall>> Element::LoadWallInfo()
{
	// �t�@�C���ǂݍ���
	std::ifstream file("data/enemy/csv/WallInit.csv");

	// �ǂݍ��߂���
	if (!file.is_open()) {
		std::runtime_error error("�t�@�C���̓ǂݍ��݂Ɏ��s");
		throw error;
	}

	std::string line;
	// ��s�ڃX�L�b�v
	std::getline(file, line);

	// �Ԃ��ǂ̃x�N�^�[
	std::vector<std::shared_ptr<Wall>> retWalls;

    // �e�s��ǂݍ��݁A�G�L�����N�^�[���쐬
	while (std::getline(file, line))
	{
		std::stringstream lineStream(line);
		std::string cell;

		// �ǂݎ����
		Vec2<float> start, end;

		// CSV�̊e�J������ǂݍ���
		// X���W
		std::getline(lineStream, cell, ',');
		start.x = std::stof(cell);

		// Y���W
		std::getline(lineStream, cell, ',');
		start.y = std::stof(cell);

		// X���W
		std::getline(lineStream, cell, ',');
		end.x = std::stof(cell);

		// Y���W
		std::getline(lineStream, cell, ',');
		end.y = std::stof(cell);

		auto wall = std::make_shared<Wall>(start, end);

		retWalls.emplace_back(wall);
	}


	file.close();

	return retWalls;
}

void Element::Init()
{
	goalPos.Set((float)WINDOW_W / 2.0f, 50.0f);

	walls = LoadWallInfo();
}

void Element::Update()
{
}

void Element::Render() const
{
	DrawCircleAA(goalPos.x, goalPos.y, 50.0f, 32, GetColor(255, 255, 255), FALSE);
	for (const auto& wall : walls)
	{
		wall->Render();
	}
}
