#include "mode_select.h"

#include "key.h"

int ModeSelect::init()
{
	if (has_to_init)
	{
		has_to_init = false;
		m_title_illust = LoadGraph("gazo_gamedx/title_illust.png");
		if (m_title_illust == -1)
		{
			errorBox("画像の読み込み中に予期せぬエラーが発生しました．");
			return -1;
		}
		m_cursor = 0;
	}
	return 0;
}

void ModeSelect::update(Scene& scene)
{
	if (CONFIRM)
	{
		if (m_cursor == 0)
		{
			has_to_init = true;
			scene = Scene::SCENE1;
		}
		if (m_cursor == 2)
		{
			has_to_init = true;
			scene = Scene::EXTRA;
		}
		if (m_cursor == 1)
		{
			has_to_init = true;
			scene = Scene::SCENE2;
		}
		if (m_cursor == 3)
		{
			has_to_init = true;
			scene = Scene::TITLE;
		}
	}

	if (up_is_pressed)
	{
		m_cursor = (std::max)(m_cursor - 1, 0);
	}
	if (down_is_pressed)
	{
		m_cursor = (std::min)(m_cursor + 1, NUM_MODE_SELECT_BUTTON - 1);
	}
}

void ModeSelect::draw()
{
	SWITCH(
		m_cursor == 0,
		DrawFormatString(100, 450, GetColor(255, 0, 0), "ボツになったステージ"),
		DrawFormatString(100, 450, GetColor(WHITE), "ボツになったステージ")
	);
	SWITCH(
		m_cursor == 1,
		DrawFormatString(100, 500, GetColor(255, 0, 0), "ボツ2"),
		DrawFormatString(100, 500, GetColor(WHITE), "ボツ2")
	);
	SWITCH(
		m_cursor == 2,
		DrawFormatString(100, 550, GetColor(255, 0, 0), "Extra"),
		DrawFormatString(100, 550, GetColor(WHITE), "Extra")
	);
	SWITCH(
		m_cursor == 3,
		DrawFormatString(100, 600, GetColor(255, 0, 0), "Back"),
		DrawFormatString(100, 600, GetColor(WHITE), "Back")
	);
}