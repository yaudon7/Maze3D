#include "Food.h"
#include "Engine/Model.h"
#include "TestScene.h"


int Food::sum_food_ = 0;
int Food::rest_food_ = 0;

Food::Food(GameObject* parent)
	:GameObject(parent,"Food"),type_(FOODTYPE_NORMAL),hModel_(-1),score_(0),sum_score_(0)
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
	if (type_ == FoodType::FOODTYPE_POWER)
	{
		transform_.rotate_.y += 1.0f;
	}
}

void Food::Draw()
{
	if (type_ == FoodType::FOODTYPE_NORMAL)
	{
		
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
	else if (type_ == FoodType::FOODTYPE_POWER)
	{

		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
}

void Food::Release()
{
}

void Food::SetFoodType(FoodType type)
{
	type_ = type;
	if (type_ == FoodType::FOODTYPE_NORMAL)
	{
		SphereCollider* collider = new SphereCollider(XMFLOAT3{ 0,1.0f,0 }, 1.0f);
		AddCollider(collider);
		hModel_ = Model::Load("Food.fbx");
		score_ = 1;
		sum_food_++;
		rest_food_++;
	}
	else if (type_ == FoodType::FOODTYPE_POWER)
	{
		SphereCollider* collider = new SphereCollider(XMFLOAT3{ 0,1.0f,0 }, 1.5f);
		AddCollider(collider);
		hModel_ = Model::Load("PowerFood.fbx");
		score_ = 5;
		sum_food_++;
		rest_food_++;
	}
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
