#pragma once
#include "Engine/GameObject.h"

class Text;
//テストシーンを管理するクラス
class StartScene : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	StartScene(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Text* pText_;//Textのアドレスを保持する変数
};