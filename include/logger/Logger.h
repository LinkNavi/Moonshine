// Logger.h
#pragma once
#include <fstream>
#include <string>

class Logger {
public:
	Logger();
	void Log(const std::string& text);
private:
	std::ofstream out;
};
