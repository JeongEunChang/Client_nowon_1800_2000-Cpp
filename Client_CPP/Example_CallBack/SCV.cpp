#include "SCV.h"
#include <iostream>
#include <chrono>
#include "CommandCenter.h"

using namespace std;


SCV::SCV()
{
	state = STATE::IDLE;
	timeMark = 0.0;
	CommandCenter* commandcenter = CommandCenter::GetInstance();
	id = commandcenter->GetUnitSpawnCount();
	commandcenter->Register(*this);
}

void SCV::DoMine()
{
	cb(id);
	state = STATE::START_MINING;
}

void SCV::UpatdState()
{
	switch (state)
	{
	case SCV::IDLE:
		break;
	case SCV::START_MINING:
		timeMark = clock();
		NextState();
		// state = STATE::ON_MINING;
		// state = (STATE)(state + 1);
		break;
	case SCV::ON_MINING: // 채굴 완료되었는지 체크
		if (clock() - timeMark > SCV_MININGTIME) {
			NextState();
		}
		break;
	case SCV::FINISH_MINING: // 커맨드 센터 총 미네량 양 증가
		CommandCenter::GetInstance()->IncreaseMinerals(SCV_MINING_AMOUNT);
		state = STATE::IDLE;
		break;
	default:
		break;
	}
}

void SCV::NextState()
{
	state = (STATE)(state + 1);
}

void SCV::RegisterCallBack(REGISTER_CALLBACK callback)
{
	this->cb = callback; // 정적 맴버 내에서는 this 사용 왜 불가능?
}


