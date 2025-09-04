#pragma once
#include <string>
#include <vector>
#include "imgui.h"
#include "../headers/flags.h"
#include <wtypes.h>

struct ID3D11ShaderResourceView;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGISwapChain;

class c_variables
{
public:

	struct
	{
		HWND hwnd;
		RECT rc;

		ID3D11Device* device_dx11{ nullptr };
		ID3D11DeviceContext* device_context{ nullptr };
		IDXGISwapChain* swap_chain{ nullptr };
	} winapi;

	struct
	{
		ImVec2 size{ 400, 450 };
		float rounding{ 4 };
		window_flags flags{ window_flags_no_saved_settings | window_flags_no_nav | window_flags_no_decoration | window_flags_no_scrollbar | window_flags_no_scroll_with_mouse | window_flags_no_background };
		ImVec2 padding{ 0, 0 };
		float border_size{ 0 };

	} window;

	struct
	{
		bool update_size{ false };
		float dpi = 1.f;
		int stored_dpi = 100;
		bool dpi_changed = true;

		float content_alpha{ 0.f };
		int active_section{ 0 };
		int section_count{ 0 };

		ID3D11ShaderResourceView* games[6];

		std::string username{ "ViSHER" };
		std::string password{ "123" };

		float injecting_timer{ 0 };

	} gui;

	gui_style style;

};

inline std::unique_ptr<c_variables> var = std::make_unique<c_variables>();
