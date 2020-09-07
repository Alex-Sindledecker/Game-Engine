#pragma once

#include "Debug.h"

namespace Engine
{

	class ENGINE_API DebugConsole : public LogTarget
	{
	public:
		virtual const char* getName() override;
		virtual LogTarget* getHandle() override;
		virtual void logError(const char* msg) override;
		virtual void logWarning(const char* msg) override;
		virtual void logMessage(const char* msg) override;

		static DebugConsole& getInstance();

		DebugConsole(const DebugConsole&) = delete;
		void operator=(const DebugConsole&) = delete;

	private:
		DebugConsole() {}

		static void log(const char* msg);
		static void setTextColor(int color);
	};

}