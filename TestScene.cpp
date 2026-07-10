#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Block.h"
#include "Engine//Camera.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Ground>(this);
	Instantiate<Block>(this);
	Camera::SetPosition(XMFLOAT3(0, 20, -8));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));
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
