#include "../headers/includes.h"
#include "../headers/widgets.h"

void c_widgets::login()
{
    const ImVec2 pos = gui->window_pos();
    const ImVec2 size = gui->window_size();
    
    draw->text_clipped(gui->window_drawlist(), font->get(inter_bold_data, 28), pos + SCALE(0, elements->login_page.label_padding), pos + size, draw->get_clr(clr->main.accent), "BELLATRIX", NULL, NULL, ImVec2(0.5f, 0.f));

    gui->set_pos(ImVec2(size.x / 2 - SCALE(elements->textfield.size.x / 2), SCALE(elements->login_page.label_padding) + gui->text_size(font->get(inter_bold_data, 28), "BELLATRIX").y), pos_all);
    gui->begin_content("login_zone", SCALE(SCALE(elements->textfield.size.x, elements->textfield.size.y * 2 + elements->button.login_size.y + elements->login_page.widgets_padding * 2)), SCALE(0, elements->login_page.widgets_padding), SCALE(0, elements->window.padding.y), window_flags_no_scrollbar | window_flags_no_scroll_with_mouse);
    {
        static char username[9];
        static char password[9];
        widgets->text_field("Username", "A", username, sizeof username);
        widgets->text_field("Passowrd", "B", password, sizeof password);

        if (widgets->login_button() && password == var->gui.password && username == var->gui.username)
        {
            var->gui.section_count = 1;
        }
    }
    gui->end_content();

    gui->set_pos(ImVec2(0, SCALE(elements->login_page.label_padding) + gui->text_size(font->get(inter_bold_data, 28), "BELLATRIX").y + SCALE(elements->textfield.size.y * 2 + elements->button.login_size.y + elements->login_page.widgets_padding * 2 + elements->login_page.socials_padding)), pos_all);
    gui->begin_content("social_zone", SCALE(0, 0), SCALE(0, 0), SCALE(elements->button.social_padding, 0), window_flags_no_scrollbar | window_flags_no_scroll_with_mouse);
    {
        draw->text_clipped(gui->window_drawlist(), font->get(inter_bold_data, 17), gui->window_pos(), gui->window_pos() + gui->window_size(), draw->get_clr(clr->main.accent), "JOIN OUR SOCIALS", NULL, NULL, ImVec2(0.5f, 0.f));

        gui->set_pos(ImVec2(gui->window_size().x / 2 - SCALE(elements->button.social_size.x * 1.5 + elements->button.social_padding), gui->text_size(font->get(inter_bold_data, 17), "JOIN OUR SOCIALS").y + SCALE(elements->window.padding.y)), pos_all);
        widgets->social_button("https://www.youtube.com/@ViSHER17", "D");
        gui->sameline();
        widgets->social_button("https://discord.gg/q9mCqHsvjk", "E");
        gui->sameline();
        widgets->social_button("https://discord.gg/6pCvhYEMgt", "F");
    }
    gui->end_content();
}

void c_widgets::top_bar()
{
    const ImVec2 pos = gui->window_pos();
    const ImVec2 size = gui->window_size();
    ImDrawList* drawlist = gui->window_drawlist();

    draw->text_clipped(drawlist, font->get(inter_bold_data, 19), pos + SCALE(elements->window.padding.x, 0), pos + ImVec2(size.x, SCALE(elements->top_bar.height)), draw->get_clr(clr->main.accent), "BELLATRIX", NULL, NULL, ImVec2(0.f, 0.5f));

    draw->line(drawlist, pos + ImVec2(0, SCALE(elements->top_bar.height)), pos + ImVec2(size.x, SCALE(elements->top_bar.height)), draw->get_clr(clr->window.outline), SCALE(1));

    gui->set_pos(ImVec2(size.x - SCALE(elements->button.social_size.x * 3 + elements->button.social_padding * 2 + elements->window.padding.x), SCALE(elements->window.padding.y)), pos_all);
    widgets->social_button("https://www.youtube.com/@ViSHER17", "D");
    gui->sameline(0, SCALE(elements->button.social_padding));
    widgets->social_button("https://discord.gg/q9mCqHsvjk", "E");
    gui->sameline(0, SCALE(elements->button.social_padding));
    widgets->social_button("https://discord.gg/6pCvhYEMgt", "F");

}

void c_widgets::loading()
{
    const ImVec2 pos = gui->window_pos();
    const ImVec2 size = gui->window_size();
    ImDrawList* drawlist = gui->window_drawlist();

    static float timer = 0.f;

    timer += gui->fixed_speed(6.f);
    if (timer >= 100.f)
        timer = 0.f;

    bool active = timer >= 0.f;

    const ImRect load_icon(pos + SCALE(elements->loading.icon_padding), pos + SCALE(elements->loading.icon_padding) + ImVec2(gui->text_size(font->get(icons_data, 72), "H")));


    draw->rotate_start(drawlist);
    draw->text_clipped(drawlist, font->get(icons_data, 72), load_icon.Min, load_icon.Max, draw->get_clr(clr->main.accent), "H", NULL, NULL, ImVec2(0.5f, 0.5f));
    draw->rotate_end(drawlist, 45 * timer, load_icon.GetCenter());

    draw->rotate_start(drawlist);
    draw->text_clipped(drawlist, font->get(icons_data, 43), load_icon.Min, load_icon.Max, draw->get_clr(clr->main.accent), "I", NULL, NULL, ImVec2(0.5f, 0.5f));
    draw->rotate_end(drawlist, -45 * timer, load_icon.GetCenter());

    draw->text_clipped(drawlist, font->get(inter_medium_data, 13), ImVec2(pos.x, load_icon.Max.y + SCALE(elements->loading.padding)), pos + size, draw->get_clr(clr->textfield.text), "Downloading injector data wait for some time ...", NULL, NULL, ImVec2(0.5f, 0.f));
}

void c_widgets::load_confirmed()
{
    const ImVec2 pos = gui->window_pos();
    const ImVec2 size = gui->window_size();
    ImDrawList* drawlist = gui->window_drawlist();

    draw->text_clipped(drawlist, font->get(inter_medium_data, 13), pos - SCALE(0, elements->button.login_size.y + elements->loading.padding) / 2, pos + size - SCALE(0, elements->button.login_size.y + elements->loading.padding) / 2, draw->get_clr(clr->textfield.text), "Downloading cannot be performed", NULL, NULL, ImVec2(0.5f, 0.5f));

    gui->set_pos(size - SCALE(elements->loading.confirmed_padding + elements->button.login_size), pos_all);
    if (widgets->back_button())
        var->gui.section_count = 1;
}
