#include "scene.h"

ALLEGRO_FONT *font = NULL;
ALLEGRO_BITMAP *background = NULL;

bool mouse_in_range(int mouse_x, int mouse_y, int x1, int y1, int x2, int y2) {
    return (mouse_x >= x1 && mouse_x <= x2 && mouse_y >= y1 && mouse_y <= y2) ? true : false;
}

// function of menu
void menu_init(){
    font = al_load_ttf_font("./font/pirulen.ttf",12,0);
}
void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) {
        if( mouse_in_range(event.mouse.x, event.mouse.y, WIDTH/2-40, 510, WIDTH/2+40, 550) ) {
            judge_next_window = true;
            menu_button_type = 1;
        } else if( mouse_in_range(event.mouse.x, event.mouse.y, WIDTH/2-40, 410, WIDTH/2+40, 450) ) {
            judge_next_window = true;
            menu_button_type = 2;
        } else if( mouse_in_range(event.mouse.x, event.mouse.y, WIDTH/2-40, 310, WIDTH/2+40, 350) ) {
            judge_next_window = true;
            menu_button_type = 3;
        }
    }
}
void menu_draw(){
    al_clear_to_color(al_map_rgb(100,50,0));

    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Play");
    al_draw_rectangle(WIDTH/2-40, 510, WIDTH/2+40, 550, al_map_rgb(255, 255, 255), 0);

    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+120 , ALLEGRO_ALIGN_CENTRE, "Store");
    al_draw_rectangle(WIDTH/2-40, 410, WIDTH/2+40, 450, al_map_rgb(255, 255, 255), 0);

    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+20 , ALLEGRO_ALIGN_CENTRE, "Intro");
    al_draw_rectangle(WIDTH/2-40, 310, WIDTH/2+40, 350, al_map_rgb(255, 255, 255), 0);
}
void menu_destroy(){
    al_destroy_font(font);
}

// function of game_scene
void game_scene_init(){
    character_init();
    background = al_load_bitmap("./image/stage.jpg");
}
void game_scene_draw(){
    al_draw_bitmap(background, 0, 0, 0);
    character_draw();

}
void game_scene_destroy(){
    al_destroy_bitmap(background);
    character_destory();
}

// function of intro_scene
void intro_scene_init(){
    font = al_load_ttf_font("./font/pirulen.ttf",12,0);
}
void intro_scene_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) {
        if( mouse_in_range(event.mouse.x, event.mouse.y, WIDTH/2-30, 510, WIDTH/2+30, 550) ) {
            judge_next_window = true;
        }
    }
}
void intro_scene_draw(){
    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 180 , ALLEGRO_ALIGN_CENTRE, "Cookie Run is an exciting game ");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 200 , ALLEGRO_ALIGN_CENTRE, "that combines endless running ");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 220 , ALLEGRO_ALIGN_CENTRE, "and platforming. Play as ");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 240 , ALLEGRO_ALIGN_CENTRE, "gingerbread man, dodging obstacles, ");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 260 , ALLEGRO_ALIGN_CENTRE, "collecting rewards, and running ");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, 280 , ALLEGRO_ALIGN_CENTRE, "as far as you can!!! ");


    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "back");
    al_draw_rectangle(WIDTH/2-30, 510, WIDTH/2+30, 550, al_map_rgb(255, 255, 255), 0);
}
void intro_scene_destroy(){
    al_destroy_font(font);
}
