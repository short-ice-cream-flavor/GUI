#pragma once
#include "includes.h"

#define IMGUI_DEFINE_MATH_OPERATORS

class c_widgets
{
public:

    void login();

    bool text_field(std::string_view name, std::string_view icon, char* buf, int size);

    bool login_button();

    bool social_button(std::string_view name, std::string_view icon);

    void top_bar();

    bool game_card(std::string_view name, std::string_view launch, std::string_view update, int img_id);

    void loading();

    bool back_button();

    void load_confirmed();

};

inline std::unique_ptr<c_widgets> widgets = std::make_unique<c_widgets>();

enum notify_type
{
    success = 0,
    warning = 1,
    error = 2
};

struct notify_state
{
    int notify_id;
    std::string_view text;
    notify_type type{ success };

    ImVec2 window_size{ 0, 0 };
    float notify_alpha{ 0 };
    bool active_notify{ true };
    float notify_timer{ 0 };
    float notify_pos{ 0 };
};

class c_notify
{
public:
    void setup_notify();

    void add_notify(std::string_view text, notify_type type);

private:
    ImVec2 render_notify(int cur_notify_value, float notify_alpha, float notify_percentage, float notify_pos, std::string_view text, notify_type type);

    float notify_time{ 15 };
    int notify_count{ 0 };

    float notify_spacing{ 20 };
    ImVec2 notify_padding{ 20, 20 };

    std::vector<notify_state> notifications;

};

inline std::unique_ptr<c_notify> notify = std::make_unique<c_notify>();
