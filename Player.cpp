#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "TestScene.h"
#include "Engine/Input.h"
#include "Ground.h"

namespace
{
	enum PLAYER_STATE
	{
		PLAYER_IDLE,
		PLAYER_WALK,
		PLAYER_TURN,
		PLAYER_STATE_MAX //状態の数
	};

	PLAYER_STATE pstate = PLAYER_STATE::PLAYER_IDLE; //プレイヤーの状態を管理する変数
	float adjustAngle(float angle);
	enum PLAYER_DIRECTION
	{
		PLAYER_UP,
		PLAYER_DOWN,
		PLAYER_LEFT,
		PLAYER_RIGHT,
		PLAYER_DIRECTION_MAX
	};

	PLAYER_DIRECTION pdirection = PLAYER_DIRECTION::PLAYER_DOWN;
	float P_ANGLE[PLAYER_DIRECTION_MAX] = { 0.0f,180.0f,-90.0f,90.0f };
	float TURN_FRAME = 30.0f;
	float start_turn_angle = 0.0f;
	float end_turn_angle = 0.0f;
	//回転中に別の方向に回転するために必要（今は不要）
	PLAYER_DIRECTION turnEndDirection = PLAYER_DIRECTION::PLAYER_DOWN;

	float adjustAngle(float start, float end)
	{
		float diff = end - start;
		//180～-180度の範囲内に収めると最短経路が求まる
		if (diff > 180.0f)
		{
			diff -= 360.0f;
		}
		else if (diff < -180.0f)
		{
			diff += 360.0f;
		}

		return diff;
	}

	std::vector<std::vector<int>> gmap;
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
	static float turn_frame = 0.0f;//回転中のフレームを管理する変数

	//turn中は待機モードにしない
	if (pstate != PLAYER_STATE::PLAYER_TURN)
	{
		pstate = PLAYER_STATE::PLAYER_IDLE;
	}

	PLAYER_DIRECTION oldDir = pdirection;//今の向き

	//ターン中は入力を受け付けない
	if (pstate != PLAYER_STATE::PLAYER_TURN)
	{
		if (Input::IsKey(DIK_LEFT))
		{
			pdirection = PLAYER_LEFT;
			move = XMVectorSet(-1, 0, 0, 0);
			pstate = PLAYER_STATE::PLAYER_WALK;
		}
		if (Input::IsKey(DIK_RIGHT))
		{
			pdirection = PLAYER_RIGHT;
			move = XMVectorSet(1, 0, 0, 0);
			pstate = PLAYER_STATE::PLAYER_WALK;
		}
		if (Input::IsKey(DIK_UP))
		{
			pdirection = PLAYER_UP;
			move = XMVectorSet(0, 0, 1, 0);
			pstate = PLAYER_STATE::PLAYER_WALK;
		}
		if (Input::IsKey(DIK_DOWN))
		{
			pdirection = PLAYER_DOWN;
			move = XMVectorSet(0, 0, -1, 0);
			pstate = PLAYER_STATE::PLAYER_WALK;
		}
	}

	//ターンモードの初期化
	if (oldDir != pdirection)
	{
		pstate = PLAYER_STATE::PLAYER_TURN;
		turn_frame = 0.0f;
		start_turn_angle = P_ANGLE[oldDir];
		end_turn_angle = P_ANGLE[pdirection];

		turnEndDirection = pdirection;
	}

	pos = pos + SPEED * move;
	XMStoreFloat3(&transform_.position_, pos);

	XMFLOAT3 wpos = transform_.position_;
	//壁に食い込んだら戻す
 	gmap = ground_->GetMapData();//マップデータを取得
	//壁の判定
	int mapX = (int)((wpos.x) + 10) / 2;
	int mapZ = (int)(10 - (wpos.z)) / 2;
	if (gmap[mapZ][mapX] == 1)
	{
		pos = pos - SPEED * move;
		XMStoreFloat3(&transform_.position_,pos);
	}

	if (pstate == PLAYER_STATE::PLAYER_TURN)
	{
		turn_frame += 1.0f;

		float t = (turn_frame / TURN_FRAME) + 0.5f;

		if (t > 1.0f)
		{
			t = 1.0f;
			turn_frame = TURN_FRAME;
		}

		float diff = adjustAngle(start_turn_angle, end_turn_angle);
		transform_.rotate_.y = start_turn_angle + diff * t;//補間で一定の割合ずつ回転

		if (turn_frame >= TURN_FRAME)
		{
			//pdirection = turnEndDirection;
			//transform_.rotate_.y = P_ANGLE[pdirection];
			pstate = PLAYER_STATE::PLAYER_WALK;
		}
		return;
	}
	else if (pstate != PLAYER_STATE::PLAYER_TURN)
	{
		//transform_.rotate_.y = P_ANGLE[pdirection];
	}

	/*pdirection = turnEndDirection;
	transform_.rotate_.y = P_ANGLE[pdirection];
	pstate = PLAYER_STATE::PLAYER_WALK;*/
}

void Player::Draw()
{
	if (pstate == PLAYER_STATE::PLAYER_IDLE)
	{
		Model::SetTransform(hIdleModel_, transform_);
		Model::Draw(hIdleModel_);
	}
	else if (pstate == PLAYER_STATE::PLAYER_WALK || pstate == PLAYER_STATE::PLAYER_TURN)
	{
		Model::SetTransform(hWalkModel_, transform_);
		Model::Draw(hWalkModel_);
	}
}

void Player::Release()
{
}