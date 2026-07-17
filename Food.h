#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
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
private:
	FoodType type_;
	Player* pPlayer;
	Text* pText;
	int hModel_;
	int score_;
	int sum_score_;
};

