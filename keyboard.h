#pragma once

#include "DxLib.h"
#include "core.h"

class Keyboard
{
private:
	char m_key_buf[KEY_BUF];
	char m_old_key_buf[KEY_BUF] = { 0 };
	int m_num_button;
public:
	void SetIndexNum(const int n);

	/// <summary>
	/// キーの状態を取得
	/// </summary>
	void GetKeyState();

	/// <summary>
	/// キーの状態を保存
	/// </summary>
	void SaveKeyState();

	/// <summary>
	/// カーソルを動かす
	/// </summary>
	/// <param name="cursor">カーソル位置</param>
	void MoveCursor(int& cursor);
};
