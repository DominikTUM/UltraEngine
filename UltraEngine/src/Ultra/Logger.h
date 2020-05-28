#pragma once

#include <ostream>
#include <iostream>

#define LOG(t, msg) (Ultra::Logger::log(t, std::cerr, __FILE__, __LINE__, __FUNCTION__, msg))

#define LOG_I(msg) LOG(Ultra::Logger::Type::Info, msg)
#define LOG_W(msg) LOG(Ultra::Logger::Type::Warning, msg)
#define LOG_E(msg) LOG(Ultra::Logger::Type::Error, msg)

#define ASSERT(expr) { if(!(expr)) { LOG_E(std::string("assertion failed: ") + (#expr)); } }

namespace Ultra {
	namespace Logger {
		enum Type {
			Info,
			Warning, 
			Error
		};

		/*
		 * Logging function
		 * @param typ the severity of the logging
		 * @param out a ostream to write the message
		 * @param file file on which the logging occured
		 * @param line the line of the log
		 * @param function the function in which the logging occured
		 * @param message the message to be logged
		 */
		void log(Type typ, std::ostream& out, const char* file, int line, const char* function, const char* message) {
			const char* tStr = ([typ]() {
				switch (typ) {
				case Info: return "INFO";
				case Warning: return "WARNING";
				case Error: return  "ERROR";
				default: return "";
				}
			})();

			out << "[" << tStr << "] In file " << file << " at " << line << " in " << function << ": " << message <<  std::endl;
		}
	}
}