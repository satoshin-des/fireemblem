#pragma once

#include "DxLib.h"
#include "core.h"

/// <summary>
/// ボタンを制御するクラス
/// </summary>
class Button
{
private:
	char m_key_buf[KEY_BUF];
	char m_old_key_buf[KEY_BUF] = { 0 };

	char* m_text;
	int m_font_size;
	int m_order;
	int m_cursor;
	int m_num_button;
	int m_x;
	int m_y;
	int diff_x = -50;
	int diff_y = -5;

	bool is_to_right = true;

	unsigned int m_arrow_img;
public:
	/// <summary>
	/// カーソルの位置を設定する関数
	/// </summary>
	/// <param name="Cursor">カーソルの位置</param>
	void SetCursor(const int cursor);

	/// <summary>
	/// ボタンの総数を設定する関数
	/// </summary>
	/// <param name="Cursor">ボタンの総数</param>
	void SetButtonNumber(const int num_button);

	/// <summary>
	/// ボタンが何番目なのかを設定する関数
	/// </summary>
	/// <param name="n">順番</param>
	void SetOrder(const int n);

	/// <summary>
	/// ボタンに表示する文字列を設定する関数
	/// </summary>
	/// <param name="text">表示させたい文字列</param>
	/// <param name="font_size">フォントサイズ</param>
	void Text(const char* text, const int font_size);

	/// <summary>
	/// ボタンの描画
	/// </summary>
	/// <param name="X">X座標</param>
	/// <param name="Y">Y座標</param>
	void Draw(const int x, const int y);

	/// <summary>
	/// ボタンが押されたかどうかを判定する関数
	/// </summary>
	/// <returns>ボタンが押されたらtrue，そうでなければfalse</returns>
	bool IsPushed();

	/// <summary>
	/// 矢印の画像を読み込む
	/// </summary>
	/// <param name="">ファイルパス</param>
	void LoadArrowImage(const char* file_path);

	/// <summary>
	/// 矢印の描画
	/// </summary>
	void DrawArrow();

	void FontDraw(int size, int x, int y, const char* sentence);

	void push1();
};