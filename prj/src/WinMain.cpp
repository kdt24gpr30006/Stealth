// ���C�u�����Ǎ�
#include "Game.h"
#include <memory>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	Game& game = Game::GetInstance(); // �V���O���g���C���X�^���X����

	// ����������
	if (game.Init() == false)
	{
		// Init()��false�ŋA���Ă����炻�̎��_�ŏI��
		return -1;
	}

	// �Q�[�����[�v
	game.Loop();

	// �I������
	game.End();


	// �\�t�g�̏I��
	return 0;
}