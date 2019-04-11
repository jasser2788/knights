#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <math.h>
int collisiontrigo (SDL_Surface *  box,SDL_Surface *circle,SDL_Rect boxpos,SDL_Rect circlepos)
{

float a,b,r,x;

a=circlepos.x+(circlepos.w/2);
b=circlepos.y+(circlepos.h/2);
r=(circlepos.w/2)*(circlepos.w/2);//rayon carre

   if( ( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-boxpos.y)*(b-boxpos.y)) > r) )
      &&( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-(boxpos.y+boxpos.h))*(b-(boxpos.y+boxpos.h))) > r) )
      &&(( ( ( (boxpos.x-a)*(boxpos.x-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r)
      &&(( ((boxpos.x-a)*(boxpos.x-a))+((boxpos.y-b)*(boxpos.y-b)))>r)
      &&( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-boxpos.x)*(a-boxpos.x)) > r) )
      &&(( ( ( ((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r)
     &&(( (((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+((boxpos.y-b)*(boxpos.y-b)))>r) 
       && ( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-(boxpos.x+boxpos.w))*(a-(boxpos.x+boxpos.w))) > r) )
      )
return 1;
else return 0;
}
