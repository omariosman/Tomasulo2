#include "Instruction.h"


Instruction::Instruction(){
	status = 0;
	rd = 0;
	rs1 = 0;
	rs2 = 0;
	rs1_name = "";
	rs2_name = "";
	rd_name = "";
	
}

//get reservation station
 ReservationStation Instruction::get_reservation_station(){
       return rs;
}

 void Instruction::setClk(int c){
       clk = c;
    }
        
 int Instruction::getClk(){return clk;}
 
 
 //set rd
 void Instruction::set_rd(int _rd){
 	rd = _rd;
 }
 
 //set rs1
 void Instruction::set_rs1(int _rs1){
 	rs1 = _rs1;
 }
 
 
 //set rs2
 void Instruction::set_rs2(int _rs2){
 	rs2 = _rs2;
 }
 
 //set name
 void Instruction::set_name(string _name){
 	name = _name;
 }
 
 //set status
  void Instruction::set_status(int _status){
 	status = _status;
 }
 
  
 //set issue clk
  void Instruction::set_issue_clk(int _issue_clk){
 	issue_clk = _issue_clk;
 }
 
 
 //get rd
 int Instruction::get_rd(){
 	return rd;
 }
 
 //get rs1
 int Instruction::get_rs1(){
 	return rs1;
 }
 
 //get rs2
 int Instruction::get_rs2(){
 	return rs2;
 }
 
  //get name
 string Instruction::get_name(){
 	return name;
 }
 
 //get status
 int Instruction::get_status(){
 	return status;
 }
 

  
 //get issue lck
 int Instruction::get_issue_clk(){
 	return issue_clk;
 }
 
 
 //set rd name
 void Instruction::set_rd_name(string _rd_name){
 	rd_name = _rd_name;
 }
 //set rs1 name
  void Instruction::set_rs1_name(string _rs1_name){
 	rs1_name = _rs1_name;
 }
 //set rs2 name
  void Instruction::set_rs2_name(string _rs2_name){
 	rs2_name = _rs2_name;
 }
 
 //set type
 void Instruction::set_type(string _type){
 	type = _type;
 }
 
 //get rd name
  string Instruction::get_rd_name(){
 	return rd_name;
 }
 
 
 //get rs1 name
  string Instruction::get_rs1_name(){
 	return rs1_name;
 }
 
 
 //get rs2 name
  string Instruction::get_rs2_name(){
 	return rs2_name;
 }
 
 string Instruction::get_type(){
 	return type;
 }
 
 
 
 void Instruction::print_clk(){
 	cout << "issue clk: " << get_issue_clk() << endl;
 }
 
 void Instruction::set_reservation_station(ReservationStation _rs){
 	rs = _rs;
 }
 
 void Instruction::print_info(){
 	cout << "rs1: " << rs1_name << " " << rs1 << endl;
 	cout << "rs2: " << rs2_name << " " << rs2 << endl;
 	cout << "rd: " << rd_name << " " << rd << endl;
 	cout << "issue clock: " << issue_clk << endl;
 	
 }
 
 
 
 
 
 
 
 
 
 
 
