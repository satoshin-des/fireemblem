#ifndef CHARACTER_LEVEL_H
#define CHARACTER_LEVEL_H

#include <iostream>
#include <vector>
#include <random>
#include "DxLib.h"
#include "core.h"
#include "button.h"

struct StatusList
{
	std::string name;
	unsigned char HP;
	unsigned char Str;
	unsigned char Mag;
	unsigned char Dex;
	unsigned char Spd;
	unsigned char Lck;
	unsigned char Def;
	unsigned char Res;
	unsigned char Cha;
	int total_status;
};

struct GrowthRate
{
	unsigned char HP;
	unsigned char Str;
	unsigned char Mag;
	unsigned char Dex;
	unsigned char Spd;
	unsigned char Lck;
	unsigned char Def;
	unsigned char Res;
	unsigned char Cha;
};

class Character {
public:
	StatusList status_;
	GrowthRate growth_;
	int level_;
	int exp_;

	int pin_ = 0;
	int rand_ = GetRandomInt(1, 100);
	int rand_pin1_;
	int rand_pin2_;


	// コンストラクタ
	Character() = default;
	
Character(StatusList& status, GrowthRate& growth)
		:status_(status), growth_(growth), level_(1), exp_(0){}
	int GetRandomInt(int n1, int n2);

	/// <summary>
	/// レベルアップする関数
	/// </summary>
	void LevelUp(int& pin, int& rand, std::vector<Character>& characters, const std::string& name/*, Button& button*/);

	std::pair<int, int>  ChooseTwoDistinct();

	void StatusOutput(std::vector<Character>& characters, const std::string& name);
};

#endif // CHARACTER_LEVEL_H