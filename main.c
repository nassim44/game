#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
//#include <header.h>
int main(int argc,char *argv[])
{  int continuer=1;
   TTF_Init();

int option=0,f=0;
int menuu=0;


	//cree une police
	   TTF_Font *policebig=NULL;
	   TTF_Font *fontTest;
	   fontTest=TTF_OpenFont("pol.ttf",35);//police w taille
	   SDL_Color fontColor={0,0,0};//couleur du texteTTF_Font *fontTest;
	   TTF_Font *fontTest1;
	   fontTest1=TTF_OpenFont("pol.ttf",35);//police w taille
	   SDL_Color fontColor1={0,0,0};//couleur du texte 
	   TTF_Font *fontTest2;
	   fontTest2=TTF_OpenFont("pol.ttf",50);//police w taille
	   SDL_Color fontColor2={150,0,0};//couleur du texte
	   TTF_Font *fontTest3;
	   fontTest3=TTF_OpenFont("pol.ttf",70);
	   SDL_Color fontColor3={150,0,0}; 
	   policebig= TTF_OpenFont("pol.ttf",95); //gran police
	   SDL_Color couleurrouge = {0, 0, 0};
	//initialisation music
	   Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	   Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	   Mix_Music *music;
	   music=Mix_LoadMUS("son.mp3");
	   Mix_PlayMusic(music,-1);
           Mix_Chunk *gta;
           gta=Mix_LoadWAV("click.wav");
	//initialisation surface fenetre
	   SDL_Event event  ;	
	   SDL_Surface *fenetre=NULL , *menu=NULL, *texte; 
	   SDL_Surface *image=NULL;

	//initialisation boutons
	   SDL_Rect button1_active_Position;
	   SDL_Rect button2_active_Position;
	   SDL_Rect button3_active_Position;
	   SDL_Rect button4_active_Position;
	   SDL_Rect button5_active_Position;
	   SDL_Rect positionecran, positionclic, positiontxt;  
	   button1_active_Position.x=350;
	   button1_active_Position.y=200; 
	   button2_active_Position.x=350;
	   button2_active_Position.y=280;
	   button3_active_Position.x=350;
	   button3_active_Position.y=360;
	   button4_active_Position.x=350;
	   button4_active_Position.y=130;
	   button5_active_Position.x=400;
	   button5_active_Position.y=180;
		// active boutton 
		SDL_Surface *button1_active;
		button1_active=IMG_Load("batjaw2.png");
                SDL_Surface *button2_active;
		button2_active=IMG_Load("batjaw2.png");
                SDL_Surface *button3_active;
		button3_active=IMG_Load("batjaw2.png");
                SDL_Surface *button4_active;
		button4_active=IMG_Load("batjaw2.png");
                SDL_Surface *button5_active;
		button5_active=IMG_Load("batjaw2.png");
SDL_Surface *plus;
	   plus=IMG_Load("plus.png");
	   SDL_Rect plusPosition ;            //jouer
	   plusPosition.x=490;
	   plusPosition.y=360;
	 SDL_Surface *moins;
	   moins=IMG_Load("moins.png");
	   SDL_Rect moinsPosition ;            //jouer
	   moinsPosition.x=365;
	   moinsPosition.y=360;
	SDL_Surface *mute1;
	   mute1=IMG_Load("mute1.png");
	   SDL_Rect mute1Position ;            //jouer
	   mute1Position.x=0;
	   mute1Position.y=470;
	//buttons1 
	   SDL_Surface *button1;
	   button1=IMG_Load("batjaw1.png");
	   SDL_Rect button1Position ;            //jouer
	   button1Position.x=350;
	   button1Position.y=200;
	  //button mousemotion
           SDL_Surface *button0;
	   button0=IMG_Load("batjaw2.jpg");
	   SDL_Rect button0Position ;            //jouer motion
	   button0Position.x=350;
	   button0Position.y=200;   
	//buttons2 
	   SDL_Surface *button2;
	   button2=IMG_Load("batjaw1.png");
	   SDL_Rect button2Position ;          //option
	   button2Position.x=350;
	   button2Position.y=280;
	    
	//buttons3 
	   SDL_Surface *button3;
	   button3=IMG_Load("batjaw1.png");
	   SDL_Rect button3Position ;
	   button3Position.x=350;             //quitter
	   button3Position.y=360;
	    
	//buttons12
	   SDL_Surface *button12;
	   button12=IMG_Load("batjaw1.png");
	   SDL_Rect button12Position ;
	   button12Position.x=650;               //jouer full screen
	   button12Position.y=300;
	//button22
	   
	   SDL_Surface *button22;
	   button22=IMG_Load("batjaw1.png");
	   SDL_Rect button22Position ;              
	   button22Position.x=650;              //option full screen
	   button22Position.y=380;
	  
	//buttons32 
	   SDL_Surface *button32;
	   button32=IMG_Load("batjaw1.png");
	  SDL_Rect button32Position ;
	button32Position.x=650;                  //quitter full screen
	button32Position.y=460; 
	//option fullscreen

       	SDL_Surface *scroll2;
	scroll2=IMG_Load("option.png");       //scroll full screen
	SDL_Rect scroll2Position ;
	scroll2Position.x=575;
	scroll2Position.y=100;
	
	SDL_Surface *but32;
	but32=IMG_Load("batjaw1.png");
	SDL_Rect but32Position ;
	but32Position.x=650;                  //full screen full screen
	but32Position.y=230;
	
	SDL_Surface *but42;
	but42=IMG_Load("batjaw1.png");
	SDL_Rect but42Position ;                 //normal full screen
	but42Position.x=700;
	but42Position.y=280;
	
	SDL_Surface *but82;
	but82=IMG_Load("batjaw1.png");          //retour fullscreen
	SDL_Rect but82Position ;
	but82Position.x=5;
	but82Position.y=-50;

           SDL_Surface *tex42;
	   tex42=TTF_RenderText_Blended(fontTest,"fullscreen",fontColor);
	   SDL_Rect text42Position;//position eli fi westha x w y 
	   text42Position.x=670;
	   text42Position.y=280;

	   SDL_Surface *tex52;
	   tex52=TTF_RenderText_Blended(fontTest,"normal",fontColor);
	   SDL_Rect tex52Position;//position eli fi westha x w y 
	   tex52Position.x=730;
	   tex52Position.y=330;

	   SDL_Surface *tex62;
	   tex62=TTF_RenderText_Blended(fontTest2,"Volume",fontColor2);
	   SDL_Rect tex62Position;//position eli fi westha x w y 
	   tex62Position.x=690;
	   tex62Position.y=400;

	   SDL_Surface *tex72;
	   tex72=TTF_RenderText_Blended(fontTest2,"Screen",fontColor2);
	   SDL_Rect tex72Position;//position eli fi westha x w y 
	   tex72Position.x=690;
	   tex72Position.y=200;

           SDL_Surface *tex82;
	   tex82=TTF_RenderText_Blended(fontTest,"retour",fontColor);
	   SDL_Rect text82Position;//position eli fi westha x w y 
	   text82Position.x=40;
	   text82Position.y=0;

	//scroll
	   SDL_Rect tex4Position;
	   SDL_Surface *scroll;
	   scroll=IMG_Load("option.png");
	   SDL_Rect scrollPosition ;
	   scrollPosition.x=275;
	   scrollPosition.y=0;
	//button fullscreen
	   SDL_Surface *but3;
	   but3=IMG_Load("batjaw1.png");
	   SDL_Rect but3Position ;
	   but3Position.x=350;
	   but3Position.y=130; 
	//button normal
	   SDL_Surface *but4;
	   but4=IMG_Load("batjaw1.png");
	   SDL_Rect but4Position ;
	   but4Position.x=400;
	   but4Position.y=180; 
	//button return
	   SDL_Surface *but8;
	   but8=IMG_Load("batjaw1.png");
	   SDL_Rect but8Position ;
	   but8Position.x=5;
	   but8Position.y=-50;
        //button return 2
           SDL_Surface *but9;
	   but9=IMG_Load("batjaw1.png");
	   SDL_Rect but9Position ;
	   but9Position.x=5;
	   but9Position.y=-50;
	//initialisation textes
	   SDL_Surface *texte1;
	   texte1=TTF_RenderText_Blended(fontTest,"quitter",fontColor);//eli nheb nektbou
	   SDL_Rect texte1Position;//position eli fi westha x w y 
	   texte1Position.x=390;
	   texte1Position.y=410;

           SDL_Surface *texte2;
	   texte2=TTF_RenderText_Blended(fontTest,"options",fontColor);//eli nheb nektbou
	   SDL_Rect texte2Position;//position eli fi westha x w y 
	   texte2Position.x=390;
	   texte2Position.y=332;
	   
	   SDL_Surface *texte3;
	   texte3=TTF_RenderText_Blended(fontTest,"jouer",fontColor);//eli nheb nektbou
	   //texte1=TTF_CloseFont(fontTest);
	   SDL_Rect texte3Position;//position eli fi westha x w y 
	   texte3Position.x=390;
	   texte3Position.y=250;
	   
	   SDL_Surface *texte4;
	   texte4=TTF_RenderText_Blended(fontTest3,"Ninja",fontColor3);//eli nheb nektbou
	   //texte1=TTF_CloseFont(fontTest);
	   SDL_Rect texte4Position;//position eli fi westha x w y 
	   texte4Position.x=370;
	   texte4Position.y=55;
	   
	   SDL_Surface *texte5;
	   texte5=TTF_RenderText_Blended(fontTest3,"Hurricane",fontColor3);//eli nheb nektbou
	   //texte1=TTF_CloseFont(fontTest);
	   SDL_Rect texte5Position;//position eli fi westha x w y 
	   texte5Position.x=330;
	   texte5Position.y=130;

	SDL_Surface *texte12;
	texte12=TTF_RenderText_Blended(fontTest,"quitter",fontColor);//eli nheb nektbou
	//texte1=TTF_CloseFont(fontTest);
	SDL_Rect texte12Position;//position eli fi westha x w y 
	texte12Position.x=690;
	texte12Position.y=510;

	SDL_Surface *texte22;
	texte22=TTF_RenderText_Blended(fontTest,"options",fontColor);//eli nheb nektbou
	//texte1=TTF_CloseFont(fontTest);
	SDL_Rect texte22Position;//position eli fi westha x w y 
	texte22Position.x=690;
	texte22Position.y=432;

	SDL_Surface *texte32;
	texte32=TTF_RenderText_Blended(fontTest,"jouer",fontColor);//eli nheb nektbou
	//texte1=TTF_CloseFont(fontTest);
	SDL_Rect texte32Position;//position eli fi westha x w y 
	texte32Position.x=690;
	texte32Position.y=350;

	SDL_Surface *texte42;
	texte42=TTF_RenderText_Blended(fontTest3,"Ninja",fontColor3);//eli nheb nektbou
	//texte1=TTF_CloseFont(fontTest);
	SDL_Rect texte42Position;//position eli fi westha x w y 
	texte42Position.x=670;
	texte42Position.y=155;

	SDL_Surface *texte52;
	texte52=TTF_RenderText_Blended(fontTest3,"Hurricane",fontColor3);//eli nheb nektbou
	//texte1=TTF_CloseFont(fontTest);
	SDL_Rect texte52Position;//position eli fi westha x w y 
	texte52Position.x=630;
	texte52Position.y=230;

	   SDL_Surface *tex4;
	   tex4=TTF_RenderText_Blended(fontTest,"fullscreen",fontColor);
	   SDL_Rect text4Position;//position eli fi westha x w y 
	   text4Position.x=370;
	   text4Position.y=180;

	   SDL_Surface *tex5;
	   tex5=TTF_RenderText_Blended(fontTest,"normal",fontColor);
	   SDL_Rect tex5Position;//position eli fi westha x w y 
	   tex5Position.x=430;
	   tex5Position.y=230;

	   SDL_Surface *tex6;
	   tex6=TTF_RenderText_Blended(fontTest2,"Volume",fontColor2);
	   SDL_Rect tex6Position;//position eli fi westha x w y 
	   tex6Position.x=390;
	   tex6Position.y=300;

	   SDL_Surface *tex7;
	   tex7=TTF_RenderText_Blended(fontTest2,"Screen",fontColor2);
	   SDL_Rect tex7Position;//position eli fi westha x w y 
	   tex7Position.x=390;
	   tex7Position.y=100;

           SDL_Surface *tex8;
	   tex8=TTF_RenderText_Blended(fontTest,"retour",fontColor);
	   SDL_Rect text8Position;//position eli fi westha x w y 
	   text8Position.x=40;
	   text8Position.y=0;

//intialisation fenetre
	if(SDL_Init(SDL_INIT_VIDEO)!= 0)
   {
       printf("unable to initialize sdl:%s \n",SDL_GetError());
        return 1;
   }
   fenetre=SDL_SetVideoMode(858,552,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
   if(fenetre==NULL)
   {
       printf("unable de set video mode:%s \n",SDL_GetError());
        return 1;
   }
   image=IMG_Load("backround.jpg");  
   if(image==NULL)
   {
       printf("unable to load image:%s \n",SDL_GetError());
        return 1;
   }

	    positionecran.x=0;
            positionecran.y=0;
            SDL_BlitSurface(image,NULL,fenetre,&positionecran);
            SDL_BlitSurface(button1,NULL,fenetre,&button1Position);
            SDL_BlitSurface(button2,NULL,fenetre,&button2Position);
            SDL_BlitSurface(button3,NULL,fenetre,&button3Position);
            SDL_BlitSurface(texte1,NULL,fenetre,&texte1Position);
            SDL_BlitSurface(texte2,NULL,fenetre,&texte2Position);
            SDL_BlitSurface(texte3,NULL,fenetre,&texte3Position);
            SDL_BlitSurface(texte4,NULL,fenetre,&texte4Position);
            SDL_BlitSurface(texte5,NULL,fenetre,&texte5Position);
            SDL_Flip(fenetre); 
            option=0;
	    menuu=1;

int x,y;
            
while(continuer) 
{  
	SDL_PollEvent(&event);	
	   
	switch (event.type)
  	{

	case SDL_QUIT : 
       continuer=0 ; 
        break ;
case SDL_MOUSEBUTTONUP : 
        if (event.button.button==SDL_BUTTON_LEFT) 
         {
		
            if((event.button.x >315 && event.button.x <465 && event.button.y >250 && event.button.y <300)&&(option==0)&&(menuu==1)) 
              {SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255));
 texte=TTF_RenderText_Blended(policebig," To Be Continued...",couleurrouge ); 
                 positiontxt.x=0; 
                  positiontxt.y=0; 
                  SDL_BlitSurface(texte,NULL,fenetre,&positiontxt); 
                   SDL_Flip(fenetre);
 		  menuu=0;}
else if((event.button.x >0 && event.button.x <100 && event.button.y >440 && event.button.y <500)&&(option==1)&&(menuu==0))
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	   Mix_VolumeMusic(0);
	   Mix_Music *music;
	   music=Mix_LoadMUS("son.mp3");
	   Mix_PlayMusic(music,-1);}
else if((event.button.x >325 && event.button.x <380 && event.button.y >350 && event.button.y <380)&&(option==1)&&(menuu==0))
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	   Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
	   Mix_Music *music;
	   music=Mix_LoadMUS("son.mp3");
	   Mix_PlayMusic(music,-1);}

else if((event.button.x >510 && event.button.x <530 && event.button.y >350 && event.button.y <380)&&(option==1)&&(menuu==0))
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	   Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
	   Mix_Music *music;
	   music=Mix_LoadMUS("son.mp3");
	   Mix_PlayMusic(music,-1);}
 else if ((event.button.x >315 && event.button.x <465 && event.button.y >300 && event.button.y <408)&&(option==0)&&(menuu==1))
{SDL_BlitSurface(image,NULL,fenetre,&positionecran);
              SDL_BlitSurface(scroll,NULL,fenetre,&scrollPosition);
              SDL_BlitSurface(but3,NULL,fenetre,&but3Position);
	      SDL_BlitSurface(but4,NULL,fenetre,&but4Position);
              SDL_BlitSurface(but8,NULL,fenetre,&but8Position);
		SDL_BlitSurface(moins,NULL,fenetre,&moinsPosition);
		SDL_BlitSurface(plus,NULL,fenetre,&plusPosition);
	      SDL_BlitSurface(mute1,NULL,fenetre,&mute1Position);
              SDL_BlitSurface(tex8,NULL,fenetre,&text8Position);
              SDL_BlitSurface(tex4,NULL,fenetre,&text4Position);
	      SDL_BlitSurface(tex5,NULL,fenetre,&tex5Position);
              SDL_BlitSurface(tex6,NULL,fenetre,&tex6Position);
              SDL_BlitSurface(tex7,NULL,fenetre,&tex7Position);
              SDL_Flip(fenetre); 
              option=1;
	      menuu=0;}
