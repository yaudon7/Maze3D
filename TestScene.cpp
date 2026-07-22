#include "TestScene.h"
#include "Ground.h"
#include "Engine//Camera.h"
#include "Engine//Text.h"
#include "Food.h"


namespace {
	int myScore = 10;
}
//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Ground* pGround = Instantiate<Ground>(this);
	pText_ = new Text;
	pText_->Initialize();


	Camera::SetPosition(XMFLOAT3(0, 20, -15));
	Camera::SetTarget(XMFLOAT3(0, 5, -2));
}

//更新
void TestScene::Update()
{
		rstFood_= Food::GetRestFood();
		sumFood = Food::GetSumFood();
}

//描画
void TestScene::Draw()
{
	std::string scrText;
	scrText = "Score:" + std::to_string(myScore_);
	pText_->Draw(600, 20, scrText.c_str());

	std::string foodText;
	foodText = "RestFood:" + std::to_string(rstFood_);
	pText_->Draw(20, 20, foodText.c_str());
	
}

//開放
void TestScene::Release()
{
	pText_->Release();
}
