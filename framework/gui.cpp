#include "headers/includes.h"
#include "headers/widgets.h"

void c_gui::render()
{
	gui->initialize();

	gui->set_next_window_pos(ImVec2(0, 0));
	gui->set_next_window_size(SCALE(var->window.size));
	gui->begin("menu", nullptr, var->window.flags);
	{
		gui->set_style();
		gui->draw_decorations();

		gui->easing(var->gui.content_alpha, var->gui.active_section == var->gui.section_count ? 1.f : 0.f, 4.f, static_easing);

		if (var->gui.content_alpha == 0.f)
			var->gui.active_section = var->gui.section_count;


		gui->push_var(style_var_alpha, var->gui.active_section >= 1 && var->gui.section_count > 1 ? 1.f : var->gui.content_alpha);
		if (var->gui.active_section > 0)
		{
			widgets->top_bar();
		}

		gui->pop_var();

		gui->push_var(style_var_alpha, var->gui.content_alpha);
		{
			if (var->gui.active_section == 0)
				widgets->login();
			if(var->gui.active_section > 0)
			{
				gui->set_pos(SCALE(0, elements->top_bar.height), pos_all);
				gui->begin_content("menu_content", SCALE(0, 0), SCALE(elements->window.padding), SCALE(elements->window.padding), window_flags_no_scrollbar | window_flags_no_scroll_with_mouse);
				{
					if (var->gui.active_section == 1)
					{
						for (int i = 0; i < elements->game_card.name.size(); i++)
						{
							if (widgets->game_card(elements->game_card.name.at(i), "01.01.2025", "01.01.2025", i))
								var->gui.section_count = 2 + i;
						}
					}
				
					if (var->gui.active_section >= 2 && var->gui.active_section != 20)
					{
						gui->push_var(ImGuiStyleVar_Alpha, var->gui.content_alpha);
						widgets->loading();
						var->gui.injecting_timer += gui->fixed_speed(6.f);

						if (var->gui.injecting_timer >= 10.f)
						{
							var->gui.injecting_timer = 0;
							var->gui.section_count = 20;
						}
						gui->pop_var();
					}

					if (var->gui.active_section == 20)
						widgets->load_confirmed();
				}
				gui->end_content();
			}
		}
		gui->pop_var();
		gui->move_window(var->winapi.hwnd, var->winapi.rc);
	}
	gui->end();

	if (ImGui::IsKeyPressed(ImGuiKey_Equal) && ImGui::IsKeyDown(ImGuiKey_LeftAlt) && var->gui.stored_dpi < 200)
	{
		var->gui.stored_dpi += 10;
		var->gui.dpi_changed = true;
	}

	if (ImGui::IsKeyPressed(ImGuiKey_Minus) && ImGui::IsKeyDown(ImGuiKey_LeftAlt) && var->gui.stored_dpi > 80)
	{
		var->gui.stored_dpi -= 10;
		var->gui.dpi_changed = true;
	}

	if (var->gui.dpi != var->gui.stored_dpi / 100.f)
	{
		var->gui.dpi_changed = true;
		var->gui.update_size = true;
	}

}