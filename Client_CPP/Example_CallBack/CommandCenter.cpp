#include "CommandCenter.h"
#include "SCV.h"
#include <iostream>

using namespace std;

CommandCenter* CommandCenter::_instance = NULL;

CommandCenter* CommandCenter::GetInstance()
{
    if (_instance == nullptr) {
        _instance = new CommandCenter();
    }

    return _instance;
}

void CommandCenter::UpdateAllSCVs()
{
    vector<SCV>::iterator iter = SCVs.begin();

    for (; iter != SCVs.end(); iter++)
    {
        if (iter->state == SCV::STATE::IDLE) {
            iter->DoMine();
        }
        iter->UpatdState();
    }
}

bool CommandCenter::TrySpawnSCV()
{
    if (_minerals > SCV_COST) {
        _minerals -= SCV_COST;
        SpawnSCV();
        return true;
    }

    return false;
}

void CommandCenter::SCVCallBack(int id)
{
    cout << "SCV (Unit ID : " << id << ") ����" << endl;
}

void CommandCenter::SpawnSCV()
{
    new SCV();
    _unitSpawnCount++;
}

void CommandCenter::Register(SCV& scv)
{
    scv.RegisterCallBack(SCVCallBack); // �� ����ƽ�� ���� �����?
    SCVs.push_back(scv);
}

int CommandCenter::GetUnitSpawnCount()
{
    return _unitSpawnCount;
}

void CommandCenter::IncreaseMinerals(int amount)
{
    _minerals += amount;
    cout << "���� �̳׶�" << _minerals << endl;
}
