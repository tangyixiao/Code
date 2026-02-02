#include <cmath>
#include <iostream>
#include <windows.h>


// 生成指定频率和时长的声音
void playBeep(int frequency, int duration_ms) {
    // Windows API播放声音
    Beep(frequency, duration_ms);
}

int main() {
    // 播放高频声波（20000Hz，持续1秒）
    // 注意：大多数扬声器能支持15-20kHz，但人耳可能听不到
    //playBeep(20000, 1000); // 20kHz，1秒

    /*

    // 也可以尝试可听频率
    std::cout << "播放10kHz声音..." << std::endl;
    playBeep(10000, 1000); // 10kHz，1秒

    */
    
    playBeep(15000, 10000); 

    return 0;
}