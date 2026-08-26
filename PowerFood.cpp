#include "PowerFood.h"
#include "Engine/Model.h"
#include "TestScene.h"

int PowerFood::sum_food_ = 0;
int PowerFood::rest_food_ = 0;


PowerFood::PowerFood(GameObject* parent)
	:GameObject(parent, "PowerFood"), hModel_(-1), score_(0), sum_score_(0)
{
}

PowerFood::~PowerFood()
{
}

void PowerFood::Initialize()
{
	pPlayer = (Player*)FindObject("Player");

}

void PowerFood::Update()
{
	transform_.rotate_.y += 1.0f;
}

void PowerFood::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void PowerFood::Release()
{
}

void PowerFood::SetPowerFood()
{
	SphereCollider* collider = new SphereCollider(XMFLOAT3{ 0,1.0f,0 }, 1.5f);
	AddCollider(collider);
	hModel_ = Model::Load("PowerFood.fbx");
	score_ = 5;
	sum_food_++;
	rest_food_++;

}


void PowerFood::OnCollision(GameObject* pTarget)
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

