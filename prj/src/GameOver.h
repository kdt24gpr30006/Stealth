#pragma once
#include "SceneManager.h"

class GameOverScene : public Scene
{
	public:
	// コンストラクタ
	GameOverScene(std::shared_ptr<SceneManager> pManager) : Scene(pManager) {}
	~GameOverScene(){}
	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Render();
};