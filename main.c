#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include "header.h"
int main(void)
{
    SDL_Surface *ecran = NULL, *background = NULL, *image1 = NULL;
    SDL_Rect positionbackground,positionimage1;
    
    int a;
		//fonction 

SDL_Rect clip[3];



clip[0].x=0;
clip[0].y=0;
clip[0].w=200;
clip[0].h=250;

clip[1].x=411;
clip[1].y=0;
clip[1].w=240;
clip[1].h=250;

clip[2].x=780;
clip[2].y=0;
clip[2].w=240;
clip[2].h=250;

clip[3].x=1175;
clip[3].y=0;
clip[3].w=240;
clip[3].h=250;

SDL_Rect camera;
camera.x=0;
camera.y=0;
camera.w=1300;
camera.h=475;


		//finfonction 
    positionbackground.x = 0;
    positionbackground.y = 0;
    positionimage1.x = 0;
    positionimage1.y = 250;
    positionimage1.w=200;
    positionimage1.h=250;
 

    a=SDL_Init(SDL_INIT_VIDEO);


    ecran = SDL_SetVideoMode(1300, 475, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 
    background = SDL_LoadBMP("background.bmp");
    SDL_BlitSurface(background,&camera, ecran, &positionbackground);
 
    
    image1 = SDL_LoadBMP("charsetf.bmp");
   //
	//SDL_BlitSurface(image1,&clip[0],ecran,&positionimage1);
 
SDL_Flip(ecran);
SDL_SetColorKey(image1 ,SDL_SRCCOLORKEY, SDL_MapRGB(image1->format, 255,255,255));
SDL_EnableKeyRepeat(75,30);
SDL_ShowCursor(SDL_DISABLE);
	anim_scroll(clip , ecran , background ,image1 , camera ,positionbackground,  positionimage1);
       SDL_FreeSurface(background);
    SDL_FreeSurface(image1);
    
    SDL_Quit();

    return 0;
}

