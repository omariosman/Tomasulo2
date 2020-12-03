#pragma once
#include<iostream>
using namespace std;

class InstructionAdd{
    private:
        int numberOfInstructions;
        int clk;
        string name;
        int rs1;
        int rs2;
        int rd; 
        int status;
        int issue_clk;

    public:
    InstructionAdd();
    void setClk(int c);
    int getClk();
    int get_rd();
    int get_rs1();
    int get_rs2();
    int get_status();
    int get_issue_clk();
    string get_name();
    void set_rd(int _rd);
    void set_rs1(int _rs1);
    void set_rs2(int _rs2);
    void set_name(string _name);
    void set_status(int _status);
    void set_issue_clk(_issue_clk);
    
    
};
