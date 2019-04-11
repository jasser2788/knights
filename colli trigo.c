#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <math.h>
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



int main (void)
{

SDL_Surface *screen =NULL,*back=NULL,*circle=NULL,*box=NULL;
SDL_Rect backpos,circlepos,boxpos;
SDL_Event event;
int boucle=1,x,y;
float a,b,r;

SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(780,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
if (screen==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
backpos.x=0;
backpos.y=0;

circlepos.x=300;
circlepos.y=174;

boxpos.x=15;
boxpos.y=0;


back= IMG_Load("menu.png");
SDL_BlitSurface(back, NULL, screen, &backpos);


circle=IMG_Load("circle.png");
SDL_BlitSurface(circle, NULL, screen, &circlepos);
SDL_Flip(screen);

box=IMG_Load("box.png");
SDL_BlitSurface(box, NULL, screen, &boxpos);
SDL_Flip(screen);

SDL_EnableKeyRepeat(10,15);

a=circlepos.x+(circlepos.w/2);
b=circlepos.y+(circlepos.h/2);
r=(circlepos.w/2)*(circlepos.w/2);//rayon carre


while(boucle)
{
SDL_WaitEvent(&event); 
    switch(event.type)              
{        case SDL_QUIT: 
          
  boucle= 0;
SDL_Quit();

            break;
case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
              case SDLK_RIGHT:

if( ( ( ( ((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r &&( (((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+((boxpos.y-b)*(boxpos.y-b)))>r  && ( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-(boxpos.x+boxpos.w))*(a-(boxpos.x+boxpos.w))) > r) )  )
boxpos.x+=8;

             break;   
 case SDLK_LEFT:
if( ( ( ( (boxpos.x-a)*(boxpos.x-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r &&( ((boxpos.x-a)*(boxpos.x-a))+((boxpos.y-b)*(boxpos.y-b)))>r  && ( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-boxpos.x)*(a-boxpos.x)) > r) )  )

boxpos.x-=8;

             break;   
 case SDLK_DOWN:
if( ( ( ( ((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r  && ( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-(boxpos.y+boxpos.h))*(b-(boxpos.y+boxpos.h))) > r) )&&( ( ( (boxpos.x-a)*(boxpos.x-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r ) 
boxpos.y+=8;


             break;   
 case SDLK_UP:
if ( ( ( ( (boxpos.x-a)*(boxpos.x-a))+((boxpos.y-b)*(boxpos.y-b))) )>r && ( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-boxpos.y)*(b-boxpos.y)) > r) )&&( (((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+((boxpos.y-b)*(boxpos.y-b)))>r  )       
boxpos.y-=8;

             break;   

}
case SDL_MOUSEMOTION:

x=event.motion.x;
y=event.motion.y;
if((((x-a)*(x-a))+((y-b)*(y-b)))<=r)
box=IMG_Load("box2.png");
else box=IMG_Load("box.png");
break;
}
SDL_BlitSurface(back, NULL, screen, &backpos);
SDL_BlitSurface(circle, NULL, screen, &circlepos);
SDL_BlitSurface(box, NULL, screen, &boxpos);
SDL_Flip(screen);
}      
//pause();
return 0;
}
