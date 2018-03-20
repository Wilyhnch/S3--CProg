// image_process.h

#ifndef IMAGE_PROCESS_H_
#define IMAGE_PROCESS_H_

#include <stdlib.h>

void line_recovery (SDL_Surface *img);
void color_line (SDL_Surface *img,int j);
void seg_char(SDL_Surface *img);
void color_char(SDL_Surface *img,int up, int down);
void __color_char(SDL_Surface *img,int up, int down,int i);

#endif

