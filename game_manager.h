#ifndef GAME_MANAGER_H
#define GAME_MANEGER_H

#include <iostream>
#include <vector>
#include "character_level.h"
#include "DxLib.h"
#include "core.h"
#include "button.h"
//#include "background.h"
#include "keyboard.h"
//#include "Chara_Move.h"
//#include "haikei_byoga.h"

class GameManager {
public:
	std::vector<Character> characters;

	GameManager() 
	{
		// Byleth_status (StatusList)  --> Character(status_ = Byleth_status, level_=1, exp_=0) --> characters[0]
		StatusList Byleth_status = { "ベレス", 27, 13, 6, 9, 8, 8, 6, 6, 7, 90};
		StatusList Edelgard_status = { "エーデルガルト", 29, 13, 6, 5, 8, 5, 6, 4, 10, 86};
		StatusList Hubert_status = { "ヒューベルト", 22, 6, 12, 6, 7, 5, 4, 7, 6, 75};

		GrowthRate Byleth_growth = { 45, 45, 35, 45, 45, 45, 35, 30, 45 };
		GrowthRate Edelgard_growth = { 40, 55, 45, 45, 40, 30, 35, 35, 60 };
		GrowthRate Hubert_growth = { 35, 30, 55, 45, 45, 35, 25, 40, 35 };

		characters.emplace_back(Byleth_status, Byleth_growth);
		characters.emplace_back(Edelgard_status, Edelgard_growth);
		characters.emplace_back(Hubert_status, Hubert_growth);
	}

	/// <summary>
	/// タイトルを制御する関数
	/// </summary>
	/// <returns>状態</returns>
	int Title();

	/// <summary>
	/// モード選択画面を制御する関数
	/// </summary>
	/// <returns>状態</returns>
	int ModeSelect();

	/// <summary>
	/// エキストラを制御する関数
	/// </summary>
	/// <returns>状態</returns>
	int Extra();

	/// <summary>
	/// 1F を制御する関数
	/// </summary>
	/// <returns>状態</returns>
	int Scene1();

	/// <summary>
	/// 廊下を制御する関数
	/// </summary>
	/// <returns>状態</returns>
	int Scene2();

	Character playable_character;
};

#endif // GAME_MANAGER_H