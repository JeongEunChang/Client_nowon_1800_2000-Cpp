#include <iostream>
using namespace std;
#include "CommandCenter.h"
#include "SCV.h"
#include <windows.h>


int main()
{
    CommandCenter* commandCenter = CommandCenter::GetInstance();

    for (int i = 0; i < 2; i++) {
        commandCenter->SpawnSCV();
    }
    
    float scv_timer = SCV_SPAWN_TIME;
    float delta_time = 17; // 60fps 기준 프레임 당 걸리는 시간

    while (true)
    {
        if (scv_timer <= 0) {
            if (commandCenter->TrySpawnSCV()) {
                scv_timer = SCV_SPAWN_TIME;
            }

        }

        commandCenter->UpdateAllSCVs();

        Sleep(delta_time);
        scv_timer -= delta_time;
    }
}