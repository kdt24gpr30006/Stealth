#pragma once

#include <memory>

class SceneManager;

// �V�[���̊��N���X
class Scene
{
protected:
	// �V�[���}�l�[�W���[�ւ̎Q��
	std::shared_ptr<SceneManager> manager;
public:
	// �R���X�g���N�^
	// �V�[���}�l�[�W���[�̎Q�Ƃ��󂯎��
	Scene(std::shared_ptr<SceneManager> pManager) { manager = pManager; };

	virtual ~Scene() {}
	virtual void Init() = 0;	// ������
	virtual void Update() = 0;	// �X�V
	virtual void Render() = 0;	// �`��
};

class SceneManager
{

	// ���݂̃V�[��
	std::shared_ptr<Scene> currentScene;
public:

	SceneManager() {};
	virtual ~SceneManager() {}

	// �V�[���ύX
	void ChengeScene(std::shared_ptr<Scene> newScene)
	{
		// 古いシーンを解放するため nullptr に設定
		currentScene.reset();
		
		if (newScene) {
			currentScene = newScene;
			currentScene->Init();
		}
	}

	// �X�V
	void Update()
	{
		if (currentScene)
		{
			currentScene->Update();
		}


	}

	// �`��
	void Render()
	{
		if (currentScene)
		{
			currentScene->Render();
		}
	}
};