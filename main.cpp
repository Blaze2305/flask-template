#include <iostream>
#include <filesystem>

#include "src/generate/generate.h"


int main(int argc, char *argv[]){
	if(argc < 2){
		std::cout<<"Missing Project Name\n\n";
		return 1;
	}

	bool exists = std::filesystem::exists(argv[1]);
	if(exists){
		std::cout<<"PROJECT ALREADY EXISTS\n"<<std::endl;
		return 0;
	}

	generateFolders(argv[1]);
	generateFiles(argv[1]);
}