#include <iostream>

using namespace std;


class a_weight
{
	char *name;
	char *gender;
	int obesity;
	double height,weight,standardweight;
public:
	a_weight()
	{
		name=gender=0;
		weight=obesity=standardweight=0;
	}
	~a_weight()
	{
		cout <<">>>>>>>>\t 프로그램 종료"<<endl;
		delete []name;
		delete []gender;
	}
	void input_data()
	{
		char name[20],gender[10];
		cout << ">>>>>>>>\t이름 입력:";
		cin >> name;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		fflush(stdin);
		b:
		cout << ">>>>>>>>\t성별 입력"<<endl;
		cout << ">>>>>>>>\t예)남,여,남자,여자"<<endl;
		cout << ">>>>>>>>\t입력:";
		cin >> gender;
		if((strcmp(gender,"남자") == 0)||(strcmp(gender,"남") == 0)||(strcmp(gender,"boy") == 0)||(strcmp(gender,"man") == 0)||(strcmp(gender,"여자") == 0)||(strcmp(gender,"여") == 0)||(strcmp(gender,"girl") == 0)||(strcmp(gender,"woman") == 0))
		{
			this->gender = new char[strlen(gender)+1];
			strcpy(this->gender,gender);
		}
		else
		{
			cout <<">>>>>>>>\t잘못입력하셨습니다"<<endl;
			goto b;
		}
		fflush(stdin);
		c:
		cout <<">>>>>>>>\t체중 입력(kg):";
		cin >> weight;
		if(strcmp(this->gender,"남자") == 0||strcmp(this->gender,"남") == 0 ||strcmp(this->gender,"boy") == 0 ||strcmp(this->gender,"man") == 0)
		{
			if(weight<40)
			{
				cout << ">>>>>>>>\t잘못입력하셨습니다."<< endl;
				goto c;
			}
		}
		if(strcmp(this->gender,"여자") == 0,strcmp(this->gender,"여") == 0||strcmp(this->gender,"girl") == 0||strcmp(this->gender,"woman") == 0)
		{
			if(weight<30)
			{
				cout << ">>>>>>>>\t잘못입력하셨습니다."<< endl;
				goto c;
			}
		}
		fflush(stdin);
		d:
		cout <<">>>>>>>>\t키 입력(cm):";
		cin >> height;
		if(height<50)
		{
			cout << ">>>>>>>>\t잘못입력하셨습니다."<< endl;
			goto d;
		}
		height = height/100;
		fflush(stdin);
	}
	void standardweight_obesity()
	{
		if(strcmp(this->gender,"남자") == 0||strcmp(this->gender,"남") == 0||strcmp(this->gender,"boy") == 0||strcmp(this->gender,"man") == 0)
		{
			standardweight = height*height*22;
			obesity = (weight/standardweight)*100;
			obesity_data();
		}
		else
		{
			standardweight = height*height*21;
			obesity = (weight/standardweight)*100;
			obesity_data();
		}
	}
	void obesity_data()
	{
		if(obesity > 0 && obesity < 85)
		{
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
		    cout <<">>>>>>>>\t이름:"<< name << endl;
			cout <<">>>>>>>>\t성별:"<< this->gender << endl;
			cout <<">>>>>>>>\t표준체중:" << standardweight<<"kg" <<endl;
			cout <<">>>>>>>>\t현재체중:" << weight <<"kg"<<endl;
			cout <<">>>>>>>>\t비만도:"<< obesity << endl;
			cout <<">>>>>>>>\t저체중입니다"<<endl;
			cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
		}
		if(obesity > 85 && obesity <= 105)
		{
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
			cout <<">>>>>>>>\t이름:"<< name << endl;
			cout <<">>>>>>>>\t성별:"<< this->gender << endl;
			cout <<">>>>>>>>\t표준체중:" <<standardweight<<"kg" <<endl;
			cout <<">>>>>>>>\t현재체중:" <<weight <<"kg"<<endl;
			cout <<">>>>>>>>\t비만도:" << obesity << endl;
			cout <<">>>>>>>>\t표준체중입니다"<<endl;
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
		}
		if(obesity > 105 && obesity <= 115)
		{
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
			cout <<">>>>>>>>\t이름:"<< name << endl;
			cout <<">>>>>>>>\t성별:"<< this->gender << endl;
			cout <<">>>>>>>>\t표준체중:" <<standardweight<<"kg" <<endl;
			cout <<">>>>>>>>\t현재체중:" <<weight <<"kg"<<endl;
			cout <<">>>>>>>>\t비만도:" << obesity << endl;
			cout <<">>>>>>>>\t과체중입니다"<<endl;
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
		}
		if(obesity > 115 && obesity <= 135)
		{
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
			cout <<">>>>>>>>\t이름:"<< name << endl;
			cout <<">>>>>>>>\t성별:"<< this->gender << endl;
			cout <<">>>>>>>>\t표준체중:" <<standardweight<<"kg" <<endl;
			cout <<">>>>>>>>\t현재체중:" <<weight <<"kg"<<endl;
			cout <<">>>>>>>>\t비만도:" << obesity << endl;
			cout <<">>>>>>>>\t약한비만입니다"<<endl;
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
		}
		if(obesity > 135)
		{
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
			cout <<">>>>>>>>\t이름:"<< name << endl;
			cout <<">>>>>>>>\t성별:"<< this->gender << endl;
			cout <<">>>>>>>>\t표준체중:" <<standardweight<<"kg" <<endl;
			cout <<">>>>>>>>\t현재체중:" <<weight <<"kg"<<endl;
			cout <<">>>>>>>>\t비만도:" << obesity << endl;
			cout <<">>>>>>>>\t심한비만입니다"<<endl;
			cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
		}
	}
	void print_data()
	{
		standardweight_obesity();
	}


};
int main()
{
	int choice;
	a_weight a;
	while(1)
	{
		system("cls");
		cout << "= = = = = = = = = 비만도 측정 = = = = = = = = = = = = =" << endl;
		cout << "             ver 1.0 kbs" <<endl;
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
		cout << ">>>>>>>>\t 1.성별,체중,키 입력"<<endl;
		cout << ">>>>>>>>\t 2.비만도 측정"<<endl;
		cout << ">>>>>>>>\t 3. 종료"<<endl;
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
		cout << ">>>>>>>>\t";
		cin >> choice;
		switch(choice)
		{
		case 1:
			a.input_data();
			break;

		case 2:
			a.print_data();
			break;
		case 3:
			return 0;
		default:
			cout<< ">>>>>>>>\t잘못입력하셨습니다"<<endl;
			break;
		}
		system("pause");
	}
}
