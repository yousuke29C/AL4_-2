#pragma once
#include "DebugText.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Sprite.h"
#include "DebugCamera.h"
#include "Object3d.h"

#include "Enum.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class TitleScene
{
private: // �ÓI�����o�ϐ�
	static const int debugTextTexNumber = 0;

public://�����o�֐�

	/// <summary>
	/// �R���X�g�N���^
	/// </summary>
	TitleScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TitleScene();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize(DirectXCommon* dxCommon, Input* input);


	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	Scene GetNextScene() { return nextScene_; }

	int GetChangeFlag() { return changeFlag_; }
private:
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	DebugText debugText;
	DebugCamera* camera = nullptr;

	//�f�o�b�O�J�����L��
	bool isDebugCameraActive_ = false;

	Scene nextScene_ = Scene::TITLE;

	int changeFlag_ = false;
	//�X�v���C�g
	Sprite* spriteBG = nullptr;
};