else if((event.button.x >325 && event.button.x <475 && event.button.y >54 && event.button.y <250)&&(option==1)&&(menuu==0))
{if(SDL_Init(SDL_INIT_VIDEO)!= 0)
   {
       printf("unable to initialize sdl:%s \n",SDL_GetError());
        return 1;}
   fenetre=SDL_SetVideoMode(1440,900,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
   if(fenetre==NULL)
   {
       printf("unable de set video mode:%s \n",SDL_GetError());
        return 1;
   }
   image=IMG_Load("backround2.jpg");  
   if(image==NULL)
   {
       printf("unable to load image:%s \n",SDL_GetError());
        return 1;
   }
       SDL_BlitSurface(image,NULL,fenetre,&positionecran);
            SDL_BlitSurface(button12,NULL,fenetre,&button12Position);
            SDL_BlitSurface(button22,NULL,fenetre,&button22Position);
            SDL_BlitSurface(button32,NULL,fenetre,&button32Position);
            SDL_BlitSurface(texte12,NULL,fenetre,&texte12Position);
            SDL_BlitSurface(texte22,NULL,fenetre,&texte22Position);
            SDL_BlitSurface(texte32,NULL,fenetre,&texte32Position);
            SDL_BlitSurface(texte42,NULL,fenetre,&texte42Position);
            SDL_BlitSurface(texte52,NULL,fenetre,&texte52Position);
            SDL_Flip(fenetre);
	    menuu=1;
            option=0; }
 else if ((event.button.x >=0 && event.button.x <100 && event.button.y >0 && event.button.y <100)&&(option==1)&&(menuu==0))
{SDL_BlitSurface(image,NULL,fenetre,&positionecran);
            SDL_BlitSurface(button1,NULL,fenetre,&button1Position);
            SDL_BlitSurface(button2,NULL,fenetre,&button2Position);
            SDL_BlitSurface(button3,NULL,fenetre,&button3Position);
            SDL_BlitSurface(texte1,NULL,fenetre,&texte1Position);
            SDL_BlitSurface(texte2,NULL,fenetre,&texte2Position);
            SDL_BlitSurface(texte3,NULL,fenetre,&texte3Position);
            SDL_BlitSurface(texte4,NULL,fenetre,&texte4Position);
            SDL_BlitSurface(texte5,NULL,fenetre,&texte5Position);
            SDL_Flip(fenetre); 
            option=0;
	    menuu=1;}}
     break;
