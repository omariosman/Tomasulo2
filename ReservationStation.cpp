#include "ReservationStation.h"

ReservationStation::ReservationStation(){
	Vj = 0;
	Vk = 0;
	Qj = "0";
	Qk = "0";
}
	void ReservationStation::setId(int _Id){
		Id = _Id;
	}
	
	void ReservationStation::setName(string _name){
		name = _name;
	}
	
	void ReservationStation::setBusy(bool bus){
		busy = bus;
	}
	void ReservationStation::setOp(string Op){
		op = Op;
	}
	void ReservationStation::setVj(int vj){
		Vj = vj;
	}
	void ReservationStation::setVk(int vk){
		Vk = vk;
	}
	void ReservationStation::setQj(string qj){
		Qj = qj;
	}
	void ReservationStation::setQk(string qk){
		Qk = qk;
	}
	void ReservationStation::setAddr(long add){
		addr = add;
	}
	int ReservationStation::getId(){return Id;}
	string ReservationStation::getName(){return name;}
	bool ReservationStation::getBusy(){return busy;}
	string ReservationStation::getOp(){return op;}
	int ReservationStation::getVj(){return Vj;}
	int ReservationStation::getVk(){return Vk;}
	string ReservationStation::getQj(){return Qj;}
	string ReservationStation::getQk(){return Qk;}
	long ReservationStation::getAddr(){return addr;}

//set execution cycles	
void ReservationStation::set_execution_cycles(int _execution_cycles){
		execution_cycles = _execution_cycles;
	}
	
// get execution cycles
int ReservationStation::get_execution_cycles(){
		return execution_cycles;
	}
	
	
