#include "InstructionAdd.h"

InstructionAdd::InstructionAdd(){
	status = 0;
}

 void InstructionAdd::setClk(int c){
       clk = c;
    }
        
 int InstructionAdd::getClk(){return clk;}
 
 
 //set rd
 void InstructionAdd::set_rd(int _rd){
 	rd = _rd;
 }
 
 //set rs1
 void InstructionAdd::set_rs1(int _rs1){
 	rs1 = _rs1;
 }
 
 
 //set rs2
 void InstructionAdd::set_rs2(int _rs2){
 	rs2 = _rs2;
 }
 
 //set name
 void InstructionAdd::set_name(string _name){
 	name = _name;
 }
 
 //set status
  void InstructionAdd::set_status(int _status){
 	status = _status;
 }
 
  
 //set issue clk
  void InstructionAdd::set_issue_clk(int _issue_clk){
 	issue_clk = _issue_clk;
 }
 
 
 //get rd
 int InstructionAdd::get_rd(){
 	return rd;
 }
 
 //get rs1
 int InstructionAdd::get_rs1(){
 	return rs1;
 }
 
 //get rs2
 int InstructionAdd::get_rs2(){
 	return rs2;
 }
 
  //get name
 string InstructionAdd::get_name(){
 	return name;
 }
 
 //get status
 int InstructionAdd::get_status(){
 	return status;
 }
 

  
 //get issue lck
 int InstructionAdd::get_issue_clk(){
 	return issue_clk;
 }
 
 
 //set rd name
 void InstructionAdd::set_rd_name(string _rd_name){
 	rd_name = _rd_name;
 }
 //set rs1 name
  void InstructionAdd::set_rs1_name(string _rs1_name){
 	rs1_name = _rs1_name;
 }
 //set rs2 name
  void InstructionAdd::set_rs2_name(string _rs2_name){
 	rs2_name = _rs2_name;
 }
 
 //get rd name
  string InstructionAdd::get_rd_name(){
 	return rd_name;
 }
 
 
 //get rs1 name
  string InstructionAdd::get_rs1_name(){
 	return rs1_name;
 }
 
 
 //get rs2 name
  string InstructionAdd::get_rs2_name(){
 	return rs2_name;
 }
 
 
 
 void InstructionAdd::print_clk(){
 	cout << "issue clk: " << get_issue_clk() << endl;
 }
 
 
 
 
 
 
 
 
 
 
 
