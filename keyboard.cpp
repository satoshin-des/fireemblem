#include "keyboard.h"

void Keyboard::SetIndexNum(const int n)
{
	m_num_button = n;
}

void Keyboard::GetKeyState()
{
	GetHitKeyStateAll(m_key_buf);
}

void Keyboard::SaveKeyState()
{
	memcpy(m_old_key_buf, m_key_buf, sizeof(m_key_buf));
}

void Keyboard::MoveCursor(int& cursor) {
	if (m_old_key_buf[KEY_INPUT_UP] == 0 && m_key_buf[KEY_INPUT_UP] == 1)
	{
		cursor += m_num_button - 1;
	}

	if (m_old_key_buf[KEY_INPUT_DOWN] == 0 && m_key_buf[KEY_INPUT_DOWN] == 1)
	{
		++cursor;
	}
}