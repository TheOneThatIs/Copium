#pragma once
#include "CopiumIO/File.h"
#include <string>

namespace Copium {
class Shader {
private:
	File file;
public:
	Shader(std::string filepath);
};
}