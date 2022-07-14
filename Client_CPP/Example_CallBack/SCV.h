#pragma once

#define SCV_COST 50
#define SCV_MININGTIME 2000
#define SCV_SPAWN_TIME 4000
#define SCV_MINING_AMOUNT 8

typedef void(*REGISTER_CALLBACK)(int);
// define 할 때는 세미 콜론 안 사용함

class SCV
{
public:
	enum STATE
	{
		IDLE,
		START_MINING,
		ON_MINING,
		FINISH_MINING
	};

	STATE state;
	double timeMark;
	int id;
	REGISTER_CALLBACK cb; // 이렇게 인스턴스화 시키면, void Register(SCV& scv, REGISTER_CALLBACK cb); 이 경우는 어떻게 해석해야 함?

	SCV();
	void DoMine();
	void UpatdState();
	void NextState();
	void RegisterCallBack(REGISTER_CALLBACK callback);

};

