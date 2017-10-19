#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
#include <windows.h>//sleep(1000)사용헤더파일.인자값 (1000) 초단위 환산 1/1000==1초

void main()
{
	int sel,count;
	int i;
	int win=0, lose=0;

	while(1){
		count=0;
		system("cls");
		printf("Baskin Robbins 31 !\n");
		printf("      1.게임시작 \n");
		printf("      2.게임전적 \n");
		printf("      3.게임종료 \n");
		printf("   >>>> ");
		scanf("%d",&sel);
		switch(sel){
		case 1:
			while(1)
			{
				printf("1 ~ 3 까지 :");
				scanf("%d",&sel);
				if(sel <= 0 || sel >= 4){
					printf("잘못입력하셨습니다\n");
					continue;
				}
				for(i=0;i<sel;i++)
				{
					count++;
					if(count==31){
						printf("멍청이...ㅋㅋㅋ\n");
						lose++;
						break;
					}
					printf(" %d !\n",count);
					Sleep(500);
				}
				if(count==31)
				{
					break;
				}

				printf("Computer \n");

				if((count+4)==31){
					sel = 3;
				}else if((count+3)==31){
					sel = 2;
				}else if((count+2)==31){
					sel = 1;
				}else{
					srand(time(NULL));
					sel = rand()%3+1;
				}

//2, 6, 10, 14, 18, 22, 26, 30 을 선택하면 무조건 이김
/*
				if((count+1)==2 || (count+1)==6 || (count+1)==10 || (count+1)==14 || (count+1)==18 || (count+1)==22 || (count+1)==26 || (count+1)==30 )
					sel = 1;
				else if((count+2)==2 || (count+2)==6 || (count+2)==10 || (count+2)==14 || (count+2)==18 || (count+2)==22 || (count+2)==26 || (count+2)==30 )
					sel = 2;
				else if((count+3)==2 || (count+3)==6 || (count+3)==10 || (count+3)==14 || (count+3)==18 || (count+3)==22 || (count+3)==26 || (count+3)==30 )
					sel = 3;
				else{
					srand(time(NULL));
					sel = rand()%3+1;
				}
*/

				for(i=0;i<sel;i++)
				{
					count++;
					if(count==31){
						printf(" %d.......?!\n",count);
						printf("당신이 이기셨습니다...ㅠ.ㅠ \n");
						win++;
						break;
					}
					printf(" %d !\n",count);
					Sleep(500);
				}
				if(count==31)
				{
					break;
				}
			}
			break;
		case 2:
			printf("<<당신의 전적>>\n");
			printf("  WIN  : %d\n", win);
			printf("  LOSE : %d\n", lose);
			break;
		case 3:
			printf("프로그램을 종료하겠습니다.\n");
			exit(1);
		}
		getch();
		}
}
