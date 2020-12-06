#include "GeneralInstruction.h"


GeneralInstruction::GeneralInstruction(){
	add_flag = 0;
	div_flag = 0;
	beq_flag = 0;
	jal_flag = 0;
	load_flag = 0;
	store_flag = 0;
}

//setters
void GeneralInstruction::set_instruction_add(InstructionAdd _instruction_add){
	instruction_add = _instruction_add;
}

void GeneralInstruction::set_instruction_beq(InstructionBeq _instruction_beq){
	instruction_beq = _instruction_beq;
}

void GeneralInstruction::set_instruction_jal(InstructionJal _instruction_jal){
	instruction_jal = _instruction_jal;
}

void GeneralInstruction::set_instruction_div(InstructionDiv _instruction_div){
	instruction_div = _instruction_div;
}

void GeneralInstruction::set_instruction_store(InstructionStore _instruction_store){
	instruction_store = _instruction_store;
}


void GeneralInstruction::set_instruction_load(InstructionLoad _instruction_load){
	instruction_load = _instruction_load;
}


//flags setters
void GeneralInstruction::set_add_flag(){
	add_flag = 1;
}



void GeneralInstruction::set_div_flag(){
	div_flag = 1;
}


void GeneralInstruction::set_beq_flag(){
	beq_flag = 1;
}


void GeneralInstruction::set_load_flag(){
	load_flag = 1;
}


void GeneralInstruction::set_store_flag(){
	store_flag = 1;
}


void GeneralInstruction::set_jal_flag(){
	jal_flag = 1;
}


//getters
InstructionAdd GeneralInstruction::get_instruction_add(){
	return instruction_add;
}


InstructionDiv GeneralInstruction::get_instruction_div(){
	return instruction_div;
}

InstructionLoad GeneralInstruction::get_instruction_load(){
	return instruction_load;
}

InstructionBeq GeneralInstruction::get_instruction_beq(){
	return instruction_beq;
}


InstructionStore GeneralInstruction::get_instruction_store(){
	return instruction_store;
}

InstructionJal GeneralInstruction::get_instruction_jal(){
	return instruction_jal;
}

//flags getters
int GeneralInstruction::get_add_flag(){
	return add_flag;
}

int GeneralInstruction::get_div_flag(){
	return div_flag;
}


int GeneralInstruction::get_jal_flag(){
	return jal_flag;
}


int GeneralInstruction::get_beq_flag(){
	return beq_flag;
}

int GeneralInstruction::get_load_flag(){
	return load_flag;
}


int GeneralInstruction::get_store_flag(){
	return store_flag;
}

//determine type
int GeneralInstruction::determine_type(){
	if (add_flag){
		return 0;
	}

	if (div_flag){
		return 1;
	}	
	

	if (jal_flag){
		return 2;
	}	
	

	if (beq_flag){
		return 3;
	}	
	

	if (load_flag){
		return 4;
	}	

	if (store_flag){
		return 5;
	}		

}

