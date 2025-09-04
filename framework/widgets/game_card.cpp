#include"../headers/includes.h"
#include "../headers/widgets.h"

bool c_widgets::game_card(std::string_view name, std::string_view launch, std::string_view update, int img_id)
{
    struct game_state
    {
        float alpha{ 0.f };
        ImVec4 text{ clr->main.text_black };
        ImVec4 rect{ clr->window.outline };
        bool clicked{ false };
    };

    ImGuiWindow* window = gui->get_window();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(name.data());

    const ImVec2 pos = window->DC.CursorPos;

    const ImRect total(pos, pos + ImVec2(gui->content_avail().x, SCALE(elements->game_card.height)));
    const ImRect button_rect(ImVec2(total.Max.x - SCALE(elements->game_card.load_padding.x + elements->button.load_size.x), total.Min.y + SCALE(elements->game_card.load_padding.y)), total.Max - SCALE(elements->game_card.load_padding));

    gui->item_size(total, style.FramePadding.y);
    if (!gui->item_add(total, id))
        return false;

    bool hovered = gui->item_hoverable(button_rect, id, g.LastItemData.InFlags);
    bool pressed = hovered && g.IO.MouseClicked[0];
    game_state* state = gui->anim_container(&state, id);

    if (pressed)
    {
        state->clicked = true;
    }
    if (state->alpha >= 0.99)
        state->clicked = false;

    gui->easing(state->text, state->clicked ? clr->main.text.Value : clr->main.text_black.Value, 12.f, dynamic_easing);
    gui->easing(state->rect, state->clicked ? clr->window.outline.Value : clr->main.accent.Value, 12.f, dynamic_easing);

    gui->easing(state->alpha, state->clicked ? 1.f : 0.f, 4.f, static_easing);

    draw->rect_filled(window->DrawList, total.Min, total.Max, draw->get_clr(clr->game_card.background, 0.5), SCALE(var->window.rounding));
    draw->image_rounded(window->DrawList, var->gui.games[img_id], total.Min, ImVec2(total.Min.x + SCALE(elements->game_card.img_width), total.Max.y), ImVec2(0, 0), ImVec2(1, 1), draw->get_clr({ 1.f, 1.f, 1.f, 1.f }), SCALE(var->window.rounding), draw_flags_round_corners_left);
    draw->rect(window->DrawList, total.Min, total.Max, draw->get_clr(clr->game_card.outline), SCALE(var->window.rounding));

    draw->rect_filled(window->DrawList, button_rect.Min, button_rect.Max, draw->get_clr(state->rect), SCALE(elements->textfield.rounding));

    draw->text_clipped(window->DrawList, font->get(icons_data, 16), button_rect.Min, button_rect.Max, draw->get_clr(state->text), "G", NULL, NULL, ImVec2(0.5f, 0.5f));

    draw->text_clipped(window->DrawList, font->get(inter_medium_data, 11), total.Min + SCALE(elements->game_card.padding) + SCALE(elements->game_card.img_width, -2), total.Max, draw->get_clr(clr->main.accent), "Last launch:");
    draw->text_clipped(window->DrawList, font->get(inter_medium_data, 11), total.Min + SCALE(elements->game_card.padding) + SCALE(elements->game_card.img_width, 0), total.Max - SCALE(0, elements->game_card.padding.y - 2), draw->get_clr(clr->game_card.text), launch.data(), NULL, NULL, ImVec2(0.f, 1.f));

    draw->text_clipped(window->DrawList, font->get(inter_medium_data, 11), total.Min + ImVec2(SCALE(elements->game_card.padding.x * 2 + elements->game_card.img_width) + gui->text_size(font->get(inter_medium_data, 11), "Last launch:").x, SCALE(elements->game_card.padding.y - 2)), total.Max, draw->get_clr(clr->main.accent), "Last update:");
    draw->text_clipped(window->DrawList, font->get(inter_medium_data, 11), total.Min + ImVec2(SCALE(elements->game_card.padding.x * 2 + elements->game_card.img_width) + gui->text_size(font->get(inter_medium_data, 11), "Last launch:").x, SCALE(elements->game_card.padding.y)), total.Max - SCALE(0, elements->game_card.padding.y - 2), draw->get_clr(clr->game_card.text), update.data(), NULL, NULL, ImVec2(0.f, 1.f));

    return state->clicked;
}
