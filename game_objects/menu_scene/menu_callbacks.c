/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_callbacks
*/

#include "my_rpg.h"

void quit_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    if (button || scene || eve)
        prog_stat->running = 0;
}

void start_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    list_t *sound = get_next_sound_cell(prog_stat->musics_sounds->sounds_list);

    if (button || scene || eve)
        prog_stat->scene_index = game_scene;
    sfMusic_pause(get_music_sound_cursor(prog_stat->musics_sounds->musics_list
    , menu_background_music)->data->music->music);
    sfSound_setBuffer(sound->data->sound->sound, get_music_sound_cursor
    (prog_stat->musics_sounds->sounds_buffer_list
    , button_click)->data->buffer->buffer);
    sfSound_play(sound->data->sound->sound);
}