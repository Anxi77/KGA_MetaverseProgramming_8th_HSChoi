/*
	1. 사용자가 입력한 양의 정수의 각 자리수의 합 구하기 (함수로 만들기)
	EX) 15248 = 20 (모듈러연산 , 나머지연산 , 나누기연산)
	2. 사용자가 입력한 최대값과 최소값 (함수)
	ex)5,1
	출력 : 최대값은 5 , 최소값 1

*/

#include <iostream>

using namespace std;

void minMaxif() 
{
	int num1;
	int num2;
	num1 = 0;
	num2 = 0;
	cout << "첫번째 숫자를 입력해주세요 : ";
	cin >> num1;
	cout << "두번째 숫자를 입력해주세요 : ";
	cin >> num2;

	int res;
	res = 0;

	
	res = num1 - num2;

	if (num1 > num2)
	{
		cout << "입력해주신 숫자의 최대값은 : " << num1 << " 이고 " << " | " << " 최솟값은 : " << num2 << " 입니다 ";
	}
	else 
	{
		cout << "입력해주신 숫자의 최대값은 : " << num2 << " 이고 " << " | " << " 최솟값은 : " << num1 << " 입니다 ";
	}
}

void minMaxArr() //Array를 사용하여 사용자가 원하는 n개만큼의 숫자를 입력받고 최소값과 최대값을 출력하는 함수
{
	int n;
	int min=0;
	int max=0;
	cout << "입력하실 숫자의 갯수를 입력해 주십시오 : ";
	cin >> n;
	int* comp = new int[n];

	for (int i = 0 ; i < n; i++)
	{
		cout << "숫자를 입력해 주십시오 : ";
		cin >> comp[i];
	}
	max = comp[0];
	min = comp[0];
	for (int i = 0; i < n; i++)
	{

		if (min > comp[i]) 
		{
			min = comp[i];
		}
		if (max < comp[i])
		{
			max = comp[i];
		}
	}
	
	cout << "최소값은 : " << min << " | " << " 최대값은 : " << max << endl;
	delete[] comp;
/*======================================기능설명 및 작동원리===============================
=========================================기능설명=======================================

기능 : 사용자가 원하는 갯수만큼의 숫자를 입력받고 , 그 숫자들 중 최대값과 최소값을 출력한다 .


1. 사용자가 입력을 원하는 숫자의 갯수를 입력받는다 .

int n; // <- (n 이라는 사용자가 원하는 숫자의 갯수에 대응하는 변수 선언)
cout << "입력을 원하는 숫자의 갯수를 입력해주세요 : ";
cin >> n; // <- (숫자의 갯수에 대한 변수 입력)

2.최소값과 최대값에 대응하는 변수 선언과 초기화

int min=0; //<-최소값
int max=0; //<-최대값

2.사용자가 원하는 갯수만큼의 숫자를 입력받는 그룹지어진 배열 (comp) 선언

int* comp = new int[n]; // <-원하는 숫자의 갯수 n 만큼의 배열을 생성하는 comp 라는 변수를 new 연산자를 이용하여 선언

*연산자 (Operator) 'new'*

갯수가 선언되지 않거나 그룹지어진 변수를 받을때의 기본형
ㄴint(주소를 저장할 포인터(메모리의 주소) int , short int , float , double 등 자료형이 들어간다) *변수의 이름 = new int(할당하고 싶은 크기의 자료형)[입력을 받을 변수의 그룹] ;

new 연산자를 사용할 때에는 동적 메모리를 할당해주었기때문에 함수와 변수와 다르게 실행이 끝나면 변수의 수명이 끝나는것이 아니라 수동으로 해제를 해야 한다.
수동으로 해제하기 위해서는 delete 라는 연산자를 사용하여 할당된 메모리를 해제해야 한다.

그룹 형식으로 메모리가 할당되었을때 delete 연산자 사용법
ㄴdelete[] p;


3. 원하는 숫자의 갯수만큼 숫자를 입력받는다 .

for (int i = 0; i < n; i++) // for 문을 사용하여 i라는 조건변수가 0에서부터 n미만일때까지 comp라는 숫자를 입력받는 반복문 작성
{
	cout<<"숫자를 입력 해 주세요 : "
	cin >> comp[i] //<- 위에서 지정한 i가 증가함에 따라 0에서부터 증가하는 주소의 comp변수에 값을 입력
}

4. 최소값과 최대값을 추출하기 위하여 가장 처음으로 입력된 숫자가 입력된 comp[0] 이라는 주소값에 있는 값을 위에 입력한 min(최소값) , max(최대값) 에 대입

max = comp[0]
min = comp[0]

5. 입력받은 n개의 갯수만큼 숫자가 저장되어있는 comp[n] 안에 있는 값을 비교하여 최소값일땐 min으로 출력하고 최대값이면 max로 출력하는 for 반복문 작성

for (int i = 0; i < n; i++)
{

	if (min > comp[i])
	{
		min=comp[i]
	}
	if (max < comp[i])
	{
		max=comp[i]
	}

}

*if문은 ()안의 조건이 참(true) 일때 {}안에있는 코드를 실행*

for 문의 종료조건은 i가 0 부터 n 미만일때 까지인데
i를 0으로 초기화하였고 i++ 로 i가 1씩 증가한다.

==============================작동원리=========================================

15[배열주소 0번] 18[배열주소 1번] 17[배열주소 2번] 11[배열주소 3번] 네개의 숫자를 입력받았을 경우에

----------루프 0--------------

첫번째 if 문 실행

첫번째 if문의 조건은 min (comp에 0번 주소 (첫번째 주소))에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(0) 을 comp[i] 에 대입 -> comp[0] = 15) 와 비교한다는 조건이다.

조건이 min > comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 초과) 이기에

min (15) > comp[0](15) <-False

조건이 False 이므로 if 문 안에있는 min = comp[i] 라는 구문이 실행되지 않는다.

두번째 if 문 실행

두번째 if문의 조건은 max (comp에 0번 주소 (첫번째 주소))에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(0) 을 comp[i] 에 대입 -> comp[0] = 15) 와 비교한다는 조건이다.

조건이 max > comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 초과) 이기에

min (15) > comp[0](15) <-False

조건이 False 이므로 if 문 안에있는 max = comp[i] 라는 구문이 실행되지 않는다.



--------------루프 1--------------

첫번째 if 문 실행

i++에 인하여 i 가 0에서 1로 증가

첫번째 if문의 조건은 min (comp에 1번 주소 (두번째 주소))에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(1) 을 comp[i] 에 대입 -> comp[1] = 18) 와 비교한다는 조건이다.

조건이 min > comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 초과) 이기에

min (15) > comp[1](18) <-False

조건이 false이기에 대입되지 않는다

두번째 if 문 실행

두번째 if문의 조건은 max (comp에 1번 주소 (두번째 주소))에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(1) 을 comp[i] 에 대입 -> comp[1] = 18) 와 비교한다는 조건이다.

조건이 max < comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 초과) 이기에

max (15) < comp[1](18) <- True

조건이 True 이므로 원래 15였던 max 의 값을 comp[1] (18) 치환/대입

-------------------루프 2-----------------------------------

첫번째 if 문 실행

i++에 인하여 i 가 1에서 2로 증가
루프 1의 두번째 if 문에 의하여 max에 18이라는 값이 대입된 상태이다 .

첫번째 if문의 조건은 min (comp에 0번 주소 (세번째 주소))에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(2) 을 comp[i] 에 대입 -> comp[2] = 17) 와 비교한다는 조건이다.

조건이 min > comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 초과) 이기에

min (15) > comp[2](17) <-False

조건이 false이기에 대입되지 않는다

두번째 if 문 실행

두번째 if문의 조건은 max (comp에 1번 주소 (두번째 주소)에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(2) 을 comp[i] 에 대입 -> comp[2] = 17) 와 비교한다는 조건이다.

조건이 max < comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 미만) 이기에

max (18) < comp[2](17) <- False

조건이 False 이므로 if 문 안에있는 max = comp[i] 라는 구문이 실행되지 않는다.

-------------------------루프 3--------------------------

첫번째 if 문 실행

i++에 인하여 i 가 2에서 3로 증가
루프 1의 두번째 if 문에 의하여 max에 18이라는 값이 대입된 상태이다 .

첫번째 if문의 조건은 min (comp에 3번 주소 (네번째 주소))에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(3) 을 comp[i] 에 대입 -> comp[3] = 11) 와 비교한다는 조건이다.

조건이 min > comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 초과) 이기에

min (15) > comp[3](11) <- True

조건이 True 이므로 if 문 안에있는 min = comp[i] 라는 구문이 실행되어 min 의 값에 11(comp의 두번째 주소에 있는 값)을 대입한다.

두번째 if 문 실행

두번째 if문의 조건은 max (comp에 3번 주소 (네번째 주소))에 할당되어있는 값 '15')을
comp[i] (조건안에 있는 변수 i(3) 을 comp[i] 에 대입 -> comp[0] = 18) 와 비교한다는 조건이다.

조건이 max < comp[i] (min의 값이 i번째 주소에 들어있는 comp의 값 미만) 이기에

max (18) < comp[2](17) <- False

조건이 False 이므로 if 문 안에있는 max = comp[i] 라는 구문이 실행되지 않는다.

------------------루프 종료-----------------

마지막 루프를 실행했을 때 대입되어있던 min 값과 max 값을 출력한다.

cout << "최소값은 : " << min(11) << " | " << " 최대값은 : " << max(18) << endl;

"최소값은 : 11 | 최대값은 : 18" 이라는 메세지가 출력된다.

그리고 마지막으로

delete[] comp; 로 delete 연산자를 사용하여 comp에 할당되어있던 동적 메모리를 해제해준다.







*/
}


