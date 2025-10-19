#include "GameScene.h"
#include "DxLib.h"
#include "WinMain.h"

void GameScene::Init()
{
	// �C���X�^���X�쐬
	player = std::make_shared<Player>();
	enemy.emplace_back(std::make_shared<Enemy>(Vec2<float>(static_cast<float>(WINDOW_W / 2 - 100), 200.0f), 0.0f, 50.0f, 100.0f, 4.0f));
	enemy.emplace_back(std::make_shared<Enemy>(Vec2<float>(static_cast<float>(WINDOW_W / 2 + 100), 400.0f), 90.0f, 30.0f, 100.0f, 4.0f));
}

void GameScene::Update()
{
	// ���݂̎����擾
	auto now = Clock::now();
	// �O�t���[���Ƃ̎��ԍ����v�Z
	std::chrono::duration<float> diff = now - prevTime;
	// �O�t���[������̌o�ߎ��Ԏ擾
	deltaTime = diff.count();
	// �O�t���[���̎����X�V
	prevTime = now;
	// ���o�ߎ��ԍX�V
	totalTime += deltaTime;

	// �X�V����
	player->Update((float)deltaTime);
	for (auto& e : enemy)
	{
		e->Update(totalTime);
	}
}

void GameScene::Render()
{
	// �`�揈��
	player->Render();
	for (auto& e : enemy)
	{
		// �v���C���[�������Ă��邩
		bool detected = e->CanSeePlayer(player);
		e->Draw(detected);
	}
}
