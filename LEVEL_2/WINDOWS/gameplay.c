#include "gameplay.h"

//fight----------------------------------------------------------------------------------[1]
int fight(int* frank,int* player){

 //generate_seed
 srand(time(NULL));

 //intervals
 int _min=1;
 int _max=3;
 int flush;
 *frank=_min+(rand()%_max);//assign_value
 char say[]="[You]    : (choose 1[rock],2[paper],3[scissor])\n";
 char error[]="WRONG INPUT DUMMIES!!\n";
 fprintf(stdout,"%s",say);
 while(1){
  if(fscanf(stdin,"%d",player)==1)break;
  while(( flush=getc(stdin))!='\n');
  fprintf(stdout,"%s",error);
  fprintf(stdout,"%s",say);
}

 //player_get_points
 if( *player==1 && *frank==3 || *player==2 && *frank==1 || *player==3 && *frank==2 ){
  *player=1;
  *frank=0;
  return 0;}

 //frank_get_points
 if( *frank==1 && *player==3 || *frank==2 && *player==1 || *frank==3 && *player==2 ){
  *player=0;
  *frank=1;
  return 0;}

 //draw
 else {*player=0; *frank=0; return 0;}
}
/////////////////////////////////////////////////////////////////////////////////////////////





//hit_point_Calculation-------------------------------------------------------------------[2]
int hitpoint(int* frank_hp,int* player_hp,int hit,int* strike_frnk,int* strike_plyr,int* effect,int* score){

 //stopping_condition
 if(*player_hp<0||*frank_hp<=0)return -1;

 //get_points&strikes
 switch(hit){
  case 1://frank's_point
   (*player_hp)--;
   (*strike_frnk)++;
   *effect=2;
   break;

  case 0://draws
   *effect=3;
   (*score)+=2;
   break;

  case -1://player_point
   (*frank_hp)--;
   (*strike_plyr)++;
   *effect=(-2);
   *score+=50;
   break;

}
 //check_strikes
 if(((*strike_plyr)-(*strike_frnk))<=1 && *strike_plyr>=1 && *strike_frnk>=1 ){
  *strike_frnk=0;
  *strike_plyr=0;
  return 0;}
 
 //frank's_bonus_points
 if(*strike_frnk==3){
  (*player_hp)=(*player_hp)-20;
  *strike_frnk=0;
  *strike_plyr=0;
  *effect=1;
  return 0;}

 //player_bonus_points
 if(*strike_plyr==3){
  (*frank_hp)=(*frank_hp)-20;
  *strike_frnk=0;
  *strike_plyr=0;
  *score=(*score)+500;
  *effect=0;
  return 0;}

 return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////


//game_effect-------------------------------------------------------------------------------[3]
void game_effect(int effect){

//frank's_hit
 char line1[]="\n\e[0;91m<<<!!!SLASH!!!>>>\n----You Got Hit----\n\n\e[0;97m";
 char line2[]="\n\e[0;91m<<<BOOM! BOOM! BOOM!>>>\n\e[0;33m----OUCH, IT'S CRITICAL HIT!----\e[0;97m\n\n";
 if(effect==1)fprintf(stdout,"%s",line2);
 if(effect==2)fprintf(stdout,"%s",line1);

//Player_hit
 char line3[]="\n<<<!!!SLASHED AND BASHED!!!>>>\n----YOU HIT FRANK!----\n\n";
 char line4[]="\n<<<WOOOOSH! BOOOOOOM! CRACK!>>>\n----OUCH, IT'S CRITICAL A HIT!----\n\n";
 if(effect==0)fprintf(stdout,"%s",line4);
 if(effect==-2)fprintf(stdout,"%s",line3);

//draw
 char line5[]="\n<<<CLING! CLANG! CREEEK!>>>\n----!!!PARRIED!!!----\n\n";
 if(effect==3)fprintf(stdout,"%s",line5);

}


//score_board_View
void scoreboard(int *score, FILE* file){
 //compare_var
 int comp;

 //readfile
 file=fopen("score","rb");

 //if_notEXIST
 if(file==NULL){
  file=fopen("score","wb");
  //write_to_bin
  fwrite(score,sizeof(int),1,file);
  //close_file
  fclose(file);
  fprintf(stdout,"[YOUR_SCORE]: %d\n[HIGHEST_SCORE]: %d\n",*score,*score);

}

 //if_exist
 else{
  //get_integer
  fread(&comp,sizeof(int),1,file);
  if(*score<comp)fprintf(stdout,"[YOUR_SCORE]: %d\n[HIGHEST_SCORE]: %d\n",*score,comp);
  else if(*score>comp){
   file=fopen("score","wb");
   //write_value
   fwrite(score,sizeof(int),1,file);
   fclose(file);
   fprintf(stdout,"[YOUR_SCORE]: %d\n[HIGHEST_SCORE]: %d\n",*score,*score);
}
}

}