case SDL_KEYDOWN : 
if(event.key.keysym.sym == SDLK_k)
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	   Mix_VolumeMusic(0);
	   Mix_Music *music;
	   music=Mix_LoadMUS("son.mp3");
	   Mix_PlayMusic(music,-1);}
	if(event.key.keysym.sym == SDLK_l)
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	   Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
	   Mix_Music *music;
	   music=Mix_LoadMUS("son.mp3");
	   Mix_PlayMusic(music,-1);}
if(event.key.keysym.sym == SDLK_m)
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	   Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
	   Mix_Music *music;
	   music=Mix_LoadMUS("son.mp3");
	   Mix_PlayMusic(music,-1);}
           if((event.key.keysym.sym == SDLK_j)&&(option==0)&&(menuu==1))
{SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255));
 texte=TTF_RenderText_Blended(policebig," To Be Continued...",couleurrouge ); 
                 positiontxt.x=0; 
                  positiontxt.y=0; 
                  SDL_BlitSurface(texte,NULL,fenetre,&positiontxt); 
                   SDL_Flip(fenetre);
                  menuu=0; }
 else if((event.key.keysym.sym == SDLK_o)&&(option==0)&&(menuu==1))
	{
              SDL_BlitSurface(image,NULL,fenetre,&positionecran);
              SDL_BlitSurface(scroll,NULL,fenetre,&scrollPosition);
              SDL_BlitSurface(but3,NULL,fenetre,&but3Position);
	      SDL_BlitSurface(but4,NULL,fenetre,&but4Position);
              SDL_BlitSurface(but9,NULL,fenetre,&but9Position);
              SDL_BlitSurface(tex8,NULL,fenetre,&text8Position);
              SDL_BlitSurface(tex4,NULL,fenetre,&text4Position);
	      SDL_BlitSurface(tex5,NULL,fenetre,&tex5Position);
              SDL_BlitSurface(tex6,NULL,fenetre,&tex6Position);
              SDL_BlitSurface(tex7,NULL,fenetre,&tex7Position);
              SDL_Flip(fenetre); 
              option=1;
              menuu=0;}
