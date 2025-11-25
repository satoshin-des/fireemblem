#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "DxLib.h"
#include "core.h"

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

	// コンストラクタ
	Character() = default;
	Character(StatusList& status, GrowthRate& growth)
		:status_(status), growth_(growth), level_(1), exp_(0) { }

	int IsSuccess();

	/// <summary>
	/// レベルアップする関数
	/// </summary>
	void LevelUp(std::vector<Character>& characters, const std::string& name);

	void StatusOutput(std::vector<Character>& characters, const std::string& name);
};