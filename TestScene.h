#pragma once
#include "Engine/GameObject.h"

class Food;
class Text;
class Player;

//テストシーンを管理するクラス
class TestScene : public GameObject
{
public:
	TestScene(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void AddScore(int score) { myScore_++; }
private:
	Text* pText_;//スコア表示用のテキスト
	int myScore_;//現在スコア
	Food* food_;//フードのアドレスを保持する変数
	int rstFood_;//残りフード数
	int sumFood_;//合計フード数
	Player* pPlayer_;//プレイヤーのアドレスを保持する変数
};