else if(event.key.keysym.sym == SDLK_r)
        {if(SDL_Init(SDL_INIT_VIDEO)!= 0)
   {
       printf("unable to initialize sdl:%s \n",SDL_GetError());
        return 1;}
   fenetre=SDL_SetVideoMode(858,552,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
   if(fenetre==NULL)
   {
       printf("unable de set video mode:%s \n",SDL_GetError());
        return 1;
   }
   image=IMG_Load("backround.jpg");  
   if(image==NULL)
   {
       printf("unable to load image:%s \n",SDL_GetError());
        return 1;
   }
SDL_BlitSurface(image,NULL,fenetre,&positionecran);
            SDL_BlitSurface(button1,NULL,fenetre,&button1Position);
            SDL_BlitSurface(button2,NULL,fenetre,&button2Position);
            SDL_BlitSurface(button3,NULL,fenetre,&button3Position);
            SDL_BlitSurface(texte1,NULL,fenetre,&texte1Position);
            SDL_BlitSurface(texte2,NULL,fenetre,&texte2Position);
            SDL_BlitSurface(texte3,NULL,fenetre,&texte3Position);
            SDL_BlitSurface(texte4,NULL,fenetre,&texte4Position);
            SDL_BlitSurface(texte5,NULL,fenetre,&texte5Position);
            SDL_Flip(fenetre); 
            option=0;
            menuu=1;
}
 else if(event.key.keysym.sym == SDLK_f)
        {if(SDL_Init(SDL_INIT_VIDEO)!= 0)
   {
       printf("unable to initialize sdl:%s \n",SDL_GetError());
        return 1;}
   fenetre=SDL_SetVideoMode(1440,900,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
   if(fenetre== NULL)
   {
       printf("unable de set video mode:%s \n",SDL_GetError());
        return 1;
   }

   image=IMG_Load("backround2.jpg");  
  if((option==0)&&(menuu==1)){
       SDL_BlitSurface(image,NULL,fenetre,&positionecran);
            SDL_BlitSurface(button12,NULL,fenetre,&button12Position);
            SDL_BlitSurface(button22,NULL,fenetre,&button22Position);
            SDL_BlitSurface(button32,NULL,fenetre,&button32Position);
            SDL_BlitSurface(texte12,NULL,fenetre,&texte12Position);
            SDL_BlitSurface(texte22,NULL,fenetre,&texte22Position);
            SDL_BlitSurface(texte32,NULL,fenetre,&texte32Position);
            SDL_BlitSurface(texte42,NULL,fenetre,&texte42Position);
            SDL_BlitSurface(texte52,NULL,fenetre,&texte52Position);
            SDL_Flip(fenetre);      
}
else if((option==1)&&(menuu==0)){       
              SDL_BlitSurface(image,NULL,fenetre,&positionecran);
              SDL_BlitSurface(scroll2,NULL,fenetre,&scroll2Position);
              SDL_BlitSurface(but32,NULL,fenetre,&but32Position);
	      SDL_BlitSurface(but42,NULL,fenetre,&but42Position);
              SDL_BlitSurface(but82,NULL,fenetre,&but82Position);
              SDL_BlitSurface(tex82,NULL,fenetre,&text82Position);
              SDL_BlitSurface(tex42,NULL,fenetre,&text42Position);
	      SDL_BlitSurface(tex52,NULL,fenetre,&tex52Position);
              SDL_BlitSurface(tex62,NULL,fenetre,&tex62Position);
              SDL_BlitSurface(tex72,NULL,fenetre,&tex72Position);
              SDL_Flip(fenetre); 

 if (event.button.button==SDL_BUTTON_LEFT) 
         {
}

}
break;
case SDL_MOUSEMOTION : 

SDL_GetMouseState(&x,&y);
if (menuu==1){

if((x>315)&&(x<465)&&(y>300)&&(y<408)&&(option==0)&&(menuu==1))
{
Mix_PlayChannel(-1,gta,0);
SDL_BlitSurface(button2_active,NULL,fenetre,&button2_active_Position);
SDL_BlitSurface(texte2,NULL,fenetre,&texte2Position);
SDL_Flip(fenetre); 

}
else if (x >315 && x <465 && y >250 && y <300&&(option==0)&&(menuu==1)) 
{
SDL_BlitSurface(button1_active,NULL,fenetre,&button1_active_Position);
SDL_BlitSurface(texte3,NULL,fenetre,&texte3Position);
Mix_PlayChannel(-1,gta,0);
SDL_Flip(fenetre); 
}


else if (x >315 && x <465 && y >430 && y <580&&(option==0)&&(menuu==1))
{
SDL_BlitSurface(button3_active,NULL,fenetre,&button3_active_Position);
SDL_BlitSurface(texte1,NULL,fenetre,&texte1Position);
Mix_PlayChannel(-1,gta,0);
SDL_Flip(fenetre); 
}
else 
{

SDL_BlitSurface(image,NULL,fenetre,&positionecran);
            SDL_BlitSurface(button1,NULL,fenetre,&button1Position);
            SDL_BlitSurface(button2,NULL,fenetre,&button2Position);
            SDL_BlitSurface(button3,NULL,fenetre,&button3Position);
            SDL_BlitSurface(texte1,NULL,fenetre,&texte1Position);
            SDL_BlitSurface(texte2,NULL,fenetre,&texte2Position);
            SDL_BlitSurface(texte3,NULL,fenetre,&texte3Position);
            SDL_BlitSurface(texte4,NULL,fenetre,&texte4Position);
            SDL_BlitSurface(texte5,NULL,fenetre,&texte5Position);
            SDL_Flip(fenetre); 
}}
if ((option==1)&&(menuu==0))
{
if((event.button.x >325 && event.button.x <475 && event.button.y >54 && event.button.y <250)&&(option==1)&&(menuu==0))
{SDL_BlitSurface(button4_active,NULL,fenetre,&button4_active_Position);
SDL_BlitSurface(tex4,NULL,fenetre,&text4Position);
Mix_PlayChannel(-1,gta,0);
SDL_Flip(fenetre); 
}
else 
{SDL_BlitSurface(but3,NULL,fenetre,&but3Position);
SDL_BlitSurface(tex4,NULL,fenetre,&text4Position);
SDL_Flip(fenetre);
}}
//else SDL_FreeSurface(button1_active);

break;


}//close switch
}}//close while
/*while(1)
{ SDL_Event event; 
SDL_WaitEvent(&event);
if (event.type==SDL_QUIT) 
{break;}}*/


