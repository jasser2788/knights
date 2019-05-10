#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


void pause()
{
    int continuer = 1;
    SDL_Event event;


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
int main(void)
{
SDL_Surface *ecran = NULL,*image=NULL,*image2=NULL;

    SDL_Rect position,position2;
SDL_Event event;
int continuer = 1;
    position.x=0;
    position.y=0;
    position2.x=0;
    position2.y=200;
FILE* f =NULL;
    

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

     SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    image =SDL_LoadBMP("background.bmp");
    image2=IMG_Load("detective.png");
    SDL_BlitSurface(image,NULL,ecran,&position);
    SDL_BlitSurface(image2,NULL,ecran,&position2);
SDL_SetColorKey(image2, SDL_SRCCOLORKEY, SDL_MapRGB(image2->format, 255, 255,255));
SDL_EnableKeyRepeat(10,10);
 while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        position2.y=position2.y-15;
                        break;
                    case SDLK_DOWN:
			position2.y=position2.y+15;
			break;	
		    case SDLK_LEFT:
			position2.x=position2.x-15;
			break;
		    case SDLK_RIGHT:
			position2.x=position2.x+15;
			break;
                    case SDLK_ESCP:
                         

f=fopen(nomfich"w";);
fprintf(f,"%d %d \n",position2.x,position2.y);

fclose(f);
                        ;
 			break;
                        
                }
        }
SDL_BlitSurface(image,NULL,ecran,&position);
SDL_BlitSurface(image2,NULL,ecran,&position2);
SDL_SetColorKey(image2, SDL_SRCCOLORKEY, SDL_MapRGB(image2->format, 255, 255,255));
SDL_Flip(ecran);
}   


  

    SDL_Flip(ecran);
    pause();
   


   
    SDL_Quit();

    return EXIT_SUCCESS;
}
