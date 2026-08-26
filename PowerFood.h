#pragma once
#include "Engine/GameObject.h"

class Player;

class PowerFood :
	public GameObject
{
public:


	PowerFood(GameObject* parent);
	~PowerFood();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget)override;
	void SetPowerFood();
	static	int GetRestFood() { return rest_food_; }
	static int GetSumFood() { return sum_food_; }
private:
	Player* pPlayer;
	int hModel_;
	int score_;
	int sum_score_;
	static int sum_food_;
	static int rest_food_;
};

