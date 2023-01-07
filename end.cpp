#include "end.h"

EndScene::EndScene(){}

EndScene::~EndScene(){
	delete spriteBG;
}

void EndScene::Initialize(DirectXCommon* dxCommon, Input* input)
{
	// nullptr�`�F�b�N
	assert(dxCommon);
	assert(input);

	this->dxCommon = dxCommon;
	this->input = input;
	nextScene_ = Scene::END;

	// �f�o�b�O�e�L�X�g�p�e�N�X�`���ǂݍ���
	Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png");
	// �f�o�b�O�e�L�X�g������
	debugText.Initialize(debugTextTexNumber);
	// �e�N�X�`���ǂݍ���
	Sprite::LoadTexture(4, L"Resources/End.png");

	// �J��������
	camera = new DebugCamera(WinApp::kWindowWidth, WinApp::kWindowHeight, input);

	// �J���������_���Z�b�g
	camera->SetEye({ 0,10,10 });
	camera->SetTarget({ 0, 1, 0 });
	camera->SetDistance(3.0f);

	// 3D�I�u�W�F�N�g�ɃJ�������Z�b�g
	Object3d::SetCamera(camera);

	// �w�i�X�v���C�g����
	spriteBG = Sprite::Create(4, { 0.0f,0.0f });
}

void EndScene::Update()
{
	changeFlag_ = false;
	if (input->TriggerKey(DIK_SPACE)) {
		changeFlag_ = true;
		nextScene_ = Scene::TITLE;
	}
}

void EndScene::Draw()
{
	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* commandList = dxCommon->GetCommandList();

#pragma region �w�i�X�v���C�g�`��
	// �w�i�X�v���C�g�`��O����
	Sprite::PreDraw(commandList);

	/// <summary>
	/// �����ɔw�i�X�v���C�g�̕`�揈����ǉ��ł���
	/// </summary>
	spriteBG->Draw();

	// �X�v���C�g�`��㏈��
	Sprite::PostDraw();
	// �[�x�o�b�t�@�N���A
	dxCommon->ClearDepthBuffer();
#pragma endregion

#pragma region 3D�I�u�W�F�N�g�`��
	// 3D�I�u�W�F�N�g�`��O����
	//Model::PreDraw(commandList);

	/// <summary>
	/// ������3D�I�u�W�F�N�g�̕`�揈����ǉ��ł���
	/// </summary>
	// 3D���f���`�� 

	// 3D�I�u�W�F�N�g�`��㏈��
	//Model::PostDraw();
#pragma endregion

#pragma region �O�i�X�v���C�g�`��
	// �O�i�X�v���C�g�`��O����
	Sprite::PreDraw(commandList);

	/// <summary>
	/// �����ɑO�i�X�v���C�g�̕`�揈����ǉ��ł���
	/// </summary>

	// �f�o�b�O�e�L�X�g�̕`��
	debugText.DrawAll(commandList);
	//
	// �X�v���C�g�`��㏈��
	Sprite::PostDraw();

}
