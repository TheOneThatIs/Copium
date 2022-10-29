#pragma once

#include <fstream>
#include <iostream>
#include <string>

namespace Copium {
class File {
private:
	std::fstream file;
	std::string data;

public:
	File();
	File(std::string filepath);

	void Open(std::string filepath);
	void Close();
};
}