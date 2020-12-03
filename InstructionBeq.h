#pragma once
#include<iostream>
using namespace std;

class InstructionBeq{
    private:
        int numberOfInstructions;
        int clk;
    public:
    void setClk(int c);
    int getClk();
        
};
