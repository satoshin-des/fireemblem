#include "opening.h"

int Opening::init()
{
	if (has_to_init)
	{
		has_to_init = false;
		m_begin = std::chrono::system_clock::now();
	}

	return 0;
}

void Opening::update(Scene& scene)
{
	m_time_duration = std::chrono::system_clock::now() - m_begin;
	if (m_time_duration.count() >= 10)
	{
		has_to_init = true;
		scene = Scene::TITLE;
	}
}

void Opening::draw()
{
	DrawFormatString(0, 0, GetColor(PINK), "‚±‚ñ‚É‚¿‚Í");
}
