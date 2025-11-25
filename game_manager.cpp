#include "game_manager.h"
#include <vector>

int GameManager:: Opening()
{
	return TITLE;

	int time = 0;
	Keyboard key_board;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		key_board.GetKeyState();
		DrawFormatString(0, 0, GetColor(PINK), "こんにちは");
		key_board.SaveKeyState();
		++time;
		if (time == 600)
		{
			return TITLE;
		}
		FPS(60);
	}
	return 0;
}

int GameManager::Title()
{
	
	LPCSTR font_path = "SawarabiMincho-Regular.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	ChangeFont("Sawarabi Mincho", DX_CHARSET_DEFAULT);
	

	Button start_button;				// スタートボタン
	Button quit_button;				// 終了ボタン
	//Background back_ground;			// 背景
	Keyboard key_board;
	//CharaMove chara_move;
	Character character;



	int num_index = 2;				// 項目数
	int cursor = 0;					// 現在のカーソル位置

	key_board.SetIndexNum(num_index);

	start_button.SetButtonNumber(num_index);
	quit_button.SetButtonNumber(num_index);

	//start_button.LoadArrowImage("gazo_gamedx/Yajirushi.png");
	//quit_button.LoadArrowImage("gazo_gamedx/Yajirushi.png");

	//const int title = LoadGraph("gazo_gamedx/title.png");
	//const int title_illust = LoadGraph("gazo_gamedx/title_illust.png");

	start_button.SetOrder(0);
	quit_button.SetOrder(1);

	int time_count = 0;//OPに飛ぶため
	//int a = chara_move.c_titleM;
	//a = 0;
	int x = 0, flag = 0; // title_illustの座標

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		character.StatusOutput(characters, "ベレス");
		character.LevelUp(characters, "ベレス");



		key_board.GetKeyState();

		//back_ground.Title();

		//DrawGraph(x, 0, title_illust, TRUE);	//titleイラスト
		if (flag == 1)
		{
			x += 2;
		}
		if (x == 20)
		{
			flag = 0;
			return MODE_SELECT;
		}

		key_board.MoveCursor(cursor);

		//DrawGraph(50, 100, title, TRUE);	//title 描画

		start_button.SetCursor(cursor);
		start_button.Text("START", TITLEFONTSIZE);
		start_button.Draw(100, 500);

		// 終了ボタンの描画
		quit_button.SetCursor(cursor);
		quit_button.Text("END", TITLEFONTSIZE);
		quit_button.Draw(100, 550);
		quit_button.DrawArrow();

		if (start_button.IsPushed())
		{
			flag = 1;
		}

		if (quit_button.IsPushed())
		{
			return GAME_END;
		}

		/*
		++time_count;
		if (time_count >= 3600) //一分放置するとOPに飛ぶ
		{
			return __OPENING__;
		}
		*/

		key_board.SaveKeyState();

		FPS(60);
	}
	return 0;
}


int GameManager::ModeSelect()
{
	Button start_button;				// はじめから
	Button continue_button;			// つづきから
	Button extra_button;				// エクストラボタン
	Button quit_button;				// 終了ボタン
	//Background back_ground;			// 背景
	Keyboard key_board;

	int num_index = 4;				// 項目数
	int cursor = 0;					// 現在のカーソル位置

	key_board.SetIndexNum(num_index);

	start_button.SetButtonNumber(num_index);
	continue_button.SetButtonNumber(num_index);
	extra_button.SetButtonNumber(num_index);
	quit_button.SetButtonNumber(num_index);

	start_button.SetOrder(0);
	continue_button.SetOrder(1);
	extra_button.SetOrder(2);
	quit_button.SetOrder(3);

	const int title_illust = LoadGraph("gazo_gamedx/title_illust.png");

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		key_board.GetKeyState();

		//back_ground.Title();

		key_board.MoveCursor(cursor);

		DrawGraph(50, 0, title_illust, TRUE);	//titleイラスト

		// はじめから
		start_button.SetCursor(cursor);
		start_button.Text("ボツになったステージ", TITLEFONTSIZE);
		start_button.Draw(100, 450);

		// つづきから
		continue_button.SetCursor(cursor);
		continue_button.Text("ボツ2", TITLEFONTSIZE);
		continue_button.Draw(100, 500);

		// エキストラ
		extra_button.SetCursor(cursor);
		extra_button.Text("Extras", TITLEFONTSIZE);
		extra_button.Draw(100, 550);

		// 終了ボタンの描画
		quit_button.SetCursor(cursor);
		quit_button.Text("Back", TITLEFONTSIZE);
		quit_button.Draw(100, 600);

		if (start_button.IsPushed())
		{
			return SCENE1;
		}

		if (extra_button.IsPushed())
		{
			return EXTRA;
		}

		if (continue_button.IsPushed())
		{
			return SCENE2;
		}

		if (quit_button.IsPushed())
		{
			return TITLE;
		}
		key_board.SaveKeyState();


		FPS(60);
	}
	return 0;
}

