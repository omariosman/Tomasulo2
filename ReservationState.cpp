#include "ReservationStation.h"

	
	void ReservationStation::setName(int nam){
		name = nam;
	}
	void ReservationStation::setBusy(bool bus){
		busy = bus;
	}
	void ReservationStation::setOp(string Op){
		op = Op;
	}
	void ReservationStation::setVj(string vj){
		Vj = vj;
	}
	void ReservationStation::setVk(string vk){
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
	int ReservationStation::getName(){return name;}
	bool ReservationStation::getBusy(){return busy;}
	string ReservationStation::getOp(){return op;}
	string ReservationStation::getVj(){return Vj;}
	string ReservationStation::getVk(){return Vk;}
	string ReservationStation::getQj(){return Qj;}
	string ReservationStation::getQk(){return Qk;}
	long ReservationStation::getAddr(){return addr;}
