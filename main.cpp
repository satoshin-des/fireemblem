#include "DxLib.h"

#include "core.h"
#include "key.h"
#include "game_manager.h"
#include "opening.h"
#include "title.h"
#include "mode_select.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Opening opening;
	Title title;
	ModeSelect mode_select;
	GameManager game;

	SetOutApplicationLogValidFlag(FALSE);

	if (DxLib_Init() == -1)
	{
		errorBox("初期化時に予期せぬエラーが発生しました．");
		return -1;
	}

	if (ChangeWindowMode(TRUE) == -1)
	{
		errorBox("ウィンドウモード遷移時に予期せぬエラーが発生しました．");
		return -1;
	}
	SetGraphMode(WIDTH_X, WIDTH_Y, 32);
	SetWindowSize(WIDTH_X, WIDTH_Y);
	SetDrawScreen(DX_SCREEN_BACK);
	SetMainWindowText(TITLE_TEXT);

	Scene game_state = Scene::OPENING;

	if (gameInit() == -1)
	{
		errorBox("初期化時に予期せぬエラーが発生しました．");
		return -1;
	}

	while (ProcessMessage() == 0)
	{
		checkKeyState();

		if (ClearDrawScreen() == -1)
		{
			return -1;
		}

		switch (game_state)
		{
		case Scene::OPENING:
			opening.init();
			opening.update(game_state);
			opening.draw();
			break;

			// タイトル画面（初期画面）
		case Scene::TITLE:
			title.init();
			title.update(game_state);
			title.draw();
			break;

		case Scene::MODE_SELECT:
			mode_select.init();
			mode_select.update(game_state);
			mode_select.draw();
			break;

		case Scene::EXTRA:
			//game_state = game.Extra();
			break;

		case Scene::SCENE1:
			//game_state = game.Scene1();
			break;

		case Scene::SCENE2:
			//game_state = game.Scene2();
			break;

		case Scene::GAME_END:
			DxLib_End();
			return 0;
		}

		if (ScreenFlip() == -1)
		{
			errorBox("裏画面の表画面への反映時に予期せぬエラーが発生しました．");
			return -1;
		}
	}

	DxLib_End();
	return 0;
}