#pragma once

#include <memory>

class SceneManager;

// シーンの基底クラス
class Scene
{
protected:
	// シーンマネージャーへの参照
	std::shared_ptr<SceneManager> manager;
public:
	// コンストラクタ
	// シーンマネージャーの参照を受け取る
	Scene(std::shared_ptr<SceneManager> pManager) { manager = pManager; };

	virtual ~Scene() {}
	virtual void Init() = 0;	// 初期化
	virtual void Update() = 0;	// 更新
	virtual void Render() = 0;	// 描画
};

class SceneManager
{

	// 現在のシーン
	std::shared_ptr<Scene> currentScene;
public:

	SceneManager() {};
	virtual ~SceneManager() {}

	// シーン変更
	void ChengeScene(std::shared_ptr<Scene> newScene)
	{
		currentScene = newScene;
		currentScene->Init();
	}

	// 更新
	void Update() const
	{
		if (currentScene)
		{
			currentScene->Update();
		}


	}

	// 描画
	void Render() const
	{
		if (currentScene)
		{
			currentScene->Render();
		}
	}
};