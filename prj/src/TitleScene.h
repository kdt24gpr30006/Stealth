#pragma once

#include "SceneManager.h"

class TitleScene : public Scene
{

public:

	// コンストラクタ
	TitleScene(std::shared_ptr<SceneManager> pManager) : Scene(pManager) {}
	~TitleScene(){}

	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Render();
};
