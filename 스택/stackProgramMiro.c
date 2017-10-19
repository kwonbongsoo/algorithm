#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#define k = 42;
void gotoxy(int x, int y){
 COORD pos = {x,y};
 SetConsoleCursorPosition
  (GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void setcolor(int color, int bgcolor)
{
 color &= 0xf;
 bgcolor &= 0xf;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
typedef struct{
	int x;
	int y;
}hero;
typedef struct Move{
	int x;
	int y;
	Move * link;
}M;
M * GetNode(){
	M * tmp = (M*)malloc(sizeof(M));
	tmp->link=NULL;
	return tmp;
}
void Push(M ** top,int x,int y){
	M * tmp = *top;
	*top = GetNode();
	(*top)->x = x;
	(*top)->y = y;
	(*top)->link = tmp;
        gotoxy(k,80);
        k--;
        printf("x:%d,y:%d",x,y);

}
hero Pop(M ** top){
	if(*top){
		hero copy;
		M * tmp = *top;
		*top = (*top)->link;
		copy.x = tmp->x;
		copy.y = tmp->y;
		free(tmp);
                k++;
                gotoxy(k,80);
                printf("                                             ");
		return copy;
	}

}
void allPop(M ** top){
	if(*top){
		allPop(&(*top)->link);
		free(*top);
	}
}
int main(){
		hero com={2,0};
		hero remove={0};
		M * top = NULL;
		int map[10][10]={
			{1,0,1,1,1,1,1,3,1,1},
			{1,0,1,0,0,0,0,0,0,1},
			{1,0,1,1,0,1,1,1,1,1},
			{1,0,1,1,0,1,0,0,0,1},
			{1,0,1,1,0,1,0,1,0,1},
			{1,0,1,1,0,0,0,1,0,1},
			{1,0,1,1,1,1,0,1,0,1},
			{1,0,1,0,0,0,1,1,0,1},
			{1,0,0,0,1,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1}
		};
		int i,j;
		setcolor(10,0);
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				if(map[i][j]==1){
					printf("■");
				}else if(map[i][j]==0||map[i][j]==3){
					printf("  "); //스페이스 두번 x 즉 가로가 y 의길이의 반이기때문에...
				}
			}
			printf("\n");
		}
		setcolor(14,0);
		gotoxy(com.x,com.y);
		printf("●");
		while(1){
			Sleep(300);
			if(map[com.y+1][com.x/2]==0||map[com.y+1][com.x/2]==3){//아래공간이 벽이 x때 움직이는코드
				gotoxy(com.x,com.y);
				printf(" ");
				map[com.y][com.x/2] = 2;
				com.y++;
				gotoxy(com.x,com.y);
				printf("●");
				Push(&top,com.x,com.y);
			}else if(map[com.y-1][com.x/2]==0||map[com.y-1][com.x/2]==3){
				gotoxy(com.x,com.y);
				printf(" ");
				map[com.y][com.x/2] = 2;
				com.y--;
				gotoxy(com.x,com.y);
				printf("●");
				Push(&top,com.x,com.y);
			}else if(map[com.y][(com.x+2)/2]==0||map[com.y][(com.x+2)/2]==3){
				gotoxy(com.x,com.y);
				printf(" ");
				map[com.y][com.x/2] = 2;
				com.x+=2;
				gotoxy(com.x,com.y);
				printf("●");
				Push(&top,com.x,com.y);
			}else if(map[com.y][(com.x-2)/2]==0||map[com.y][(com.x-2)/2]==3){
				gotoxy(com.x,com.y);
				printf(" ");
				map[com.y][com.x/2] = 2;
				com.x-=2;
				gotoxy(com.x,com.y);
				printf("●");
				Push(&top,com.x,com.y);
			}else if(map[com.y][com.x/2] == 3){
				printf("축하합니다!탈출성공 했습니다.\n");
				gotoxy(15,14);
				break;
			}
			else{
				gotoxy(com.x,com.y);
				printf(" ");
				remove = Pop(&top);
				map[com.y][com.x/2] =2;
				map[remove.y][remove.x/2]=0;
				gotoxy(remove.x,remove.y);
				printf("●");
			}
		}allPop(top);
		top = NULL;
		return ;
	}
