#include "Element.h"
#include "WinMain.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::shared_ptr<Wall>> Element::LoadWallInfo()
{
	// ファイル読み込み
	std::ifstream file("data/wall/WallInit.csv");

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
		Vec2<float> leftUp, leftDown, rightDown, rightUp;

		// CSVの各カラムを読み込む
		// 左上の座標
		std::getline(lineStream, cell, ',');
		leftUp.x = std::stof(cell);
		std::getline(lineStream, cell, ',');
		leftUp.y = std::stof(cell);

		// 左下の座標
		std::getline(lineStream, cell, ',');
		leftDown.x = std::stof(cell);
		std::getline(lineStream, cell, ',');
		leftDown.y = std::stof(cell);

		// 右下の座標
		std::getline(lineStream, cell, ',');
		rightDown.x = std::stof(cell);
		std::getline(lineStream, cell, ',');
		rightDown.y = std::stof(cell);

		// 右上の座標
		std::getline(lineStream, cell, ',');
		rightUp.x = std::stof(cell);
		std::getline(lineStream, cell, ',');
		rightUp.y = std::stof(cell);

		auto wall = std::make_shared<Wall>(leftUp, leftDown, rightDown, rightUp);

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

void Element::Render() const
{
	DrawCircleAA(goalPos.x, goalPos.y, goalRadius, 32, GetColor(255, 255, 255), FALSE);
	for (const auto& wall : walls)
	{
		wall->Render();
	}
}
