#pragma once
#include <string>
#include <fstream>

namespace Big
{
	class LogFile
	{
	public:
		LogFile();
		~LogFile();

		enum LogType 
		{
			Info = 0,
			Warning,
			Error
		};

		bool Create(const std::string& filename, bool doSupressFileOutput = false, bool doLogTimeStamps = true);
		void Destroy();

		void DoLog(const std::string& message, LogType logType = Info);

	private:
		LogFile(const LogFile& logFile);
		LogFile& operator= (const LogFile& log) {};


		std::string uri;
		bool supressFileOutput = false;
		bool logTimeStamps = true;

		std::ofstream filestream;
	};
}
