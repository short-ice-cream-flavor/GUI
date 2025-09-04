#pragma once
#include <string>
#include "imgui.h"

class c_elements
{
public:

	struct
	{
		float height{ 35 };
	} top_bar;

	struct
	{
		ImVec2 padding{ 10, 10 };
	} window;

	struct
	{
		float label_padding{ 70 };
		float widgets_padding{ 34 };
		float socials_padding{ 25 };
	} login_page;

	struct
	{
		ImVec2 size{ 220, 42 };
		float rounding{ 6 };
	} textfield;

	struct
	{
		ImVec2 login_size{ 220, 38 };
		ImVec2 social_size{ 15, 15 };
		float social_padding{ 15 };
		ImVec2 load_size{ 40, 40 };
	} button;

	struct
	{
		std::vector<std::string> name{ "VALORANT", "CS2", "TITANFALL 2", "PUBG", "DOTA2", "TARKOV" };
		float height{ 50 };
		float img_width{ 87 };
		ImVec2 padding{ 15, 15 };
		ImVec2 load_padding{ 5, 5 };
	} game_card;

	struct
	{
		float padding{ 30 };
		ImVec2 icon_padding{ 166, 149 };
		ImVec2 confirmed_padding{ 93, 167 };
	} loading;
};

inline std::unique_ptr<c_elements> elements = std::make_unique<c_elements>();
