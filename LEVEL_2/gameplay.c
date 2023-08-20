#include "gameplay.h"s

//fight----------------------------------------------------------------------------------[1]
void fight(int* frank,int* player){

 //generate_seed
 srand(time(null));

 //intervals
 int _min=1;
 int _max=3;
 *frank=_min+(rnd()%_max);//assign_value
 char say[]="[You]    : (choose 1[rock],2[paper],3[scissor])\n"
 fprintf(stdout,"%s",say);
 while(1)if(fscanf(stdin,"%d",player)==1)break;

 //player_get_points
 if( *player==1 && *frank==3 || *player==2 && *frank==1 || *player==3 && *frank==2 ){
  *player=1;
  *frank=0;}

 //frank_get_points
 if( *frank==1 && *player==3 || *frank==2 && *player==1 || *frank==3 && *player==2 ){
  *player=0;
  *frank=1;}

 //draw
 else {*player=0; *frank=0;}

}
/////////////////////////////////////////////////////////////////////////////////////////////





//hit_point_Calculation-------------------------------------------------------------------[2]
int hitpoint(int* frank_hp,int* player_hp,int hit,int* strike_frnk,int* strike_plyr){

 //stopping_condition
 if(*player_hp<0||*frank_hp<0)return -1;

 //get_points&strikes
 switch(hit){
  case 1://frank's_point
   (*player_hp)--;
   (*strike_frnk)++;
   break;

  case 0://draws
   break;

  case -1:
   (*frank_hp)--;
   (*strike_plyr)++;
   break;

}
 //check_strikes
 if((*strike_plyr)-(*strike_frnk)<=1){
  *strike_frnk=0;
  *strike_plyr=0;
  return 0;}

 //frank's_bonus_points
 if(*strike_frnk==3){
  (*player_hp)=(*player_hp)-10;
  *strike_frnk=0;
  *strike_plyr=0;
  return 5;}

 //player_bonus_points
 if(*strike_plyr==3){
  (*frank_hp)=(*frank_hp)-10;
  *strike_frnk=0;
  *strike_plyr=0;
  return 10;}

 return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////


/*

//game_effect
void game_effect(int react);

//score_board_View
void scoreboard();

*/
