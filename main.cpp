#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include "Instruction.h"
#include "ResStatHandler.h"
#include "ReservationStation.h"

#include "GeneralInstruction.h"



using namespace std;




/*
	Function: Check operands ready
	Issue FP
*/

//needs to be completed witih Qk and Vk
void check_operands_ready(Instruction &inst_arr,ReservationStation &rs_arr, map<string, int> &RegStats, map<string, int> &RegFile){
	//j not ready
	if (RegStats[inst_arr.get_rs1_name()] != -1){ //-1 means that the regstats not available
			rs_arr.setQj(RegStats[inst_arr.get_rs1_name()]);
	
						
	//j ready
	} else {
			rs_arr.setVj(RegFile[inst_arr.get_rs1_name()]);
			rs_arr.setQj(-1);
			
			
	}
	
	//k not ready
	if (RegStats[inst_arr.get_rs2_name()] != -1){
			rs_arr.setQk(RegStats[inst_arr.get_rs2_name()]);
	
						
	//k ready
	} else {
			rs_arr.setVk(RegFile[inst_arr.get_rs2_name()]);
			rs_arr.setQk(-1);
			
			
	}
	
	
		

 }



int main(int argC, char **argv) {
    ResStatHandler object();
    ReservationStation load1;
    ReservationStation load2;
    ReservationStation store1;
    ReservationStation store2;
    ReservationStation branch;
    ReservationStation jal;
    ReservationStation add1;
    ReservationStation add2;
    ReservationStation div;




	map<string, int> RegStats;
	
    RegStats["r0"] = -1;
    RegStats["r1"] = -1;
    RegStats["r2"] = -1;
    RegStats["r3"] = -1;
    RegStats["r4"] = -1;
    RegStats["r5"] = -1;
    RegStats["r6"] = -1;
    RegStats["r7"] = -1;
    RegStats["r8"] = -1;
    RegStats["r9"] = -1;
    RegStats["r10"] = -1;
    RegStats["r11"] = -1;
    RegStats["r12"] = -1;
    RegStats["r13"] = -1;
    RegStats["r14"] = -1;
    RegStats["r15"] = -1;
    
    
    map<string, int> RegFile;
    
    RegFile["r0"] = 0;
    RegFile["r1"] = 1;
    RegFile["r2"] = 2;
    RegFile["r3"] = 3;
    RegFile["r4"] = 4;
    RegFile["r5"] = 0;
    RegFile["r6"] = 0;
    RegFile["r7"] = 0;
    RegFile["r8"] = 0;
    RegFile["r9"] = 0;
    RegFile["r10"] = 0;
    RegFile["r11"] = 0;
    RegFile["r12"] = 0;
    RegFile["r13"] = 0;
    RegFile["r14"] = 0;
    RegFile["r15"] = 0;
    
    map<string, int> inst_type;     //map for the instruction types to a number
    inst_type["add"] = 0;
    inst_type["neg"] = 0;
    inst_type["addi"] = 0;
    inst_type["div"] = 1;
    inst_type["jalr"] = 2;
    inst_type["ret"] = 2;
    inst_type["beq"] = 3;
    inst_type["lw"] = 4;
    inst_type["sw"] = 5;





	//map a counter to a general instruction
	map<int, GeneralInstruction> general_inst_map;



	vector <vector <string> > my_inst;
  		 ifstream instruction_file; //keywords
			instruction_file.open(argv[1]);
		  while (instruction_file)
		  {
			string s;
			if (!getline( instruction_file, s )) break;

			stringstream ss(s);
			vector <string> inst_params;

			while (ss)
			{
			  string s;
			  if (!getline( ss, s, ' ' )) break;
			  inst_params.push_back(s);
			}

			my_inst.push_back(inst_params);
		  }
		  if (!instruction_file.eof())
		  {
			cerr << "\n";
		  }
	
		  
		  
		//Dynamic array for instruction objects
		Instruction *inst_arr;
		inst_arr = new Instruction[100];
		int inst_counter = 0; 
		  //Loop to instantiate object for every instruction
		  
		for (int i = 0; i < my_inst.size(); i++){
		   	for (int j = 0; j < my_inst[i].size(); j++) {
		   		Instruction inst = Instruction();
		   		inst.set_type(my_inst[i][0]);
		   		if (inst.get_type() == "add"){
		   			
		   			//set rd
		   			inst.set_rd_name(my_inst[i][1]);
		   			inst.set_rd(RegFile[my_inst[i][1]]);
		   			
		   			//set rs1
		   			inst.set_rs1_name(my_inst[i][2]);
		   			inst.set_rs1(RegFile[my_inst[i][2]]);
		   			
		   			//set rs2
		   			inst.set_rs2_name(my_inst[i][3]);
		   			inst.set_rs2(RegFile[my_inst[i][3]]);
		   			
		   			inst.set_execution_cycles(2);
		   			inst.set_execution_counter(2);
		   			inst_arr[i] = inst;
		   			
		   		
		   			
		   		} 
		   	}
		   	inst_counter++;
		 
		   }
		   
		   
		   
		   		  
		//Dynamic array for instruction objects
		Instruction *backend;
		backend = new Instruction[100];
		   
		



        int main_clk = 1;
        ResStatHandler RS_handler;
        //Dynamic array for instruction objects
		ReservationStation *rs_arr;
		rs_arr = new ReservationStation[100];
		
		int very_temp = 10;
		int issue_counter = 0;
		int backend_size = 0;
		int while_counter = my_inst.size() + 6;
        while(true){
        	//first step
        	
        	for (int i = 0; i < backend_size; i++){
        	
        		
        		//check type of instruction

        		if (backend[i].get_status() == 1){
        		
        			//before execute
        			
        			if (backend[i].get_type() == "add"){
        			
        				
        				if (rs_arr[backend[i].get_rs_id()].getQj() == -1 && rs_arr[backend[i].get_rs_id()].getQk() == -1){
        					
        				
        					backend[i].set_status(2); //executing
        					backend[i].set_start_execute_clk(main_clk);
        					backend[i].set_end_execute_clk(main_clk + backend[i].get_execution_cycles() - 1);
        					backend[i].set_rd(backend[i].get_rs1() + backend[i].get_rs2());
						RegFile[backend[i].get_rd_name()] = backend[i].get_rd();
        				
        					
        				}	
        			
        			}
        			//executing stage
        		} else if (backend[i].get_status() == 2) {
        			backend[i].decrement_execution_counter(); //decrement execution cycles
        			if (backend[i].get_execution_counter() == 0){
        			//finish executing
        				
        				backend[i].set_status(3);
        			
        				
        			}
        			//write stage
        		} else if (backend[i].get_status() == 3){
        			backend[i].set_write_cycle(main_clk - 1);
        			RS_handler.incrementAdd();
        			RegFile[backend[i].get_rd_name()] = backend[i].get_rd();
        			RegStats[backend[i].get_rd_name()] = -1;
        			backend[i].set_status(4);
        			for (int k = 0; k < backend_size; k++){
        				if (rs_arr[backend[k].get_rs_id()].getQj()== backend[i].get_rs_id()) {
        					
        					rs_arr[backend[k].get_rs_id()].setVj(backend[i].get_rd());
        					rs_arr[backend[k].get_rs_id()].setQj(-1);
        					
        					
        				}
        				
        				if (rs_arr[backend[k].get_rs_id()].getQk() == backend[i].get_rs_id()) {
        					rs_arr[backend[k].get_rs_id()].setVk(backend[i].get_rd());
        					rs_arr[backend[k].get_rs_id()].setQk(-1);
        				
        				}       				
        			}
        			
        		}
        	}
        	bool cont_flag = false; //false means will break infinite loop
        	//logic to break infinte loop
        	if (backend_size == 0) {
        		cont_flag = true; //special case for first time
        	}
        	
        	for (int i = 0; i < backend_size; i++){

        		if (backend[i].get_write_cycle() == 0){
        			cont_flag = true;
        		}
        	}
        	
        	
        	
        	//second step [issue a new instruction]
        	string my_type = inst_arr[issue_counter].get_type(); //check
        
        	if (my_type == "add"){
        		//check reservation station
        		bool check_avail = RS_handler.is_add_available();
        		if (check_avail){
        			inst_arr[issue_counter].set_status(1);
        			inst_arr[issue_counter].set_issue_clk(main_clk);
  
        			RS_handler.decrementAdd(); //decrement add RS
        			
        			ReservationStation rs = ReservationStation();
        			rs_arr[issue_counter] = rs;
        			inst_arr[issue_counter].set_rs_id(issue_counter);
        			backend[issue_counter] = inst_arr[issue_counter]; //append the issued instrucion to the backend array
        			backend_size++;
        	
        			//check operand ready and o some creepy things after issuing
        			
        			check_operands_ready(inst_arr[issue_counter], rs_arr[issue_counter], RegStats,RegFile);
        			
        			RegStats[backend[issue_counter].get_rd_name()] = backend[issue_counter].get_rs_id();
        			issue_counter++;
        		}
        		
        		
        	} 
        	main_clk++;
        	while_counter--;
        	very_temp--;
        	
        	if (!cont_flag){
        	
        		break;
        	}
        	
  
        
        }
        
        //test
        for (int i = 0; i < backend_size; i++){
        cout << "Instruction: " << i + 1 << endl;
        	backend[i].print_info();
        	cout << endl;
        }

        

 
}