void sumEA() //모든 자릿수 더하기 함수
{
	int n; // 입력 받을 수
	n = 0;
	int sum; // 출력할 수
	sum = 0;
	cout << "임의의 숫자를 입력해주세요 : ";
	; // 수의 입력
	
	while (n > 0) 
	{
		int num1;
		num1 = n % 10;
		sum += num1;
		n = n / 10;
	}
	cout << endl;
	cout << "입력해주신 수의 모든 자릿수를 더한 결과는 : " << sum;

	/*============================================기능설명==============================================
	* 숫자를 10으로 나눈 나머지는 가장 첫번째 자릿수이다
	* e .g) 12*9* / 10 -> 120/10=12 나머지 *9*
	이렇게 각 자릿수를 원래 받은 숫자가 0이 될때까지 10으로 계속 나누면 모든 자릿수를 추출할 수 있다.

	1. 숫자를 받는다
	ㄴ cin >> n;
	2. 반복문 바깥에서 출력한 숫자를 받아줄 변수를 선언한다. 
	ㄴint sum;
	3. 숫자를 0이 될때까지 10으로 나눈 나머지를 추출할 반복문을 작성한다.
	ㄴwhile (input > 0){} 
	4. 숫자를 10으로 나누고 나머지를 반복문 안에서 num1 이라는 변수로 출력한다 (1의 자릿수 출력) 
	ㄴ num1 = input % 10;
	5. 이때 이 1의 자릿수(num1)은 sum 이라는 변수에 저장하고
	ㄴ sum=num1
	6. 반복문이 반복되는 동안 (원래 입력한 숫자를 10으로 계속나누다가 0이 될때까지) 서로 더한다
	ㄴ sum+=num1
	7. 그리고 1의 자릿수를 제외한 나머지를 다시 n 으로 출력한다.
	ㄴ n = n / 10;
	8. 숫자가 사라질때(0이 될때)까지  반복한다.
	ㄴwhile *(input > 0)* <- "input > 0" 이라는 조건이 false가 될때까지 반복된다.
	9. 1의 자릿수를 모두 더한 변수 (sum) 을 출력한다
	ㄴ cout << sum;
	*/
	
}


int main()
{
	minMaxArr();
}