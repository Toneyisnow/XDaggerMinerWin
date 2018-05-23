#pragma once

#include <ctime>
#include <sstream>

#include "stdafx.h"


#ifdef RUNTIME_EXPORTS
#define NATIVE_LIB_EXPORT __declspec(dllexport)
#else
#define NATIVE_LIB_EXPORT __declspec(dllimport)
#endif

namespace XDaggerMinerRuntime
{
	class NATIVE_LIB_EXPORT Runtime {
	public:
		Runtime();

		int getDevices();

		int getValue();

	private:
		int m_value;
	};

}


class NATIVE_LIB_EXPORT MyNativeClass {
public:
	MyNativeClass(int val)
	{
		this->m_value = val;
	}

	int getValue() const
	{
		return m_value;
	}

private:
	int m_value;
};





#define DLLEXP   __declspec( dllexport )
DLLEXP void pop_back(std::string& str);
DLLEXP std::string testReturnString();
DLLEXP int getRandomNumber();




// This is our native implementation
// It's marked with __declspec(dllexport) 
// to be visible from outside the DLL boundaries
class __declspec(dllexport) HelloLogic
{
public:
	int Get() const
	{
		return 55;
	}
};


extern "C"
{
	__declspec(dllexport) void HelloWorld()
	{
		std::stringstream _sstr;

		_sstr << "HelloWorld from DLL!";
	}
	__declspec(dllexport) void ShowMe()
	{
		
	}
}


namespace XDag
{
	class SampleLogic
	{
	public:
		int Get()
		{
			return 33;
		}
	};


	/// The null output stream. Used when logging is disabled.
	class NullOutputStream
	{
	public:
		template <class T> NullOutputStream& operator<<(T const&) { return *this; }
	};

	/// A simple log-output function that prints log messages to stdout.
	void SimpleDebugOut(std::string const&);

	/// The logging system's current verbosity.
	extern int g_logVerbosity;

	class ThreadContext
	{
	public:
		ThreadContext(std::string const& _info) { push(_info); }
		~ThreadContext() { pop(); }

		static void push(std::string const& _n);
		static void pop();
		static std::string join(std::string const& _prior);
	};

	/// Set the current thread's log name.
	void SetThreadName(char const* _n);

	/// Get the current thread's log name.
	std::string GetThreadName();

	/// The default logging channels. Each has an associated verbosity and three-letter prefix (name() ).
	/// Channels should inherit from LogChannel and define name() and verbosity.
	struct LogChannel { static const char* name(); static const int verbosity = 1; static const bool debug = true; };
	struct LeftChannel : public LogChannel { static const char* name(); };
	struct RightChannel : public LogChannel { static const char* name(); };
	struct WarnChannel : public LogChannel { static const char* name(); static const int verbosity = 0; static const bool debug = false; };
	struct NoteChannel : public LogChannel { static const char* name(); static const bool debug = false; };
	struct DebugChannel : public LogChannel { static const char* name(); static const int verbosity = 0; };

	enum class LogTag
	{
		None,
		Url,
		Error,
		Special
	};

#define cdebug clog(XDag::DebugChannel)
#define cnote clog(XDag::NoteChannel)
#define cwarn clog(XDag::WarnChannel)

	// Null stream-like objects.
#define ndebug if (true) {} else XDag::NullOutputStream()
#define nlog(X) if (true) {} else XDag::NullOutputStream()
#define nslog(X) if (true) {} else XDag::NullOutputStream()

}