int GameManager::Extra()
{
	Button hana_button;
	Button ryo_button;
	Button quit_button;
	//Background back_ground;
	Keyboard key_board;

	int num_index = 3;				// キャラクター数
	int cursor = 0;					// 現在のカーソル位置
	int charactor = 0;

	key_board.SetIndexNum(num_index);

	hana_button.SetButtonNumber(num_index);
	ryo_button.SetButtonNumber(num_index);
	quit_button.SetButtonNumber(num_index);

	//int title = LoadGraph("gazo_gamedx/title.png");
	const int hana_front = LoadGraph("gazo_gamedx/hana_front3.png");
	const int hana_side = LoadGraph("gazo_gamedx/hana_side3.png");
	const int hana_back = LoadGraph("gazo_gamedx/hana_back3.png");

	const int ryo_front = LoadGraph("gazo_gamedx/ryo_front3.png");
	const int ryo_side = LoadGraph("gazo_gamedx/ryo_side3.png");
	const int ryo_back = LoadGraph("gazo_gamedx/ryo_back3.png");

	hana_button.SetOrder(0);
	ryo_button.SetOrder(1);
	quit_button.SetOrder(2);

	int time_count = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		key_board.GetKeyState();

		///back_ground.Title();

		key_board.MoveCursor(cursor);
		DrawFormatString(0, 0, GetColor(PINK), "こんにちは");
		switch (charactor)
		{
		case 0:
			// File 1 ( 華子 )
			hana_button.SetCursor(cursor);
			hana_button.Text("file 1", TITLEFONTSIZE);
			hana_button.Draw(100, 500);

			if (hana_button.IsPushed())
			{
				charactor = 1;
			}

			// File 2 ( 涼太郎 )
			ryo_button.SetCursor(cursor);
			ryo_button.Text("file 2", TITLEFONTSIZE);
			ryo_button.Draw(100, 550);

			if (ryo_button.IsPushed())
			{
				charactor = 2;
			}

			// もどる
			quit_button.SetCursor(cursor);
			quit_button.Text("Back", TITLEFONTSIZE);
			quit_button.Draw(100, 600);

			if (quit_button.IsPushed())
			{
				return MODE_SELECT;
			}

			break;
		case 1:
			//back_ground.CharaInfo();
			hana_button.FontDraw(40, 130, 100, "華子");
			hana_button.FontDraw(20, 130, 160, "Age: 20 \nJob: 大学院生 \nBirthday: October 5th \nTall: 165cm \nWeight: 52kg \nBloodType: A\nHometown: Kanagawa, Japan \n\n\nアメリカで数学を専攻している博士後期課程学生. \n翌年から日本に帰国し, 研究所の助手として勤務予定. \n過去に長年未解決問題であった, とある定理を証明したことが\nきっかけでこの齢にして天才数学者として名を馳せている.");

			DrawExtendGraph(700, 100, 700 + 300 * 2 / 3, 100 + 324 * 2 / 3, hana_front, TRUE);
			DrawExtendGraph(710, 350, 710 + 299 * 2 / 3, 350 + 351 * 2 / 3, hana_side, TRUE);
			DrawExtendGraph(950, 100, 950 + 300 * 2 / 3, 100 + 324 * 2 / 3, hana_back, TRUE);

			break;
		case 2:
			//back_ground.CharaInfo();
			hana_button.FontDraw(40, 130, 100, "涼太郎");
			hana_button.FontDraw(20, 130, 160, "Age: 22 \nJob: 美術大学生 \nBirthday: December 15th \nTall: 176cm \nWeight: 65kg \nBloodType: AB\nHometown: Okayama, Japan \n\n\n美大に2浪して入学した学部2年生. \n将来は画家として生きていくことを目指していた.\n医者からそう長くは生きられないと言われてからは, \n自分がこの世に生きていた証を残すために必死に \n絵を描き続けている. ");
			DrawExtendGraph(700, 100, 700 + 228 * 2 / 3, 100 + 324 * 2 / 3, ryo_front, TRUE);
			DrawExtendGraph(710, 350, 710 + 228 * 2 / 3, 350 + 351 * 2 / 3, ryo_side, TRUE);
			DrawExtendGraph(950, 100, 950 + 228 * 2 / 3, 100 + 324 * 2 / 3, ryo_back, TRUE);

			break;
		}
		key_board.SaveKeyState();

		FPS(60);

	}
	return 0;
}

