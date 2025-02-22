#include "barrel.hpp"

#include <cassert>
#include <iostream>

using namespace std;

Barrel::Barrel(int vol, double percent)
{
    if (vol <= 0)
    {
        vol = 0;
        percent = 0;
    }
    else if (percent < 0) percent = 0;
    else if (percent > 100) percent = 100;
    this->vol = vol;
    this->percent = percent;
}

int Barrel::get_vol() const { return vol; }

double Barrel::get_percent() const { return percent; }

void Barrel::reduce(int volume)
{
    if (volume <= 0) return;
    if (volume > vol) volume = vol;
    vol -= volume;
}

void Barrel::pour_from(Barrel& src, int volume)
{
    if (volume <= 0 || src.get_vol() - volume <= 0) return;

    src.reduce(volume); // зачерпываем из бочки
    int alco_in_dest = percent*vol; // кол-во зачерпнутого спирта (мл)
    int alco_in_cup = volume*src.get_percent(); // кол-во спирта в бочке перед вливанием (мл)
    int vol_after_pour = vol + volume; // общий объем после вливания
    
    percent = (alco_in_dest + alco_in_cup) / (vol_after_pour); // итоговая концентрация
    vol = vol_after_pour;
}
