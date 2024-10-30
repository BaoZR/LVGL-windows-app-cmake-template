#include <Windows.h>
#include "lvgl/lvgl.h"
#include <stdio.h>

static lv_style_t style_font;
static const lv_font_t* font_size;



void my_demo() {
    font_size = &lv_font_montserrat_24;
    lv_obj_t* parent = lv_screen_active();
    lv_obj_t* panel = lv_obj_create(parent);
    lv_obj_set_height(panel, LV_SIZE_CONTENT);

    lv_style_init(&style_font);
    lv_style_set_text_font(&style_font, font_size);

    lv_obj_t* a_label = lv_label_create(panel);
    lv_label_set_text(a_label, "a");
    lv_obj_add_style(a_label, &style_font, 0);

    lv_obj_t* b_label = lv_label_create(panel);
    lv_label_set_text(b_label, "b");
    lv_obj_add_style(b_label, &style_font, 0);

    lv_obj_t* a_area = lv_textarea_create(panel);
    lv_textarea_set_one_line(a_area, true);
    lv_obj_add_style(a_area, &style_font, 0);

    lv_textarea_set_accepted_chars(a_area, "0123456789 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    //lv_textarea_set_text_selection(a_area, true);
    //lv_obj_set_style_text_color(lv_textarea_get_label(a_area), lv_color_hex(0x00BFFF), LV_PART_SELECTED);
    

    lv_obj_t* b_area = lv_textarea_create(panel);
    lv_textarea_set_one_line(b_area, true);
    lv_obj_add_style(b_area, &style_font, 0);

    lv_obj_t* seed_btn = lv_button_create(panel);
    lv_obj_set_height(seed_btn, LV_SIZE_CONTENT);


    lv_obj_t* seed_btn_label = lv_label_create(seed_btn);
    lv_label_set_text(seed_btn_label, "f");
    lv_obj_add_style(seed_btn_label, &style_font, 0);

    lv_obj_t* key_btn  = lv_button_create(panel);
    lv_obj_set_height(key_btn, LV_SIZE_CONTENT);

    lv_obj_t* key_btn_label = lv_label_create(key_btn);
    lv_label_set_text(key_btn_label, "e");
    lv_obj_add_style(key_btn_label, &style_font, 0);


    lv_obj_t* key_label = lv_label_create(panel);
    lv_label_set_text(key_label, "g");
    lv_obj_add_style(key_label, &style_font, 0);


    lv_obj_t* key_area = lv_textarea_create(panel);
    lv_textarea_set_one_line(key_area, true);
    lv_obj_add_style(key_area, &style_font, 0);

    lv_obj_t* seed_label = lv_label_create(panel);
    lv_label_set_text(seed_label, "h");
    lv_obj_add_style(seed_label, &style_font, 0);

    lv_obj_t* seed_area = lv_textarea_create(panel);
    lv_textarea_set_one_line(seed_area, true);
    lv_obj_add_style(seed_area, &style_font, 0);

    

    lv_obj_t* c_label = lv_label_create(panel);
    lv_obj_t* d_label = lv_label_create(panel);
    lv_obj_add_style(c_label, &style_font, 0);
    lv_obj_add_style(d_label, &style_font, 0);

    lv_label_set_text(d_label, "d");
    lv_label_set_text(c_label, "c");
    lv_obj_t* c_area = lv_textarea_create(panel);
    lv_obj_t* d_area = lv_textarea_create(panel);
    lv_obj_add_style(c_area, &style_font, 0);
    lv_obj_add_style(d_area, &style_font, 0);

    lv_textarea_set_one_line(c_area, true);
    lv_textarea_set_one_line(d_area, true);
    lv_obj_t* decrypt_btn = lv_button_create(panel);
    lv_obj_t* encrypt_btn = lv_button_create(panel);
    lv_obj_set_height(decrypt_btn, LV_SIZE_CONTENT);
    lv_obj_set_height(encrypt_btn, LV_SIZE_CONTENT);
    lv_obj_t* decrypt_btn_label = lv_label_create(decrypt_btn);
    lv_obj_t* encrypt_btn_label = lv_label_create(encrypt_btn);
    lv_obj_add_style(decrypt_btn_label, &style_font, 0);
    lv_obj_add_style(encrypt_btn_label, &style_font, 0);

    lv_label_set_text(decrypt_btn_label, "" LV_SYMBOL_DOWN);
    lv_label_set_text(encrypt_btn_label, "" LV_SYMBOL_UP);
    lv_obj_t* text_area = lv_textarea_create(panel);



    static int32_t grid_main_col_dsc[] = { LV_GRID_FR(1),LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST };
    static int32_t grid_main_row_dsc[] = { LV_GRID_CONTENT,LV_GRID_CONTENT,  LV_GRID_TEMPLATE_LAST };
    static int32_t grid_1_col_dsc[] = { LV_GRID_CONTENT, LV_GRID_FR(2), LV_GRID_CONTENT, LV_GRID_CONTENT,   LV_GRID_FR(2), LV_GRID_TEMPLATE_LAST};
    static int32_t grid_1_row_dsc[] = { LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT,LV_GRID_CONTENT, LV_GRID_CONTENT,LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST };
    lv_obj_set_grid_dsc_array(parent, grid_main_col_dsc, grid_main_row_dsc);

    lv_obj_set_grid_cell(panel, LV_GRID_ALIGN_STRETCH, 0, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_dsc_array(panel, grid_1_col_dsc, grid_1_row_dsc);
    lv_obj_set_grid_cell(a_label, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(b_label, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(a_area, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_set_grid_cell(b_area, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_cell(seed_btn, LV_GRID_ALIGN_CENTER, 2, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(key_btn, LV_GRID_ALIGN_CENTER, 2, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(key_label, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(seed_label, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(key_area, LV_GRID_ALIGN_STRETCH, 4, 1, LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_set_grid_cell(seed_area, LV_GRID_ALIGN_STRETCH, 4, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    lv_obj_set_grid_cell(c_label, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(c_area, LV_GRID_ALIGN_STRETCH, 1, 4, LV_GRID_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(encrypt_btn, LV_GRID_ALIGN_START, 4, 1, LV_GRID_ALIGN_CENTER, 3, 1);
    lv_obj_set_grid_cell(decrypt_btn, LV_GRID_ALIGN_END, 1, 1, LV_GRID_ALIGN_CENTER, 3, 1);

    lv_obj_set_grid_cell(d_label, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 4, 1);
    lv_obj_set_grid_cell(d_area, LV_GRID_ALIGN_STRETCH, 1, 4, LV_GRID_ALIGN_CENTER, 4, 1);

    lv_obj_set_grid_cell(text_area, LV_GRID_ALIGN_STRETCH, 0,5, LV_GRID_ALIGN_STRETCH, 5, 1);


}

int main(int argc,char* arv[]) {
    ::lv_init();

    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = false;
    lv_display_t* display = ::lv_windows_create_display(
        L"LVGL Windows Application Display 1",
        800,
        600,
        zoom_level,
        allow_dpi_override,
        simulator_mode);
    if (!display)
    {
        return -1;
    }

    HWND window_handle = ::lv_windows_get_display_window_handle(display);
    if (!window_handle)
    {
        return -1;
    }

     lv_indev_t* pointer_indev = ::lv_windows_acquire_pointer_indev(display);
    if (!pointer_indev)
    {
        return -1;
    }

    lv_indev_t* keypad_indev = ::lv_windows_acquire_keypad_indev(display);
    if (!keypad_indev)
    {
        return -1;
    }

    lv_indev_t* encoder_indev = ::lv_windows_acquire_encoder_indev(display);
    if (!encoder_indev)
    {
        return -1;
    }

    //::lv_demo_widgets();
    //::lv_demo_benchmark();
    //lv_textarea_set_one_line

    my_demo();


    while (1)
    {
        uint32_t time_till_next = ::lv_timer_handler();
        ::Sleep(time_till_next);
    }

    return 0;
}
