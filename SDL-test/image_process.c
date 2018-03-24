#include <SDL/SDL.h>
#include "pixel_operations.h"
#include "image_process.h"


void line_recovery (SDL_Surface *img){

	for (int j = 0; j < img->h ; j++){
		int line_found = 0;
		for (int i=0 ; i< img->w && !(line_found); i++){
			Uint32 pixel = getpixel(img,i,j);
			Uint8 r, g, b;
			SDL_GetRGB(pixel, img->format,&r,&g,&b);
			if (r == 0 && g==0 && b == 0){
				line_found = 1;
			}	
		}
		if (line_found == 0){
			color_line(img,j,j+1,0,img->w);
		}
	}
}

void color_line (SDL_Surface *img,int b_h,int e_h,int b_w,int e_w){
	//printf("color_line %d \n", j);
	for (;b_h < e_h ;b_h++){
		for(;b_w < e_w;b_w ++ ){
			Uint32 new_pixel = SDL_MapRGB(img->format,255,0,0);
			putpixel(img,b_w,b_h,new_pixel);
		}
	}
}

void seg_char (SDL_Surface *img){
	int up = 0;
	int down = 0;
	for(int j = 0; j < img->h; j++){
		Uint32 pixel = getpixel(img,0,j);
		Uint8 r, g, b;
		SDL_GetRGB(pixel, img->format,&r,&g,&b);
		if (r==255 && g==255 && b==255 && !(up)){
			up = j;
		}
		if (r == 255 && g==0 && b==0 && up){
			down = j;
		}
		if (up && down){
			color_char(img, up,down);
			up = 0;
			down = 0;
		}
	}
}

void color_char (SDL_Surface *img,int up,int down){
	
	for (int i=0; i < img->w ; i++){
		int char_found = 0;
		for (int j=up; j < down && !(char_found) ; j++){
			Uint32 pixel = getpixel(img,i,j);
			Uint8 r, g, b;
			SDL_GetRGB(pixel, img->format,&r,&g,&b);
			if (r==0 && g==0 && b==0){
				char_found =1;
			}
		}
		if (char_found == 0){
			__color_char (img,up,down,i);
		}
	}
}

void __color_char (SDL_Surface *img,int up,int down, int i){

	for (int j = up ;j < down ;j++){
		Uint32 new_pixel = SDL_MapRGB(img->format,255,0,0);
		putpixel(img,i,j,new_pixel);
	}
}
