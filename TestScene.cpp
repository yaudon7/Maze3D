#include "TestScene.h"


//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),hModel_(-1)
{
	speed_ = 10.0f;
}

//初期化
void TestScene::Initialize()
{
	hModel_ = Model::Load("saikoro.fbx");
}

//更新
void TestScene::Update()
{
	transform_.rotate_.y += speed_;
	transform_.position_.x += 0.01f;
	transform_.scale_ = { 5.0f,5.0f,5.0f };
}

//描画
void TestScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void TestScene::Release()
{
}
