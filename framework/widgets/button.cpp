#include"../headers/includes.h"
#include "../headers/widgets.h"

bool c_widgets::login_button()
{
    struct log_button_state
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
    const ImGuiID id = window->GetID("LOGIN");

    const ImVec2 pos = window->DC.CursorPos;

    const ImRect total(pos, pos + SCALE(elements->button.login_size));

    gui->item_size(total, style.FramePadding.y);
    if (!gui->item_add(total, id))
        return false;

    bool hovered = gui->item_hoverable(total, id, g.LastItemData.InFlags);
    bool pressed = hovered && g.IO.MouseClicked[0];
    log_button_state* state = gui->anim_container(&state, id);

    if (pressed)
        state->clicked = true;
    if (state->alpha >= 0.999)
        state->clicked = false;

    gui->easing(state->text, state->clicked ? clr->main.text.Value : clr->main.text_black.Value, 12.f, dynamic_easing);
    gui->easing(state->rect, state->clicked ? clr->window.outline.Value : clr->main.accent.Value, 12.f, dynamic_easing);

    gui->easing(state->alpha, state->clicked ? 1.f : 0.f, 4.f, static_easing);

    draw->rect_filled(window->DrawList, total.Min, total.Max, draw->get_clr(state->rect), SCALE(elements->textfield.rounding));

    draw->text_clipped(window->DrawList, font->get(inter_semi_bold_data, 14), total.Min + ImVec2(gui->text_size(font->get(icons_data, 11), "C").x + SCALE(elements->window.padding.x), 0) / 2, total.Max + ImVec2(gui->text_size(font->get(icons_data, 11), "C").x + SCALE(elements->window.padding.x), 0) / 2, draw->get_clr(state->text), "LOGIN", NULL, NULL, ImVec2(0.5f, 0.5f));
    draw->text_clipped(window->DrawList, font->get(icons_data, 11), total.Min - ImVec2(gui->text_size(font->get(inter_semi_bold_data, 14), "LOGIN").x + SCALE(elements->window.padding.x), 0) / 2, total.Max - ImVec2(gui->text_size(font->get(inter_semi_bold_data, 14), "LOGIN").x + SCALE(elements->window.padding.x), 0) / 2, draw->get_clr(state->text), "C", NULL, NULL, ImVec2(0.5f, 0.5f));

    return state->clicked;
}

bool c_widgets::social_button(std::string_view name, std::string_view icon)
{
    struct social_state
    {
        float alpha{ 0.f };
        ImVec4 icon{ clr->textfield.text };
        bool clicked{ false };
    };

    ImGuiWindow* window = gui->get_window();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(icon.data());

    const ImVec2 pos = window->DC.CursorPos;

    const ImRect total(pos, pos + SCALE(elements->button.social_size));

    gui->item_size(total, style.FramePadding.y);
    if (!gui->item_add(total, id))
        return false;

    bool hovered = gui->item_hoverable(total, id, g.LastItemData.InFlags);
    bool pressed = hovered && g.IO.MouseClicked[0];
    social_state* state = gui->anim_container(&state, id);

    if (pressed)
    {
        state->clicked = true;
        gui->open_url(name);
    }
    if (state->alpha >= 0.99)
        state->clicked = false;

    gui->easing(state->icon, hovered ? clr->main.text.Value : clr->textfield.text.Value, 12.f, dynamic_easing);

    gui->easing(state->alpha, state->clicked ? 1.f : 0.f, 4.f, static_easing);

    draw->text_clipped(window->DrawList, font->get(icons_data, 15), total.Min, total.Max, draw->get_clr(state->icon), icon.data(), gui->text_end(icon.data()), NULL, ImVec2(0.5f, 0.5f));

    return state->clicked;
}

bool c_widgets::back_button()
{
    struct log_button_state
    {
        float alpha{ 0.f };
        ImVec4 text{ clr->main.text };
        bool clicked{ false };
    };

    ImGuiWindow* window = gui->get_window();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    std::string name = "BACK##" + std::to_string(var->gui.active_section);

    const ImGuiID id = window->GetID(name.data());

    const ImVec2 pos = window->DC.CursorPos;

    const ImRect total(pos, pos + SCALE(elements->button.login_size));

    gui->item_size(total, style.FramePadding.y);
    if (!gui->item_add(total, id))
        return false;

    bool hovered = gui->item_hoverable(total, id, g.LastItemData.InFlags);
    bool pressed = hovered && g.IO.MouseClicked[0];
    log_button_state* state = gui->anim_container(&state, id);

    if (pressed)
        state->clicked = true;
    if (var->gui.content_alpha <= 0.01f)
    {
        state->clicked = false;
        state->alpha = 0.f;
    }

    gui->easing(state->text, state->clicked ? clr->main.text_black.Value : clr->main.text.Value, 12.f, dynamic_easing);

    gui->easing(state->alpha, state->clicked ? 1.f : 0.f, 8.f, static_easing);

    draw->rect(window->DrawList, total.Min, total.Max, draw->get_clr(clr->window.outline), SCALE(elements->textfield.rounding));

    draw->rect_filled(window->DrawList, total.Min, total.Max, draw->get_clr(clr->main.accent, state->alpha), SCALE(elements->textfield.rounding));

    draw->text_clipped(window->DrawList, font->get(inter_semi_bold_data, 14), total.Min, total.Max, draw->get_clr(state->text), name.data(), gui->text_end(name.data()), NULL, ImVec2(0.5f, 0.5f));

    return state->clicked;
}
