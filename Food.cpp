#include "Food.h"
#include "Engine/Model.h"
#include "TestScene.h"



int Food::sum_food_ = 0;
int Food::rest_food_ = 0;

Food::Food(GameObject* parent)
	:GameObject(parent, "Food"), hModel_(-1), score_(0), sum_score_(0)
{
}

Food::~Food()
{
}

void Food::Initialize()
{

	pPlayer = (Player*)FindObject("Player");


}

void Food::Update()
{

	transform_.rotate_.y += 1.0f;
}

void Food::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Food::Release()
{
}

void Food::SetFood()
{
	SphereCollider* collider = new SphereCollider(XMFLOAT3{ 0,1.0f,0 }, 1.0f);
	AddCollider(collider);
	hModel_ = Model::Load("Food.fbx");
	score_ = 1;
	sum_food_++;
	rest_food_++;

}

void Food::OnCollision(GameObject* pTarget)
{
	if (pTarget == nullptr)
	{
		return;
	}


	if (pTarget->GetObjectName() == "Player")
	{
		TestScene* test = dynamic_cast<TestScene*>(GetParent()->GetParent());
		if (test) {
			test->AddScore(score_);
		}

		rest_food_--;
		KillMe();
	}
}
