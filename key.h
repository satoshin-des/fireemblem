#pragma once

#include "DxLib.h"

extern bool is_pressed_now;	// 現在のキーの状態
extern bool is_pressed_old; // 前のキーの状態
extern char key[256];
extern char old_key[256];

extern int any_key_is_pressed;	// 何らかのキーが押されているか
extern int z_is_pressed;		// zが押されているか
extern int enter_is_pressed;	// エンターキーが押されているか
extern int up_is_pressed;		// ↑が押されているか
extern int down_is_pressed;		// ↓が押されているか
extern int right_is_pressed;	// →が押されているか
extern int left_is_pressed;		// ←が押されているか

/// <summary>
/// キー状態を取得する
/// </summary>
void checkKeyState();
