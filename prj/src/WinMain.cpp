// ���C�u�����Ǎ�
#include "Game.h"
#include <memory>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	// ����������
	Game::GetInstance().Init();

	// Init()��false�ŋA���Ă����炻�̎��_�ŏI��
	if (Game::GetInstance().Init() == false)
	{
		return -1;
	}

	// �Q�[�����[�v
	Game::GetInstance().Loop();

	// �I������
	Game::GetInstance().End();


	// �\�t�g�̏I��
	return 0;
}