#pragma once

#include <string>

#include "DxLib.h"

#define TITLE_TEXT "たいとる"
#define WIDTH_X 1275
#define WIDTH_Y 714
//#define WIDTH_X_HALF 640
//#define WIDTH_Y_HALF 360
#define TITLEFONTSIZE 25
#define KEY_BUF 256

//色
#define LIGHT_BLUE 0, 255, 200
#define WHITE 255, 255, 255
#define BLACK 0, 0, 0
#define PINK 240, 180, 240
#define ENJI 180, 50, 125
#define BLUE 40,39,50
#define DARK_BLUE 35, 35, 45

// マップ調整
#define CELL 55 // 背景画像一辺の長さ
#define MAP_CELL_HORIZONTAL 60 / 2 // 横方向マップの大きさ (片方)
#define MAP_CELL_VERTICAL 30 / 2 // 縦方向マップの大きさ (片方)


//画像調整
#define HANA_SIZE 0.20 // hana の画像比率
#define PLAYER_X CELL * 12	//hana の初期位置
#define PLAYER_Y CELL * 7	//hana の初期位置

#define MAX_X WIDTH_X / CELL

#define MAP_MAX_X MAX_X + 10
#define MAP_MAX_Y 14

#define CONFIRM z_is_pressed || enter_is_pressed

#define SWITCH(c, a, b) c ? a : b

/// <summary>
/// ゲームのシーンに関するenum
/// </summary>
enum Scene
{
	GAME_END,
	OPENING,
	TITLE,
	MODE_SELECT,
	QUIT,
	EXTRA,
	SCENE1,
	SCENE2
};

extern bool has_to_init; // 各シーンにおいて初期化する必要があるかどうか
extern LPCSTR font_path; // フォントのパス

/// <summary>
/// エラー発生時にエラーボックスを表示する関数
/// </summary>
/// <param name="str">エラーメッセージ</param>
void errorBox(const std::string str);

int gameInit();

/// <summary>
/// FPSを制御する関数
/// </summary>
/// <param name="fps">FPS</param>
void FPS(const int fps);