// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_CORE_WIN32_THREADIMPL_HPP
#define NAZARA_CORE_WIN32_THREADIMPL_HPP

#include <NazaraUtils/Prerequisites.hpp>
#include <string>

// Try to identify MinGW thread flavor
#ifdef NAZARA_COMPILER_MINGW

#if defined(__USING_MCFGTHREAD__)
#define NAZARA_COMPILER_MINGW_THREADS_MCF
#elif defined(_REENTRANT)
#define NAZARA_COMPILER_MINGW_THREADS_POSIX
#else
#define NAZARA_COMPILER_MINGW_THREADS_WIN32
#endif

#endif

#ifdef NAZARA_COMPILER_MINGW_THREADS_POSIX
#include <pthread.h>
#else
#include <Windows.h>
#endif

namespace Nz::PlatformImpl
{
#ifdef NAZARA_COMPILER_MINGW_THREADS_POSIX
	using ThreadHandle = pthread_t;
#else
	using ThreadHandle = HANDLE;
#endif

	ThreadHandle GetCurrentThreadHandle();
	std::string GetCurrentThreadName();
	std::string GetThreadName(ThreadHandle threadHandle);
#ifndef NAZARA_COMPILER_MINGW
	void RaiseThreadNameException(DWORD threadId, const char* threadName);
#endif
	void SetCurrentThreadName(const char* threadName);
	void SetThreadName(ThreadHandle threadHandle, const char* threadName);
}

#endif // NAZARA_CORE_WIN32_THREADIMPL_HPP