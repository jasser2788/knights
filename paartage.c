#include "paartage.h"





void initialiser_background1 (bg *b,int x)
{
b->bgi=NULL;
b->pos.x=x;
b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=800;
b->bgi=IMG_Load("1211.jpg");
}
void initialiser_background2 (bg *b,int x)
{
b->bgi=NULL;
b->pos.x=x;
b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=800;
b->bgi=IMG_Load("121.jpg");
}
/******************************************************************************************************/
/******************************************************************************************************/
void afficher_bg (SDL_Surface *screen,bg *b)
{
SDL_BlitSurface(b->bgi,NULL,screen,&b->pos);
}
/*****************************************************************************************************/
/*****************************************************************************************************/



void init_perso(perso *p)
{
    int i;
    char chaine[20];
    for (i=1; i<8; i++)
    {
        sprintf(chaine,"%d.png",i);
        p->tab[i-1]=IMG_Load(chaine);
    }
    p->frame=1;
    p->posperso.x=0;
    p->posperso.y=300;
    p->perframe=p->tab[0];
    p->vie=100;
    p->score=0;
}
void init_perso2(perso *p,int x)
{
    int i;
    char chaine[20];
    for (i=1; i<8; i++)
    {
        sprintf(chaine,"droite%d.png",i);
        p->tab[i-1]=IMG_Load(chaine);
    }
    p->frame=1;
    p->posperso.x=x;
    p->posperso.y=300;
    p->perframe=p->tab[0];
    p->vie=100;
    p->score=0;
}

void animer_perso_right(perso *p)
{
    p->perframe=p->tab[p->frame];
    p->frame++;
    if(p->posperso.x<330)
    p->posperso.x+=1;
    if (p->frame==7)
        p->frame=0;
}

void animer_perso_left(perso *p)
{


      p->perframe=p->tab[p->frame];
    p->frame++;
    if(p->posperso.x<330)
    p->posperso.x-=1;
    if (p->frame==7)
        p->frame=0;




}



void animer_perso2_right(perso *p)
{
    p->perframe=p->tab[p->frame];
    p->frame++;
    if(p->posperso.x<680)
    p->posperso.x+=1;
    if (p->frame==7)
        p->frame=0;
}


void animer_perso2_left(perso *p)
{
    p->perframe=p->tab[p->frame];
    p->frame++;
    if(p->posperso.x<680)
    p->posperso.x-=1;
    if (p->frame==7)
        p->frame=0;
}


void afficher_perso(perso p,SDL_Surface *screen)
{
    SDL_BlitSurface(p.perframe,NULL,screen,&p.posperso);
}



