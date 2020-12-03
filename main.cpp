#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include "InstructionAdd.h"
#include "InstructionDiv.h"
#include "InstructionBeq.h"
#include "InstructionJal.h"
#include "InstructionLoad.h"
#include "InstructionStore.h"
#include "ResStatHandler.h"
#include "ReservationStation.h"

using namespace std;



// int issue(ReservationStation object){
//     if()
//     //comdition for FP
//     if(){

//     }
//     //condition for Lw
//     if(){

//     }
//     //condition for Sw
//     if(){

//     }
//     //at the end return clk
// };


// int execute(){
//     //condition for FP
//     if(){
        
//     }
//     //condition for Lw
//     if(){

//     }
//     //condition for Sw
//     if(){

//     }
//     //return clk
// };

// int writeBack(){
//     //condition for FP and lw
//     if(){

//     }
//     //condition for Sw 
//     if(){

//     }
//     //return clk
// };



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
		  
		//   for (int i = 0; i < my_inst.size(); i++){
		//   	for (int j = 0; j < my_inst[i].size(); j++) {
		//   		cout << my_inst[i][j] << " ";
		//   	}
		//   	cout << endl;
		//   }
		

		//Dynamic array for instruction objects
		InstructionAdd *inst_add_arr;
		inst_add_arr = new InstructionAdd[100];
		
		
		int inst_add_counter = 0;
        for (int i = 0; i < my_inst.size(); i++){
        	if(inst_type[my_inst[i][0]] == 0){ //add
        		//call opbject of add instruction
        		InstructionAdd addInst;
        		string name = my_inst[i][0];
        		addInst.set_name(name);
        		
        		//add rd rs1 rs2
        		string rd = my_inst[i][1]; //rd
        		int rd_val = RegFile[rd];
        		addInst.set_rd(rd_val);
        		
        		string rs1 = my_inst[i][2]; //rs1
        		int rs1_val = RegFile[rs1];
        		addInst.set_rs1(rs1_val);
        		
        		string rs2 = my_inst[i][3]; //rs2
        		int rs2_val = RegFile[rs2];
        		addInst.set_rs2(rs2_val);        		
        		
        		//append the instruction object to an array
        		inst_add_arr[inst_add_counter] = addInst;
        		inst_add_counter++;
        		
        	}
        }
        //printing info of 
        /*
        for (int i = 0; i < inst_add_counter; i++){
        	cout << "name: " << inst_add_arr[i].get_name() << endl;
        	cout << "rd: " << inst_add_arr[i].get_rd() << endl;
        	cout << "rs1: " << inst_add_arr[i].get_rs1() << endl;
        	cout << "rs2: " << inst_add_arr[i].get_rs2() << endl;
        	cout << "Next Instruction" << endl;
       
        }
        */
        int main_clk = 0;
        ResStatHandler RS_handler();
        
        while(true){
        	/*
        	//inner loop
        		First step
        		check instructions status
        	*/
        	
        	for(int i = 0; i < inst_add_counter; i++){
        		int current_status = inst_add_arr[i].get_status();
        		
        		//before issue
        		if (current_status == 0){
        			//check issue conditions
        			//Empty RS
        			bool add_avail = RS_handler.is_add_available();
        			if (add_avail) {
        				inst_add-arr[i].set_status(1); //issue
        				inst_add-arr[i].set_issue_clk(main_clk);
        			} else {
        			
        			}
        		}
        	}
        	
        	/*
        		Second Step
        		check issue condition for a new instruction
        	*/
        	main_clk++;
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
      
 
 
}

