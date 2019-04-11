#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include "header.h"
void anim_scroll(SDL_Rect clip[] , SDL_Surface *ecran ,SDL_Surface *background ,SDL_Surface *image1 , SDL_Rect camera ,SDL_Rect positionbackground, SDL_Rect positionimage1){
int continuer =1;
int frame=0;
SDL_Event event;
const int speed=20;
while (continuer == 1)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
	    case SDL_MOUSEMOTION: 
			
                        break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {   
		    case SDLK_ESCAPE:
			continuer=0;
			break; 
		    case SDLK_UP: 
                         
                         camera.y-=speed;

                        break;
                   
                    case SDLK_RIGHT:
                   if (positionimage1.x > ecran->w*3/4)
                        {   camera.x+=speed;
                         if (camera.x>=2000)
                          
camera.x=2000;
}

			else
positionimage1.x+=20;
		    break;

                    case SDLK_LEFT: 
			if (positionimage1.x < ecran->w/4)
                        { 
                           camera.x-=speed;
if (camera.x<=0)
camera.x=0;
                        }   

			else
positionimage1.x-=20;


                        break;
		    
                }
               

                
}
 
	SDL_BlitSurface(background,&camera,ecran, &positionbackground);
        SDL_BlitSurface(image1,&clip[frame], ecran, &positionimage1);
        SDL_Flip(ecran);
frame++;
 if(frame==4)
{
frame = 0;
}       
}
}
 
