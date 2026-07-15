#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Engine//Camera.h"


//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Player* pPlayer = Instantiate<Player>(this);
	Ground* pGround = Instantiate<Ground>(this);
	pPlayer->SetGround(pGround);

	Camera::SetPosition(XMFLOAT3(0, 20, -10));
	Camera::SetTarget(XMFLOAT3(0, 5, -2));
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
