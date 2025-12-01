#pragma once

#include <chrono>

#include "core.h"

class Opening
{
private:
	std::chrono::system_clock::time_point m_begin;	// 時間計測開始
	std::chrono::duration<float> m_time_duration;	// 経過時間

public:
	/// <summary>
	/// Openingクラスの初期化
	/// </summary>
	/// <returns></returns>
	int init();

	/// <summary>
	/// Openignの更新
	/// </summary>
	void update(Scene &scene);

	/// <summary>
	/// Openingの描画
	/// </summary>
	void draw();
};
