#pragma once
#include<iostream>
using namespace std;

class InstructionLoad{
    private:
        int numberOfInstructions;
        int clk;
    public:
        void setClk(int c);
        int getClk();
};
