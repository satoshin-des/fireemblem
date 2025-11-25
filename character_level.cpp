#include "character_level.h"

int Character::IsSuccess()
{
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_int_distribution<int> dist(0, 100);

	int r = dist(mt); // 0 to 100
	DrawFormatString(200, 0, GetColor(WHITE), "rand = %r", r);
	return r;
}


void Character::LevelUp(std::vector<Character>& characters, const std::string& name)
{
	int r = 1;
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		++r;
		int n = IsSuccess();
		if (n <= characters[0].growth_.HP)
		{
			++characters[0].status_.HP;
		}
		if (n <= characters[0].growth_.Str)
		{
			++characters[0].status_.Str;
		}
		if (n <= characters[0].growth_.Mag)
		{
			++characters[0].status_.Mag;
		}
		if (n <= characters[0].growth_.Dex)
		{
			++characters[0].status_.Dex;
		}
		if (n <= characters[0].growth_.Spd)
		{
			++characters[0].status_.Spd;
		}
		if (n <= characters[0].growth_.Lck)
		{
			++characters[0].status_.Lck;
		}
		if (n <= characters[0].growth_.Def)
		{
			++characters[0].status_.Def;
		}
		if (n <= characters[0].growth_.Res)
		{
			++characters[0].status_.Res;
		}
		if (n <= characters[0].growth_.Cha)
		{
			++characters[0].status_.Cha;
		}
		DrawFormatString(100, 0, GetColor(WHITE), "level = %d", r);
	}
}

void Character::StatusOutput(std::vector<Character>& characters, const std::string& name)
{
	for (const auto& ch : characters)
	{
		if (ch.status_.name == name)
		{
			continue;
		}
	}
	DrawFormatString(0, 0, GetColor(WHITE), "%s", characters[0].status_.name.c_str());
	DrawFormatString(0, 30, GetColor(WHITE), "HP %d", characters[0].status_.HP);
	DrawFormatString(0, 60, GetColor(WHITE), "str %d", characters[0].status_.Str);
	DrawFormatString(0, 90, GetColor(WHITE), "str %d", characters[0].status_.Mag);
	DrawFormatString(0, 120, GetColor(WHITE), "str %d", characters[0].status_.Dex);
	DrawFormatString(0, 150, GetColor(WHITE), "str %d", characters[0].status_.Spd);
	DrawFormatString(0, 180, GetColor(WHITE), "str %d", characters[0].status_.Lck);
	DrawFormatString(0, 210, GetColor(WHITE), "str %d", characters[0].status_.Def);
	DrawFormatString(0, 240, GetColor(WHITE), "str %d", characters[0].status_.Res);
	DrawFormatString(0, 270, GetColor(WHITE), "str %d", characters[0].status_.Cha);
}