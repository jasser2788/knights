  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #include <SDL.h>
 /* On inclut les libs supplémentaires */
  #include <SDL_image.h>

 /* Taille de la fenêtre / résolution en plein écran */
  #define SCREEN_WIDTH 
  #define SCREEN_HEIGHT 

 #define PLAYER_WIDTH 1366
 #define PLAYER_HEIGTH 419

 #define MAX_MAP_X 400
 #define MAX_MAP_Y 300

#define PLAYER_SPEED 4


 
 

#define WALK 1
#define IDLE 2
#define JUMP 3
#define RIGHT 1
#define LEFT 2
#define TIME_BETWEEN_2_FRAMES 8







 typedef struct Hero
   {
       //Sprite du héros (pas d'animation pour l'instant)
       SDL_Surface *sprite;

       /* Coordonnées du héros */
       int x, y;

   int etat, direction;
   /* Variables utiles pour l'animation */
    int frameNumber, frameTimer;

   } Hero;

 typedef struct Input
  {

    int left, right, up, down, jump, attack, enter, erase, pause;

  } Input;


  typedef struct Map
  {

      SDL_Surface *background, *tileSet;
     
    /* Coordonnées de début, lorsqu'on doit dessiner la map */
    int startX, startY;

    /* Coordonnées max de fin de la map */
    int maxX, maxY;

    /* Tableau à double dimension représentant la map de tiles */
    int tile[MAX_MAP_Y][MAX_MAP_X];

  } Map;
   
Hero player;


 


void initializePlayer(void)
   {    
       /* Charge le sprite de notre héros */
       player.sprite = loadImage("");

 //Indique l'état et la direction de notre héros
    player.direction = RIGHT;
    player.etat = WALK;
   
    //Réinitialise le timer de l'animation et la frame
    player.frameNumber = 0;
    player.frameTimer = TIME_BETWEEN_2_FRAMES;

      /* Coordonnées de démarrage de notre héros */
       player.x = 20;
       player.y = 304;

   }



void drawplayer()
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = player.x - map.startX;
    dest.y = player.y - map.startY;
    dest.w = PLAYER_WIDTH;
    dest.h = PLAYER_HEIGTH;

    /* Rectangle source à blitter */
    SDL_Rect src;
//Pour connaître le X de la bonne frame à blitter, il suffit de multiplier
    //la largeur du sprite par le numéro de la frame à afficher 
    src.x = player.frameNumber * PLAYER_WIDTH;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;

    /* Blitte notre héros sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}

void getInput()
 {
    SDL_Event event;

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;

                    case SDLK_DELETE:
                        input.erase = 1;
                    break;

                    case SDLK_c:
                        input.jump = 1;
                    break;

                      case SDLK_v:
                        input.attack = 1;
                    break;

                    case SDLK_LEFT:
                        input.left = 1;
                    break;

                    case SDLK_RIGHT:
                        input.right = 1;
                    break;

                    case SDLK_DOWN:
                        input.down = 1;
                    break;

                    case SDLK_UP:
                        input.up = 1;
                    break;

                    case SDLK_RETURN:
                        input.enter = 1;
                    break;

                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_DELETE:
                        input.erase = 0;
                    break;

                    case SDLK_c:
                        input.jump = 0;
                    break;

                    case SDLK_LEFT:
                        input.left = 0;
                    break;

                    case SDLK_RIGHT:
                        input.right = 0;
                    break;

                    case SDLK_DOWN:
                        input.down = 0;
                    break;

                    case SDLK_UP:
                        input.up = 0;
                    break;

                    case SDLK_RETURN:
                        input.enter = 0;
                    break;

                    default:
                    break;
                }
            break;

        }

    }
 }




 void updatePlayer(void)
{

     if (input.left == 1)
    {
        player.x -= PLAYER_SPEED;
       
        if (player.x < 0)
        {
            player.x = 0;
        }
//On teste le sens pour l'animation : si le joueur allait dans le sens contraire
        //précédemment, il faut recharger le spritesheet pour l'animation.
        if(player.direction == RIGHT)
        {
            player.direction = LEFT;
            player.sprite = loadImage("");
        }
    }



    else if (input.right == 1)
    {
        player.x += PLAYER_SPEED;
       
        if (player.x + PLAYER_WIDTH >= map.maxX)
        {
            player.x = map.maxX - PLAYERdr_WIDTH;;
        }
  if(player.direction == LEFT)
        {
            player.direction =  RIGHT;
            player.sprite = loadImage("");
        }

    }

  
   
}


void drawanimatedplayer()
{

    /* Gestion du timer */

    // Si notre timer (un compte à rebours en fait) arrive à zéro

    if (player.frameTimer <= 0)
    {
        //On le réinitialise

        player.frameTimer = TIME_BETWEEN_2_FRAMES;

        //Et on incrémente notre variable qui compte les frames de 1 pour passer à la suivante

        player.frameNumber++;

        //Mais si on dépasse la frame max, il faut revenir à la première
       
        //Puisque la première frame est la numéro 0, la dernière est donc la numéro 3

        if(player.frameNumber >= 3)
            player.frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
        player.frameTimer--;


    //Ensuite, on peut passer la main à notre fonction
    drawplayer();







