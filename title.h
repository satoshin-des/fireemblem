#pragma once

#include "core.h"
#include "key.h"
#include "character_level.h"

#define NUM_TITLE_BUTTON 2

class Title
{
private:
	short m_cursor;

public:
	StatusList statuslist;
	Character character;
	std::vector<Character> characters;

	/// <summary>
	/// タイトルクラスの初期化
	/// </summary>
	/// <returns></returns>
	int init();

	/// <summary>
	/// タイトルの更新
	/// </summary>
	/// <param name="scene"></param>
	void update(Scene &scene);

	/// <summary>
	/// タイトルの描画
	/// </summary>
	void draw();
};

