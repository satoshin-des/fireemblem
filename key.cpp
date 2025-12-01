#include "key.h"

#include <cstdlib>
#include <iostream>

#include <DxLib.h>

#include "core.h"

bool is_pressed_now;
bool is_pressed_old;
char key[256];
char old_key[256];

int z_is_pressed;
int enter_is_pressed;
int up_is_pressed;
int down_is_pressed;
int right_is_pressed;
int left_is_pressed;
int any_key_is_pressed;


void checkKeyState()
{
	GetHitKeyStateAll(key);

	// Zkey
	is_pressed_now = (key[KEY_INPUT_Z] != 0);
	is_pressed_old = (old_key[KEY_INPUT_Z] != 0);
	z_is_pressed = is_pressed_now && (!is_pressed_old);

	// Enter key
	is_pressed_now = (key[KEY_INPUT_RETURN] != 0);
	is_pressed_old = (old_key[KEY_INPUT_RETURN] != 0);
	enter_is_pressed = is_pressed_now && (!is_pressed_old);

	// Up key
	is_pressed_now = (key[KEY_INPUT_UP] != 0);
	is_pressed_old = (old_key[KEY_INPUT_UP] != 0);
	up_is_pressed = is_pressed_now && (!is_pressed_old);

	// Down key
	is_pressed_now = (key[KEY_INPUT_DOWN] != 0);
	is_pressed_old = (old_key[KEY_INPUT_DOWN] != 0);
	down_is_pressed = is_pressed_now && (!is_pressed_old);

	// RIght key
	is_pressed_now = (key[KEY_INPUT_RIGHT] != 0);
	is_pressed_old = (old_key[KEY_INPUT_RIGHT] != 0);
	right_is_pressed = is_pressed_now && (!is_pressed_old);

	// Left key
	is_pressed_now = (key[KEY_INPUT_LEFT] != 0);
	is_pressed_old = (old_key[KEY_INPUT_LEFT] != 0);
	left_is_pressed = is_pressed_now && (!is_pressed_old);

	any_key_is_pressed = CheckHitKeyAll();

	memcpy(old_key, key, 256);
}