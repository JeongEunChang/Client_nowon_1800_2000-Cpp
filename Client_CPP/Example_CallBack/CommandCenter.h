#pragma once
#include <vector>
#include "SCV.h"
using namespace std;

class CommandCenter
{
private:
	static CommandCenter* _instance;
	int _minerals;
	int _unitSpawnCount;

public:
	vector<SCV> SCVs;

	static CommandCenter* GetInstance();
	void UpdateAllSCVs();
	bool TrySpawnSCV();
	static void SCVCallBack(int id);
	void SpawnSCV();
	void Register(SCV& scv);
	int GetUnitSpawnCount();
	void IncreaseMinerals(int amount);
};

