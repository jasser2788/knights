#include <stdlib.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include "paartage.c"


int main(int argc, char *argv[])
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface* pScreen = SDL_SetVideoMode(1000,1000,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 0, 0, 0));
SDL_ShowCursor(SDL_DISABLE);




SDL_Flip(pScreen);

    SDL_Event event;
    SDL_EnableKeyRepeat(10,10);
   
    SDL_Init(SDL_INIT_VIDEO);


    SDL_Surface* screen=NULL;
    screen=SDL_SetVideoMode(700,400,32,SDL_HWSURFACE);

    bg b,b1;
    initialiser_background1(&b,0);
initialiser_background2(&b1,350);
 
    perso p,p1;
    init_perso(&p);
    init_perso2(&p1,666);

    int quit;
    SDL_EnableKeyRepeat(10,10);
    while (quit)
    {
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit=0;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_RIGHT :
                    animer_perso_right(&p);
                    break;
                    case SDLK_LEFT:
                    animer_perso_left(&p);
                    break;
                case SDLK_e:
                    animer_perso2_right(&p1);
                    break;
                         case SDLK_q:
                    animer_perso2_left(&p1);
                    break;
                }
            }
        }
        afficher_bg(screen,&b);
        afficher_bg(screen,&b1);
        afficher_perso(p,screen);
        afficher_perso(p1,screen);
        SDL_Flip(screen);
    }




SDL_Quit();
return EXIT_SUCCESS;

}   
