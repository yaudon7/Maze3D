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
	Player* pPlayer;//Playerのアドレスを保持する変数
	int hModel_;//モデルのハンドル
	int score_;//スコア
	int sum_score_;//合計スコア
	static int sum_food_;//合計フード数
	static int rest_food_;//残りフード数
};

