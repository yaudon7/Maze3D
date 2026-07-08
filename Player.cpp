#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "TestScene.h"
#include "Engine/Input.h"

namespace
{
	enum PLAYER_STATE
	{
		PLAYER_IDLE,
		PLAYER_WALK,
		PLAYER_STATE_MAX //状態の数
	};
	PLAYER_STATE pstate = PLAYER_STATE::PLAYER_IDLE; //プレイヤーの状態を管理する変数
}


Player::Player(GameObject* parent)
	:GameObject(parent), hWalkModel_(-1), hIdleModel_(-1) {
	//swordDirには、初期方向として、ローカルモデルの剣の根っこから
	//先端までのベクトルとして（0,1,0)を代入しておく
	//初期位置は原点
}

void Player::Initialize()
{
	hWalkModel_ = Model::Load("Walking.fbx");
	Model::SetAnimFrame(hWalkModel_, 0, 59, 1.0);

	hIdleModel_ = Model::Load("Idle.fbx");
	Model::SetAnimFrame(hIdleModel_, 0, 117, 1.0);


}

void Player::Update()
{
	XMVECTOR pos = XMLoadFloat3(&transform_.position_);
	XMVECTOR move = XMVectorSet(0, 0, 0, 0);
	const float SPEED = 0.05f;
	float angle = 0.0f;
	pstate = PLAYER_STATE::PLAYER_IDLE;

	if (Input::IsKey(DIK_LEFT))
	{
		angle = -90.0f;
		move = XMVectorSet(-1, 0, 0, 0);
		pstate = PLAYER_STATE::PLAYER_WALK;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		angle = 90.0f;
		move = XMVectorSet(1, 0, 0, 0);
		pstate = PLAYER_STATE::PLAYER_WALK;
	}
	if (Input::IsKey(DIK_UP))
	{
		angle = 0.0f;
		move = XMVectorSet(0, 0, 1, 0);
		pstate = PLAYER_STATE::PLAYER_WALK;
	}
	if (Input::IsKey(DIK_DOWN))
	{
		angle = 180.0f;
		move = XMVectorSet(0, 0, -1, 0);
		pstate = PLAYER_STATE::PLAYER_WALK;
	}
	transform_.rotate_.y = angle;
	pos = pos + SPEED * move;
	XMStoreFloat3(&transform_.position_, pos);
}

void Player::Draw()
{
	if (pstate == PLAYER_STATE::PLAYER_IDLE)
	{
		Model::SetTransform(hIdleModel_, transform_);
		Model::Draw(hIdleModel_);
	}
	else if (pstate == PLAYER_STATE::PLAYER_WALK)
	{
		Model::SetTransform(hWalkModel_, transform_);
		Model::Draw(hWalkModel_);
	}

}

void Player::Release()
{
}