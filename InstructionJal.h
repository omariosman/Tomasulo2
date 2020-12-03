#pragma once
#include<iostream>
using namespace std;

class InstructionJal{
    private:
        int numberOfInstructions;
        int clk;
    public:
       	void setClk(int c);
    	int getClk();
};
