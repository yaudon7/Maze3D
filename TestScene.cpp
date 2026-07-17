#include "TestScene.h"
#include "Ground.h"
#include "Food.h"
#include "Engine//Camera.h"


//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Ground* pGround = Instantiate<Ground>(this);
	Food* pFood;


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
