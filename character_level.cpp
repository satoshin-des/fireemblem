#include "character_level.h"
#include "game_manager.h"
#include "key.h"

int Character::GetRandomInt(int n1, int n2)
{
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_int_distribution<int> dist(n1, n2);

	int r = dist(mt); // 0 to 100
	return r;
}


std::pair<int, int> Character::ChooseTwoDistinct()
{
	std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	static std::random_device rd;
	static std::mt19937_64 mt(rd());

	std::shuffle(nums.begin(), nums.end(), mt);

	return { nums[0], nums[1] };
}

void Character::LevelUp(int& pin, int& rand, std::vector<Character>& characters, const std::string& name/*, Button& button*/ )
{
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		if (any_key_is_pressed)
		{
			characters[0].level_ += 1;
			pin = 0;
			if (rand <= characters[0].growth_.HP)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Str)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Mag)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Dex)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Spd)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Lck)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Def)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Res)
			{
				++pin;
			}
			if (rand <= characters[0].growth_.Cha)
			{
				++pin;
			}
			// button.pushed = false;
			rand = GetRandomInt(1, 100);
			if (pin >= 2)
			{
				if (rand <= characters[0].growth_.HP)
				{
					++characters[0].growth_.HP;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Str)
				{
					++characters[0].growth_.Str;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Mag)
				{
					++characters[0].growth_.Mag;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Dex)
				{
					++characters[0].growth_.Dex;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Spd)
				{
					++characters[0].growth_.Spd;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Lck)
				{
					++characters[0].growth_.Lck;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Def)
				{
					++characters[0].growth_.Def;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Res)
				{
					++characters[0].growth_.Res;
				}
				rand = GetRandomInt(1, 100);
				if (rand <= characters[0].growth_.Cha)
				{
					++characters[0].growth_.Cha;
				}
				rand = GetRandomInt(1, 100);
				characters[0].status_.total_status += pin;
			}
			
			// Å’á2ƒsƒ“•Ûá
			else
			{
				auto p = ChooseTwoDistinct();
				rand_pin1_ = p.first;
				rand_pin2_ = p.second;
				if (rand_pin1_ == 1 || rand_pin2_ == 1)
				{
					++characters[0].status_.HP;
				}
				if (rand_pin1_ == 2 || rand_pin2_ == 2)
				{
					++characters[0].status_.Str;
				}
				if (rand_pin1_ == 3 || rand_pin2_ == 3)
				{
					++characters[0].status_.Mag;
				}
				if (rand_pin1_ == 4 || rand_pin2_ == 4)
				{
					++characters[0].status_.Dex;
				}
				if (rand_pin1_ == 5 || rand_pin2_ == .5)
				{
					++characters[0].status_.Spd;
				}
				if (rand_pin1_ == 6 || rand_pin2_ == 6)
				{
					++characters[0].status_.Lck;
				}
				if (rand_pin1_ == 7 || rand_pin2_ == 7)
				{
					++characters[0].status_.Def;
				}
				if (rand_pin1_ == 8 || rand_pin2_ == 8)
				{
					++characters[0].status_.Res;
				}
				if (rand_pin1_ == 9 || rand_pin2_ == 9)
				{
					++characters[0].status_.Cha;
				}
				characters[0].status_.total_status += pin;
			}
		}
	}
	else
	{
		// button.pushed = true;
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
	DrawFormatString(0, 90, GetColor(WHITE), "Mag %d", characters[0].status_.Mag);
	DrawFormatString(0, 120, GetColor(WHITE), "Dex %d", characters[0].status_.Dex);
	DrawFormatString(0, 150, GetColor(WHITE), "Spd %d", characters[0].status_.Spd);
	DrawFormatString(0, 180, GetColor(WHITE), "Lck %d", characters[0].status_.Lck);
	DrawFormatString(0, 210, GetColor(WHITE), "Def %d", characters[0].status_.Def);
	DrawFormatString(0, 240, GetColor(WHITE), "Res %d", characters[0].status_.Res);
	DrawFormatString(0, 270, GetColor(WHITE), "Cha %d", characters[0].status_.Cha);
}