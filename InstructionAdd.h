#pragma once
#include<iostream>
using namespace std;

class InstructionAdd{
    private:
        int numberOfInstructions;
        int clk;
        string name;
        string rs1_name;
        string rs2_name;
        string rd_name;
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
    
    string get_rd_name();
    string get_rs1_name();
    string get_rs2_name();
    
    int get_status();
    int get_issue_clk();
    string get_name();
    void set_rd(int _rd);
    void set_rs1(int _rs1);
    void set_rs2(int _rs2);
    void set_name(string _name);
    void set_status(int _status);
    void set_issue_clk(int _issue_clk);
    
    void set_rd_name(string _rd_name);
    void set_rs1_name(string _rs1_name);
    void set_rs2_name(string _rs2_name);
    void print_clk();
    
    
};
