#pragma once

#define SCV_COST 50
#define SCV_MININGTIME 2000
#define SCV_SPAWN_TIME 4000
#define SCV_MINING_AMOUNT 8

typedef void(*REGISTER_CALLBACK)(int);
// define �� ���� ���� �ݷ� �� �����

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
	REGISTER_CALLBACK cb; // �̷��� �ν��Ͻ�ȭ ��Ű��, void Register(SCV& scv, REGISTER_CALLBACK cb); �� ���� ��� �ؼ��ؾ� ��?

	SCV();
	void DoMine();
	void UpatdState();
	void NextState();
	void RegisterCallBack(REGISTER_CALLBACK callback);

};

