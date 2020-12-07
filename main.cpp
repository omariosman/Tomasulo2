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
/*
void check_operands_ready(InstructionAdd *inst_add_arr,ReservationStation *rs_arr, map<string, string> &RegStats, map<string, int> &RegFile){
	//not ready
	if (RegStats[inst_add_arr->get_rs1_name()] != "0"){
			rs_arr->setQj(RegStats[inst_add_arr->get_rs1_name()]);
	
						
	//ready
	} else {
			rs_arr->setVj(RegFile[inst_add_arr->get_rs1_name()]);
			rs_arr->setQj("0");
			cout << "from inside: " << rs_arr->getVj() << endl;
			
	}
		

 }

*/

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




	map<string, string> RegStats;
	
    RegStats["r0"] = "0";
    RegStats["r1"] = "0";
    RegStats["r2"] = "0";
    RegStats["r3"] = "0";
    RegStats["r4"] = "0";
    RegStats["r5"] = "0";
    RegStats["r6"] = "0";
    RegStats["r7"] = "0";
    RegStats["r8"] = "0";
    RegStats["r9"] = "0";
    RegStats["r10"] = "0";
    RegStats["r11"] = "0";
    RegStats["r12"] = "0";
    RegStats["r13"] = "0";
    RegStats["r14"] = "0";
    RegStats["r15"] = "0";
    
    
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
		cout << "Me" << endl;
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
		   			inst.set_rs2(RegFile[my_inst[i][2]]);
		   			
		   			inst_arr[i] = inst;
		   			
		   			cout << "c: " << inst_counter << endl; 
		   			
		   		} 
		   	}
		   	inst_counter++;
		 
		   }
		   
		   
		   
		



        int main_clk = 1;
        ResStatHandler RS_handler;
        //Dynamic array for instruction objects
		ReservationStation *rs_arr;
		rs_arr = new ReservationStation[100];
		
		int very_temp = 2;
		int issue_counter = 0;
        while(true){
        	
        	//first step
        	
        	
        	//second step [issue a new instruction]
        	string my_type = inst_arr[issue_counter].get_type(); //check
        	
        	if (my_type == "add"){
        		//check reservation station
        		bool check_avail = RS_handler.is_add_available();
        		if (check_avail){
        			inst_arr[issue_counter].set_status(1);
        			inst_arr[issue_counter].set_issue_clk(main_clk);
        			RS_handler.decrementAdd(); //decrement add RS
        			issue_counter++;
        		}
        		
        		
        	} 
        	main_clk++;
        	very_temp--;
        	if (very_temp == 0){
        	
        		break;
        	}
        	
  
     
        
        
        
        }
        cout << "Y: " << inst_counter << endl;
        //test
        for (int i = 0; i < inst_counter; i++){
        cout << "here: " << endl;
        	inst_arr[i].print_info();
        }

        

 
}

