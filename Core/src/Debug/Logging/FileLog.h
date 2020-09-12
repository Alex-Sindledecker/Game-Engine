#pragma once

#include "LogTarget.h"

#include <fstream>

namespace Engine
{

	class ENGINE_API FileLog : public LogTarget
	{
	public:
		FileLog(std::string path, std::string name);
		virtual ~FileLog();

		const std::string getName() const;
		const std::string getPath() const;
		virtual void logError(const char* msg) override;
		virtual void logWarning(const char* msg) override;
		virtual void logMessage(const char* msg) override;

	private:
		std::ofstream mOut;
		std::string mPath, mName;
	};

}