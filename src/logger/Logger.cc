// Logger.cc
#include "logger/Logger.h"
#include <cstdlib>
#include <filesystem>
#include <mutex>

namespace fs = std::filesystem;
static std::mutex mu;   // engine threads will call this concurrently

Logger::Logger() {
	const char* home = std::getenv("HOME");
	fs::path dir = fs::path(home ? home : ".") / ".Moonshine";
	std::error_code ec;
	fs::create_directories(dir, ec);
	out.open(dir / "log.txt", std::ios::app);
}

void Logger::Log(const std::string& text) {
	std::lock_guard<std::mutex> lock(mu);
	if (out) out << text << '\n' << std::flush;   // flush so a crash doesn't lose lines
}
