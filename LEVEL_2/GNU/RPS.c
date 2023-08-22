  GNU nano 7.2                                                                                                                                                RPS.c                                                                                                                                                          
//initialize
 frank_hp=50;
 player_hp=50;
 strike_frnk=0;
 strike_plyr=0;


//WELCOME_BANNER
 banner();
 sleep(1);

//Frank's_Greet
if(frank_greet()==0)exit(1);


//------------------PLAY-------------------
while(1){
 if(player_hp<=0||frank_hp<=0)break;
//fight
 fight(&frank,&player);
 fprintf(stdout,"\033[H\033[2J");//ansi_code_to_clear_stdout
 fflush(stdout);
//reaction
 if( hitpoint(&frank_hp,&player_hp,hit(frank,player),&strike_frnk,&strike_plyr,&effect,&score)==-1 )break;
 game_effect(effect);
 frank_react(frank,player);
 fprintf(stdout,"[YOU]%d::%d::[FRANK]%d::%d\n\n",player_hp,strike_plyr,frank_hp,strike_frnk);
 fflush(stdout);
 sleep(1);

}
 if(player_hp<=0)fprintf(stdout,"----GAME OVER----\n\e[0;91m <<<YOU LOSE>>>\n");
 if(frank_hp<=0)fprintf(stdout," ----GAME OVER----\n\e[0;94m<<<!!!YOU WIN!!!>>>\n");
 //printf("%d\n",score);
 scoreboard(&score,file);
//esc
 return 0;
}
