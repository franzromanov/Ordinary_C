//WELCOME_codename::FRANKLIN
#include "frank_talk.h"
#include "gameplay.h"
//declare
int frank,player,player_hp,frank_hp,strike_frnk,strike_plyr,effect;
int score;
FILE* file;

//main
int main(){
//initialize
 frank_hp=50;
 player_hp=50;
 strike_frnk=0;
 strike_plyr=0;


//WELCOME_BANNER
 banner();
 Sleep(1000);

//Frank's_Greet
if(frank_greet()==0)exit(0);


//------------------PLAY-------------------
while(1){
 if(player_hp<=0||frank_hp<=0)break;
//fight
 fight(&frank,&player);
 system("cls");
 fflush(stdout);
//reaction
 if( hitpoint(&frank_hp,&player_hp,hit(frank,player),&strike_frnk,&strike_plyr,&effect,&score)==-1 )break;
 game_effect(effect);
 frank_react(frank,player);
 fprintf(stdout,"[YOU]%d::%d::[FRANK]%d::%d\n\n",player_hp,strike_plyr,frank_hp,strike_frnk);
 fflush(stdout);
 Sleep(1000);//1_second

}
 if(player_hp<=0)fprintf(stdout,"----GAME OVER----\n <<<YOU LOSE>>>\n");
 if(frank_hp<=0)fprintf(stdout," ----GAME OVER----\n<<<!!!YOU WIN!!!>>>\n");
 //printf("%d\n",score);
 scoreboard(&score,file);
//esc
 return 0;
}
