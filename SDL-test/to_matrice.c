#include "to_matrice.h"

struct MatImg ImgToMat(SDL_Surface *img){
	//printf ("%d / %d \n", img->w , img->h);
	int width = img->w;
	int height = img->h;
	struct MatImg res;
	res.mat = malloc(sizeof(int) * width * height);
	res.width = width;
	res.height = height;
	int begin = 0;
	int line_found = 0;
	for (int j = 0 ; j < height ; j++){
		int line = 0;
		for (int i = 0; i < width; i++){
			//printf("test %d / %d ", i , j);
			Uint32 pixel = getpixel(img,i,j);
			Uint8 r, g, b;
			SDL_GetRGB(pixel, img->format,&r,&g,&b);
			if (r == 0){
				//printf("r == 0 \n ");
				line =1;
				res.mat[i + j * res.width] = 1;  
				if (!(line_found)){
					//printf("here");
					line_found = 1;
					line = 1;
					FillMatClear(res,begin,j,0,res.width);
				}
			}else{
				//printf("else \n");
				res.mat[i + j * res.width] = 0; 
			}
		}
		if(!(line) && (line_found)){
			//printf("in if \n");
			begin = j;
			line_found =0;
		}
	}
	FillMatClear(res,begin,res.height,0,res.width);
	return res;
}

void Crop_Char (struct MatImg res){
	int begin = 0;
	int found = 0;
	for (int j = 0; j < res.height ; j++){
		if (res.mat[0+j*res.width] != 2 && !(found)){
			found = 1;
			begin = j;
		}
		if (res.mat[0+j*res.width] == 2 && found){
			printf("%d / %d \n",begin,j);
			__Crop_Char(res,begin,j);
			found = 0;
			begin = 0;
		}
	}
}

void __Crop_Char(struct MatImg res,int begin ,int end){
	int begin_w = 0;
	int end_h = end;
	int char_found = 0;
	int empty_line = 1;
	for (int i = 0 ; i < res.width; i++){
		empty_line = 1;
		for(int begin_h = begin ; begin_h < end_h ; begin_h++){
			if (res.mat[i + begin_h*res.width] == 1){
				if (!(char_found)){
					begin_w = i;
					char_found = 1;
				}
				empty_line = 0;
			}
		}
		//printf("%d / %d \n",empty_line,char_found);
		if (empty_line && char_found){
			//printf("%d / %d and %d/%d \n" ,begin,end_h,begin_w,i);
			PrintMat(res,begin,end_h,begin_w,i);
			empty_line = 1;
			char_found = 0;
		}
	}
}


void FillMatClear(struct MatImg res,int h_begin,int h_end,int w_begin,int w_end){
	//printf("test fill \n");
	for (int j = h_begin; j < h_end; j++){
		for (int i = w_begin; i < w_end;i++)
			res.mat[i+j*res.width] = 2;
	}
}


void PrintMat(struct MatImg res,int begin_h,int end_h,int begin_w,int end_w){
	printf("\n");
	for (int j = begin_h; j<end_h;j++){
		for(int i= begin_w; i<end_w;i++){
			if(res.mat[i+j*res.width] == 1){
				printf("0");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

SDL_Surface MatToIm(struct MatImg res){
	SDL_Surface *img;
	img = SDL_CreateRGBSurface(0,res.width,res.height,32,0,0,0,0);
	for (int i = 0; i < res.width; i++){
		for(int j = 0 ; j < res.height;j++ ){
			if (res.mat[i+j*res.width] == 0){
				Uint32 pixel = SDL_MapRGB(img->format,255,255,255);
				putpixel(img,i,j,pixel);
			}else{
				if (res.mat[i+j*res.width] == 1){				
					Uint32 pixel = SDL_MapRGB(img->format,0,0,0);
					putpixel(img,i,j,pixel);
				}else{
					Uint32 pixel = SDL_MapRGB(img->format,255,0,0);
					putpixel(img,i,j,pixel);
				}
			}
		}
	}
	return *img;
}