SDL_FreeSurface(fenetre);
SDL_FreeSurface(button1_active);
SDL_FreeSurface(button2_active);
SDL_FreeSurface(button3_active);
SDL_FreeSurface(button4_active);
SDL_FreeSurface(button5_active);
SDL_FreeSurface(image);
SDL_FreeSurface(menu);
SDL_FreeSurface(texte);
SDL_FreeSurface(button1);
SDL_FreeSurface(button2);
SDL_FreeSurface(button3);
SDL_FreeSurface(button12);
SDL_FreeSurface(button22);
SDL_FreeSurface(button32);
SDL_FreeSurface(scroll);
SDL_FreeSurface(but3);
SDL_FreeSurface(but4);
SDL_FreeSurface(but8);
SDL_FreeSurface(texte1);
SDL_FreeSurface(texte2);
SDL_FreeSurface(texte3);
SDL_FreeSurface(texte4);
SDL_FreeSurface(texte5);
SDL_FreeSurface(texte12);
SDL_FreeSurface(texte22);
SDL_FreeSurface(texte32);
SDL_FreeSurface(texte42);
SDL_FreeSurface(texte52);
SDL_FreeSurface(tex4);
SDL_FreeSurface(tex5);
SDL_FreeSurface(tex6);
SDL_FreeSurface(tex7);
SDL_FreeSurface(tex8);
Mix_FreeMusic(music);
Mix_FreeChunk(gta);
Mix_CloseAudio();
Mix_Quit();
TTF_Quit();
SDL_Quit();
return 0;
}
   







