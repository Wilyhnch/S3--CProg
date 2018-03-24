#include <SDL/SDL.h>

#include <stdlib.h>
#include <stdio.h>
#include "pixel_operations.h"

struct MatImg {
	int width;
	int height;
	int* mat;
};

struct MatImg ImgToMat(SDL_Surface *img);
void PrintMat(struct MatImg res,int begin_h,int end_h, int begin_w,int end_w);
void FillMatClear(struct MatImg res, int h_begin,int h_end,int w_begin,int w_end);
void Crop_Char(struct MatImg res);
void __Crop_Char(struct MatImg res,int begin,int end);
SDL_Surface MatToIm(struct MatImg res); 


