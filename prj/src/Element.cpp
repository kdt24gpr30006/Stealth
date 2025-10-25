#include "Element.h"
#include "WinMain.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::shared_ptr<Wall>> Element::LoadWallInfo()
{
	// ファイル読み込み
	std::ifstream file("data/enemy/csv/WallInit.csv");

	// 読み込めたか
	if (!file.is_open()) {
		std::runtime_error error("ファイルの読み込みに失敗");
		throw error;
	}

	std::string line;
	// 一行目スキップ
	std::getline(file, line);

	// 返す壁のベクター
	std::vector<std::shared_ptr<Wall>> retWalls;

    // 各行を読み込み、敵キャラクターを作成
	while (std::getline(file, line))
	{
		std::stringstream lineStream(line);
		std::string cell;

		// 読み取る情報
		Vec2<float> start, end;

		// CSVの各カラムを読み込む
		// X座標
		std::getline(lineStream, cell, ',');
		start.x = std::stof(cell);

		// Y座標
		std::getline(lineStream, cell, ',');
		start.y = std::stof(cell);

		// X座標
		std::getline(lineStream, cell, ',');
		end.x = std::stof(cell);

		// Y座標
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
