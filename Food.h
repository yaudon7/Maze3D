#pragma once
#include "Engine/GameObject.h"

class Player;

enum FoodType {
	FOODTYPE_NORMAL,
	FOODTYPE_POWER,
	FOODTYPE_MAX
};

class Food :
	public GameObject
{
public:
	

	Food(GameObject* parent);
	~Food();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void SetFoodType(FoodType type);
	void OnCollision(GameObject* pTarget)override;
    static	int GetRestFood()  { return rest_food_; }
	static int GetSumFood()  { return sum_food_; }
private:
	FoodType type_;
	Player* pPlayer;
	int hModel_;
	int score_;
	int sum_score_;
	static int sum_food_;
	static int rest_food_;
};

