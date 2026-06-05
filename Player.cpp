#include "Player.h"
#include "Engine/Model.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
	speed_ = 1.0f;
}

void Player::Initialize()
{
	hModel_ = Model::Load("saikoro.fbx");

	
}

void Player::Update()
{
	//XMFLOAT4X4 matS{
	//	2.0f,0.0f,0.0f,0.0f,
	//	0.0f,2.0f,0.0f,0.0f,
	//	0.0f,0.0f,2.0f,0.0f,
	//	0.0f,0.0f,0.0f,1.0f
	//};//保存用のほう

	//XMFLOAT4X4 matRx{
	//	1.0f,0.0f,0.0f,0.0f,
	//	0.0f,cosf(XMConvertToRadians(xRot)),sinf(XMConvertToRadians(xRot)),0.0f,
	//	0.0f,-sinf(XMConvertToRadians(xRot)),cosf(XMConvertToRadians(xRot)),0.0f,
	//	0.0f,0.0f,0.0f,1.0f
	//};

	//XMFLOAT4X4 matRy{
	//	cosf(XMConvertToRadians(yRot)),0.0f,-sinf(XMConvertToRadians(yRot)),0.0f,
	//	0.0f,1.0f,0.0f,0.0f,
	//	sinf(XMConvertToRadians(yRot)),0.0f,cosf(XMConvertToRadians(yRot)),0.0f,
	//	0.0f,0.0f,0.0f,1.0f
	//};

	//XMFLOAT4X4 matRz{
	//	cosf(XMConvertToRadians(zRot)),sinf(XMConvertToRadians(zRot)),0.0f,0.0f,
	//	-sinf(XMConvertToRadians(zRot)),cosf(XMConvertToRadians(zRot)),0.0f,0.0f,
	//	0.0f,0.0f,1.0f,0.0f,
	//	0.0f,0.0f,0.0f,1.0f
	//};

	/*XMFLOAT4X4 matT{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		tx,   ty,  tz, 1.0f
	};*/

	static float xRot = 0.0f;//度
	static float yRot = 0.0f;
	float zRot = 0.0f;
	float tx = -2.0f, ty = 2.0f, tz = 0.0f;

	XMMATRIX translate = XMMatrixIdentity();
	XMMATRIX rotate = XMMatrixIdentity();
	XMMATRIX scale;
	XMMATRIX mRx, mRy, mRz;

	mRx = XMMatrixRotationX(xRot);
	mRy = XMMatrixRotationY(yRot);
	mRz = XMMatrixRotationZ(zRot);

	translate = XMMatrixTranslation(tx,ty,tz);
	rotate = mRz * mRx * mRy;
	scale = XMMatrixScaling(2.0f, 2.0f, 2.0f);

	XMMATRIX world = scale * rotate * translate;

	SetWorldMatrix(world);

	yRot += 0.05f;
	xRot += 0.025f;
}
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
