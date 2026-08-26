#include "GameOverScene.h"
#include "Engine/Text.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOverScene"),pText_(nullptr)
{
}

void GameOverScene::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();
}

void GameOverScene::Update()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	//Enter
	if (Input::IsKeyDown(DIK_RETURN))
	{
		pSceneManager->ChangeScene(SCENE_ID_START);
	}
}

void GameOverScene::Draw()
{
	pText_->Draw(500, 200, "TITLE TO ENTER");
}

void GameOverScene::Release()
{
}
