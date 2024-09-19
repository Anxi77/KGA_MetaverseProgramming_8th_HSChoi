#include <iostream>

using namespace std;

struct studentInfo
{
	string name;
	double math;
	double english;
	double science;
};

double sum(double math, double english, double science)
{
	int res;
	res = math + english + science;
	return res;
}

double calculateAverage(double math, double english, double science)
{
	int res;
	res = sum(math , english, science) /3;
	return res;
}

int main()
{	
	studentInfo sti[3];
	int studentpick = 0;
	int studentnum = 0;
	bool bEsc = true;
	int endtrig = 0;

	for(int i = 0; i < 3; i++)
	{
		cout << "학생의 이름을 입력해주세요 : ";
		cin >> sti[i].name;
		cout << endl;
		cout << "학생의 수학 점수를 입력해주세요 : ";
		cin >> sti[i].math;
		cout << endl;
		cout << "학생의 영어 점수를 입력해주세요 : ";
		cin >> sti[i].english;
		cout << endl;
		cout << "학생의 과학 점수를 입력해주세요 : ";
		cin >> sti[i].science;
		cout << endl;
		cout << sti[i].name << " 학생의 " << endl;
		cout << "수학 점수 : " << sti[i].math << endl;
		cout << "영어 점수 : " << sti[i].english << endl;
		cout << "과학 점수 : " << sti[i].science << endl;
	}

	cout << "학생 명단" << endl;

	while (bEsc) 
	{
		for (int i = 0; i < 3; i++)
		{
			cout << i << ") " << sti[i].name << endl;
		}

		cout << "원하시는 학생의 번호를 입력해주세요 : ";
		cin >> studentpick;

		cout << sti[studentpick].name << " 학생의" << endl;
		cout << "수학 점수는 : " << sti[studentpick].math << endl;
		cout << "영어 점수는 : " << sti[studentpick].english << endl;
		cout << "과학 점수는 : " << sti[studentpick].science << endl;
		cout << "3 과목 점수의 합계 : " << sum(sti[studentpick].math, sti[studentpick].english, sti[studentpick].science) << " 점" << endl;
		cout << "3 과목 점수의 평균 : " << calculateAverage(sti[studentpick].math, sti[studentpick].english, sti[studentpick].science) << " 점" << endl;
		cout << endl;
		cout << "다른 학생을 확인하고 싶으시면 (1 , 종료하고 싶으시면 (2 를 눌러주세요" << endl;
		cin >> endtrig;
		while (endtrig != 1 && endtrig != 2)
		{
			if (endtrig == 2)
			{
				bEsc = false;
			}
			else if (endtrig == 1)
			{
				break;
			}
			else
			{
				cout << "유효한 숫자를 입력해 주세요 !!" << endl;
			}
		}
	}


}

