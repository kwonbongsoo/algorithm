#include <iostream>

using namespace std;

class money
{
	int year_money;
	double increase;
public:
	money()
	{
		cout <<"           초기화"<<endl;
		year_money=increase=0;
	}
	~money()
	{
		cout<<"           프로그램 종료"<<endl;
	}
	void input_money()
	{
		cout <<"           연봉 입력(만원):";
		cin >> year_money;
		a:
		if(year_money >= 3000)
		{
			cout <<"           올?대기업"<<endl;
			cout <<"           인상률 3%~5% 입력:";
			cin >> increase;
			if(increase < 3 || increase > 5)
			{
				cout <<"           잘못입력하셨습니다"<<endl;
				goto a;
			}
		}
		if(year_money >= 1800 && year_money < 3000)
		{
			cout <<"           인상률 10%~20% 입력:";
			cin >> increase;
			if(increase < 10 || increase > 20)
			{
				cout <<"           잘못입력하셨습니다"<<endl;
				goto a;
			}
		}
		if(year_money < 1800)
		{
			cout <<"           알바시네요?"<<endl;
		}

	}
	void print_money()
	{
		increase = increase/100;
		for(int i = 0; i <10; i++)
		{
			year_money = year_money+(year_money*increase);
		}
		cout <<"           10년째 될때 연봉은 "<< year_money <<"만원입니다"<<endl;
	}
};

int main()
{
	money a;
	int choice;
	while(1)
	{
		system("cls");
		cout <<"= = = = = = = = = = = = = = = = = = = = = = ="<<endl;
		cout <<"           연봉 계산기 ver 1.0 kbs"<<endl;
		cout <<"= = = = = = = = = = = = = = = = = = = = = = ="<<endl;
		cout <<"           1. 연봉 입력"<<endl;
		cout <<"           2. 연봉 계산 및 출력"<<endl;
		cout <<"           3. 프로그램 종료"<<endl;
		cout <<"= = = = = = = = = = = = = = = = = = = = = = ="<<endl;
		cout <<"          >";
		cin >> choice;
		switch(choice)
		{
		case 1:
			a.input_money();
			break;
		case 2:
			a.print_money();
			break;
		case 3:
			return 0;

		}
		system("pause");
	}

}
