#pragma once

#include "DxLib.h"

#include "core.h"

#define NUM_MODE_SELECT_BUTTON 4

class ModeSelect
{
private:
	int m_title_illust;
	int m_cursor = 0;

public:
	int init();

	void update(Scene& scene);

	void draw();
};
