#pragma once
#include<iostream>
using namespace std;
#include "InstructionAdd.h"
#include "InstructionBeq.h"
#include "InstructionDiv.h"
#include "InstructionJal.h"
#include "InstructionLoad.h"
#include "InstructionStore.h"

class GeneralInstruction{
private:
	InstructionAdd instruction_add;
	int add_flag;
	InstructionBeq instruction_beq;
	int beq_flag;
	InstructionDiv instruction_div;
	int div_flag;
	InstructionJal instruction_jal;
	int jal_flag;
	InstructionLoad instruction_load;
	int load_flag;
	InstructionStore instruction_store;
	int store_flag;
public:
	GeneralInstruction();
	void set_instruction_add(InstructionAdd _instruction_add);
	void set_instruction_beq(InstructionBeq _instruction_beq);
	void set_instruction_div(InstructionDiv _instruction_div);
	void set_instruction_jal(InstructionJal _instruction_jal);
	void set_instruction_load(InstructionLoad _instruction_load);
	void set_instruction_store(InstructionStore _instruction_store);
	void set_add_flag();
	void set_beq_flag();
	void set_div_flag();
	void set_jal_flag();
	void set_load_flag();
	void set_store_flag();
	
	
	
	int determine_type();
	InstructionAdd get_instruction_add();
	InstructionBeq get_instruction_beq();
	InstructionDiv get_instruction_div();
	InstructionJal get_instruction_jal();
	InstructionLoad get_instruction_load();
	InstructionStore get_instruction_store();
	
	int get_add_flag();
	int get_div_flag();
	int get_beq_flag();
	int get_jal_flag();
	int get_load_flag();
	int get_store_flag();
	
};
