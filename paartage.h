#ifndef PAARTAGE_H_INCLUDED
#define PAARTAGE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct perso
{
SDL_Surface *tab[19],*perframe;
SDL_Rect posperso;
int frame,vie,score;
}perso;

typedef struct  bg
{

	    SDL_Surface *bgi;
	    SDL_Rect camera;
	    SDL_Rect pos;
}bg;

void initialiser_background1 (bg *b,int x);
void initialiser_background2 (bg *b,int x);
void afficher_bg (SDL_Surface *screen,bg *b);
//void afficher_score (SDL_Surface *screen,bg *b);


void init_perso(perso *p);
void init_perso2(perso *p,int x);
void animer_perso(perso *p);
void animer_perso2(perso *p);
void animer_persoleft(perso *p);
void afficher_perso(perso p,SDL_Surface *screen);
//void partage();

#endif // PAARTAGE_H_INCLUDED
