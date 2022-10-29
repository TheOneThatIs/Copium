#include "File.h"



namespace Copium {

	File::File(){}

	File::File(std::string filepath) : file(filepath, std::ios::in | std::ios::out) {
		
	}

	void File::Open(std::string filepath) {
		file.open(filepath, std::ios::in | std::ios::out);
	}

	void File::Close() {

	}

}