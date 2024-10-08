/*
============================================================================================
상태패턴 : 디자인 패턴중 하나
싱글턴패턴
옵저버
전략패턴
추상메서드
==============================================================================================
*/
#pragma region enumeration_status
/*
-상태를 나타내는 열거형
enum class STATE
{
	ATTACK,
	RUN,
	JUMP
};

void RunState()
{
	cout << "달리고 있다 ! " << endl;
};
void JumpState()
{
	cout << "점프하고 있다 ! " << endl;
};
void AttackState()
{
	cout << "공격하고 있다 ! " << endl;
};

int main()
{
	//작은 규모의 상태면 이렇게 처리하는것도 가능함 , 확장이 용이하지 않고 전환이 복잡함
	STATE state = STATE::ATTACK;

	switch(state)
	{
	case STATE::ATTACK:
		AttackState();
		break;
	case STATE::JUMP:
		JumpState();
		break;
	case STATE::RUN:
		RunState();
		break;
	default:
		break;
	}
}
*/
#pragma endregion

#include<iostream>

using namespace std;

#pragma region CharacterStatePattern
class IState
{
public:
	virtual void EnterState() = 0;
	virtual void InputEvent() = 0;
	virtual void Update() = 0;
	virtual void ExitState() = 0;
};
class JumpState : public IState
{
public :
	void EnterState()override
	{
		cout << "점프 상태로 진입" << endl;
	}
	void InputEvent()override
	{
		cout << "점프 중에 키입력을 받는다" << endl;
	}
	void Update()override
	{
		cout << "점프중에 위치 변경" << endl;
	}
	void ExitState()override
	{
		cout << "점프 끝 ! " << endl;
	}

};
class RunState : public IState
{
public:
	void EnterState()override
	{
		cout << "달리는 상태로 진입" << endl;
	}
	void InputEvent()override
	{
		cout << "달리던 중에 키입력을 받는다" << endl;
	}
	void Update()override
	{
		cout << "달리는 속도를 업데이트 한다" << endl;
	}
	void ExitState()override
	{
		cout << "점프 끝 ! " << endl;
	}
};
class Character
{
private:
	IState* curState;
public:
	Character()
	{
		curState = new RunState();//기본상태
	}
	void setcurState(IState* s)
	{
		curState->ExitState();//이전 상태 종료
		curState = s;//현재 상태를 변경
		curState->EnterState();//진입
	}
	void InputEvent()
	{
		curState->InputEvent();
	}
	void Update()
	{
		curState->Update();
	}
};
#pragma endregion

int main()
{


	Character c;

	c.InputEvent();

	c.Update();

	c.setcurState(new JumpState());

	c.InputEvent();

	c.Update();

}