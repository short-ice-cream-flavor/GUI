#pragma once
#include "imgui.h"
#include <memory>

class c_colors
{
public:

	struct
	{
		ImColor accent{ 242, 175, 255 };
		ImColor text{ 255, 255, 255 };
		ImColor text_black{ 0, 0, 0 };
	} main;

	struct
	{
		ImColor background{ 16, 17, 22 };
		ImColor outline{ 37, 37, 54 };
	} window;

	struct
	{
		ImColor text{ 92, 93, 115 };
	} textfield;

	struct
	{
		ImColor outline{ 31, 36, 44 };
		ImColor background{ 28, 26, 42 };
		ImColor text{ 96, 95, 118 };
	} game_card;
};

inline std::unique_ptr<c_colors> clr = std::make_unique<c_colors>();
