#pragma once
#include<iostream>
#include<string>
using namespace std;

class ReservationStation{
private:
	int name;
	bool busy;
	string op;
	string Vj;
	string Vk;
	string Qj;
	string Qk;
	long addr;
	int execution_cycles;
public:
	void setName(int nam);
	void setBusy(bool bus);
	void setOp(string Op);
	void setVj(string vj);
	void setVk(string vk);
	void setQj(string qj);
	void setQk(string qk);
	void setAddr(long add);
	int getName();
	bool getBusy();
	string getOp();
	string getVj();
	string getVk();
	string getQj();
	string getQk();
	long getAddr();
	void set_execution_cycles(int _execution_cycles);
	int get_execution_cycles();

};

