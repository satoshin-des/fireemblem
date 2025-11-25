#include "button.h"

void  Button::SetCursor(const int cursor)
{
	m_cursor = cursor;
}

void  Button::SetButtonNumber(const int num_button)
{
	m_num_button = num_button;
}

void  Button::SetOrder(const int n)
{
	m_order = n;
}

void  Button::Text(const char* text, const int font_size)
{
	m_text = (char*)text;
	m_font_size = font_size;
}

void  Button::Draw(const int x, const int y)
{
	unsigned int color;

	m_x = x;
	m_y = y;

	color = (m_cursor % m_num_button == m_order ? GetColor(DARK_BLUE) : GetColor(BLACK));
	SetFontSize(m_font_size);
	DrawFormatString(x, y, color, "%s", m_text);
}

bool  Button::IsPushed()
{
	GetHitKeyStateAll(m_key_buf);

	if (m_cursor % m_num_button == m_order)
	{
		if ((m_old_key_buf[KEY_INPUT_Z] == 0 && m_key_buf[KEY_INPUT_Z] == 1) || (m_old_key_buf[KEY_INPUT_RETURN] == 0 && m_key_buf[KEY_INPUT_RETURN] == 1))
		{
			WaitTimer(300); // ‘Ò‚Â
			return true;
		}
	}

	memcpy(m_old_key_buf, m_key_buf, sizeof(m_key_buf));

	return false;
}

void  Button::LoadArrowImage(const char* file_path)
{
	m_arrow_img = LoadGraph(file_path);
}

void Button::DrawArrow()
{
	if (m_cursor % m_num_button == m_order)
	{
		if (is_to_right)
		{
			++diff_x;
			if (diff_x == -45)
			{
				is_to_right = false;
			}
		}
		else
		{
			--diff_x;
			if (diff_x == -55)
			{
				is_to_right = true;
			}
		}
		DrawGraph(m_x + diff_x, m_y + diff_y, m_arrow_img, TRUE);
	}
}

void Button::FontDraw(int size, int x, int y, const char* sentence)
{
	SetFontSize(size);
	unsigned int a = GetColor(BLUE);
	DrawFormatString(x, y, a, "%s", sentence);
}

void Button::push1()
{
	if (CheckHitKeyAll() != 0)
	{

	}
}