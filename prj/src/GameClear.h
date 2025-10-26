#pragma once
#include "SceneManager.h"

class GameClearScene : public Scene
{
	public:
	// コンストラクタ
	GameClearScene(std::shared_ptr<SceneManager> pManager) : Scene(pManager) {}
	~GameClearScene() {}
	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Render();
};