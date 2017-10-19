#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>

void main()
{
	int player,com;
	int sel,dummy;
	int score,min=99;

	srand(time(NULL));

	while(1){
		system("cls");
		printf(" === UP & Down Game ===\n");
		printf("    1. 게임시작\n");
		printf("    2. 게임전적\n");
		printf("    3. 게임종료\n");
		printf("    > ");
		scanf("%d",&sel);

		switch(sel){
		case 1:
			com = rand()%99+1;
			score = 0;
			dummy = 3;

			while(1)
			{
				system("cls");
				//출력부분
				if(dummy==3){
					printf(" ===  START  === \n");
				}else if(dummy==1){
					printf(" ===  U  P  === \n");
					score++;

				}else if(dummy==2){
					printf(" ===  Down  === \n");
					score++;

				}else{
					score++;
					printf("%d회만에 맞췄습니다 \n",score);
					if(min>score)
					{
						min = score;
						printf("최고기록을 갱신하셨습니다. \n");
					}

					break;
				}

				//입력부분
				printf("Input Number --> ");
				scanf("%d",&player);

				//검사부분
				if(player > com){
					dummy = 2;
				}else if(player < com){
					dummy = 1;
				}else{
					dummy = 4;
				}
			}
			break;
		case 2:
			if(min==99)
			{
				printf("게임을 시작하지 않았습니다\n");
				break;
			}
			printf("최고점수는 %d회 입니다 \n",min);
			break;
		case 3:
			printf("게임을 종료합니다.\n");
			exit(1);
		}
		getch();
	}
}