int GameManager::Scene1()
{
	Button start_button;				// はじめから
	//Background back_ground;			// 背景
	Keyboard key_board;
	//CharaMove chara_move;
	//haikei_byoga Haikei;

	int num_index = 1;				// 項目数
	int cursor = 0;					// 現在のカーソル位置

	key_board.SetIndexNum(num_index);

	start_button.SetButtonNumber(num_index);

	start_button.SetOrder(0);

	// hana 画像読み取り
	const int hana_1 = LoadGraph("gazo_gamedx/hana_front3.png");
	const int hana_2 = LoadGraph("gazo_gamedx/hana_frontR.png");
	const int hana_3 = LoadGraph("gazo_gamedx/hana_frontL.png");
	const int hana_4 = LoadGraph("gazo_gamedx/hana_side3.png");
	const int hana_5 = LoadGraph("gazo_gamedx/hana_side31.png");
	const int hana_6 = LoadGraph("gazo_gamedx/hana_side32.png");
	const int hana_7 = LoadGraph("gazo_gamedx/hana_back3.png");
	const int hana_8 = LoadGraph("gazo_gamedx/hana_back31.png");
	const int hana_9 = LoadGraph("gazo_gamedx/hana_back32.png");

	// 背景画像読み取り
	// const int serifubox = LoadGraph("gazo_gamedx/serifu.png");
	const int haikei_1F = LoadGraph("gazo_gamedx/floor.png");
	const int tile_blue = LoadGraph("gazo_gamedx/tile_1.png");
	const int escalator1 = LoadGraph("gazo_gamedx/escalator1.png");
	const int escalator2 = LoadGraph("gazo_gamedx/escalator2.webm");
	const int window = LoadGraph("gazo_gamedx/window.png");
	const int table_circle = LoadGraph("gazo_gamedx/table_circle.png");
	const int table_front = LoadGraph("gazo_gamedx/table_front.png");

	const int jozan = LoadGraph("gazo_gamedx/jozan.png");
	const int zentai = LoadGraph("gazo_gamedx/zentai.png");
	const int kabe = LoadGraph("gazo_gamedx/wall.png");
	const int wood = LoadGraph("gazo_gamedx/wood.png");
	const int noise = LoadGraph("gazo_gamedx/noise.png");
	const int highlight = LoadGraph("gazo_gamedx/player_highlight.png");

	PlayMovieToGraph(escalator2, DX_PLAYTYPE_LOOP);

	//hana の初期位置とスピード
	//chara_move.raw_moved_x = PLAYER_X;
	//chara_move.raw_moved_y = PLAYER_Y;
	//chara_move.player_speed = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		key_board.GetKeyState();

		// 背景描画
		/*
		back_ground.back_1F(haikei_1F); // 床
		back_ground.putTile_no_hit_judge(CELL * 10, CELL * (-4), escalator1);
		back_ground.putTile_no_hit_judge(CELL * 11, CELL * (-4), escalator2);
		back_ground.putTile_no_hit_judge(CELL * 15, CELL * 5, wood);
		back_ground.wall_draw(kabe);
		back_ground.putTile_no_hit_judge(CELL * 15, CELL * (-12), window);
		back_ground.putTile_no_hit_judge(CELL * 17, CELL * (-12), window);
		back_ground.putTile_no_hit_judge(CELL * 17, CELL * (-6), table_circle);
		back_ground.putTile_no_hit_judge(CELL * 17, CELL * 17, table_front);

		//back_ground.putTile_no_hit_judge(CELL * 11, CELL * ( - 4), escalator2);*/

		// hana 歩き
		//chara_move.Move(hana_1, hana_2, hana_3, hana_4, hana_5, hana_6, hana_7, hana_8, hana_9);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		SetDrawBlendMode(DX_BLENDMODE_MULA, 128);
		DrawGraph(0, 0, jozan, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 30);
		SetDrawBlendMode(DX_BLENDMODE_MULA, 10);
		DrawGraph(0, 0, zentai, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
		SetDrawBlendMode(DX_BLENDMODE_MULA, 50);
		DrawGraph(0, 0, noise, TRUE);
		DrawGraph(0, 0, highlight, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		start_button.Draw(0, 0);
		if (CheckHitKey(KEY_INPUT_A))
		{
			return SCENE2;
		}

		//DrawFormatString(0, 150, GetColor(255, 255, 255), "item_y: %d", back_ground.test_x);
		//DrawFormatString(0, 200, GetColor(255, 255, 255), "test_y: %d", back_ground.test_y);

		FPS(60);
		key_board.SaveKeyState();
	}
	return 0;
}

int GameManager::Scene2()
{
	Button start_button;				// はじめから
	//Background back_ground;			// 背景
	Keyboard key_board;
	//CharaMove chara_move;
	//HaikeiByoga haikei_byoga;

	int num_index = 1;				// 項目数
	int cursor = 0;					// 現在のカーソル位置

	key_board.SetIndexNum(num_index);

	start_button.SetButtonNumber(num_index);

	start_button.SetOrder(0);

	// hana 画像読み取り
	const int hana_1 = LoadGraph("gazo_gamedx/hana_front3.png");
	const int hana_2 = LoadGraph("gazo_gamedx/hana_frontR.png");
	const int hana_3 = LoadGraph("gazo_gamedx/hana_frontL.png");
	const int hana_4 = LoadGraph("gazo_gamedx/hana_side3.png");
	const int hana_5 = LoadGraph("gazo_gamedx/hana_side31.png");
	const int hana_6 = LoadGraph("gazo_gamedx/hana_side32.png");
	const int hana_7 = LoadGraph("gazo_gamedx/hana_back3.png");
	const int hana_8 = LoadGraph("gazo_gamedx/hana_back31.png");
	const int hana_9 = LoadGraph("gazo_gamedx/hana_back32.png");

	// 背景画像読み取り
	//haikei_byoga.read();
	//haikei_byoga.TextRead();

	const int jozan = LoadGraph("gazo_gamedx/jozan.png");
	const int zentai = LoadGraph("gazo_gamedx/zentai.png");
	const int noise = LoadGraph("gazo_gamedx/noise.png");
	const int highlight = LoadGraph("gazo_gamedx/player_highlight.png");
	const int kako = LoadGraph("gazo_gamedx/kako.png");
	const int shade = LoadGraph("gazo_gamedx/shade.png");

	//hana の初期位置とスピード
	//chara_move.raw_moved_x = PLAYER_X;
	//chara_move.raw_moved_y = PLAYER_Y;
	//chara_move.player_speed = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		key_board.GetKeyState();

		// 背景描画？
		//haikei_byoga.Out();

		// hana 歩き
		//chara_move.Move(hana_1, hana_2, hana_3, hana_4, hana_5, hana_6, hana_7, hana_8, hana_9);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		SetDrawBlendMode(DX_BLENDMODE_MULA, 128);
		DrawGraph(0, 0, shade, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 30);
		SetDrawBlendMode(DX_BLENDMODE_MULA, 10);
		DrawGraph(0, 0, zentai, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
		SetDrawBlendMode(DX_BLENDMODE_MULA, 50);
		DrawGraph(0, 0, noise, TRUE);
		DrawGraph(0, 0, highlight, TRUE);
		//DrawGraph(0, 0, kako, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


		start_button.Draw(0, 0);
		if (start_button.IsPushed())
		{
			return GAME_END;
		}

		//DrawFormatString(0, 200, GetColor(255, 255, 255), "raw_y: %d", chara_move.raw_moved_y);

		///DrawFormatString(0, 250, GetColor(255, 255, 255), "player_speed: %d", chara_move.player_speed);

		FPS(60);
		key_board.SaveKeyState();
	}
	return 0;
}
