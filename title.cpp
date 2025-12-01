#include "title.h"

int Title::init()
{
	if (has_to_init)
	{
		has_to_init = false;
		m_cursor = 0;

		StatusList Byleth_status = { "ベレス", 27, 13, 6, 9, 8, 8, 6, 6, 7, 90 };
		StatusList Edelgard_status = { "エーデルガルト", 29, 13, 6, 5, 8, 5, 6, 4, 10, 86 };
		StatusList Hubert_status = { "ヒューベルト", 22, 6, 12, 6, 7, 5, 4, 7, 6, 75 };

		GrowthRate Byleth_growth = { 45, 45, 35, 45, 45, 45, 35, 30, 45 };
		GrowthRate Edelgard_growth = { 40, 55, 45, 45, 40, 30, 35, 35, 60 };
		GrowthRate Hubert_growth = { 35, 30, 55, 45, 45, 35, 25, 40, 35 };

		characters.emplace_back(Byleth_status, Byleth_growth);
		characters.emplace_back(Edelgard_status, Edelgard_growth);
		characters.emplace_back(Hubert_status, Hubert_growth);
	}

	return 0;
}

void Title::update(Scene& scene)
{
	if (CONFIRM)
	{
		if (m_cursor == 0)
		{
			has_to_init = true;
			scene = Scene::MODE_SELECT;
		}
		if (m_cursor == 1)
		{
			has_to_init = true;
			scene = Scene::GAME_END;
		}
	}

	if (up_is_pressed)
	{
		m_cursor = (std::max)(m_cursor - 1, 0);
	}
	if (down_is_pressed)
	{
		m_cursor = (std::min)(m_cursor + 1, NUM_TITLE_BUTTON - 1);
	}
}

void Title::draw()
{
	character.StatusOutput(characters, "ベレス");
	character.LevelUp(character.pin_, character.rand_, characters, "ベレス");

	DrawFormatString(100, 100, GetColor(WHITE), "rand = %d", character.rand_);
	DrawFormatString(100, 150, GetColor(WHITE), "pin = %d", character.pin_);
	DrawFormatString(100, 200, GetColor(WHITE), "level = %d", characters[0].level_);
	DrawFormatString(100, 250, GetColor(WHITE), "total = %d", characters[0].status_.total_status);

	SWITCH(
		m_cursor == 0,
		DrawFormatString(100, 500, GetColor(255, 0, 0), "START"),
		DrawFormatString(100, 500, GetColor(WHITE), "START")
	);
	SWITCH(
		m_cursor == 1,
		DrawFormatString(100, 550, GetColor(255, 0, 0), "END"),
		DrawFormatString(100, 550, GetColor(WHITE), "END")
	);
}
