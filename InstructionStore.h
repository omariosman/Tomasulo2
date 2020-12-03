#pragma once
#include<iostream>
using namespace std;

class InstructionStore{
    private:
        int numberOfInstructions;
        int clk;
    public:
        void setClk(int c){
            clk = c;
        }
        int getClk(){return clk;}
};
