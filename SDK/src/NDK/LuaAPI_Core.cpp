// This file was automatically generated on 26 May 2014 at 01:05:31

#include <NDK/LuaAPI.hpp>
#include <Nazara/Core.hpp>
#include <Nazara/Lua/LuaClass.hpp>

#include <Nazara/Core/Hash/MD5.hpp>

namespace Ndk
{
	void LuaAPI::Register_Core(Nz::LuaInstance& instance)
	{
		/******************************** Nz::AbstractHash *******************************/
		Nz::LuaClass<Nz::AbstractHash> abstractHashClass("AbstractHash");

		abstractHashClass.SetMethod("__tostring",
			[](Nz::LuaInstance& lua, Nz::AbstractHash& hash) -> int
			{
				Nz::StringStream strStrm("Nz::AbstractHash(");

				strStrm << "Hash type: " << hash.GetHashName() << ", ";
				strStrm << "Digest size: " << hash.GetDigestLength() << ")";

				lua.PushString(strStrm);
				return 1;
			});

		abstractHashClass.SetMethod("Append", 
			[](Nz::LuaInstance& lua, Nz::AbstractHash& hash) -> int
			{
				size_t dataLength = 0;
				const Nz::UInt8* data = reinterpret_cast<const Nz::UInt8*>(lua.CheckString(1, &dataLength));

				hash.Append(data, dataLength);

				return 0;
			});

		abstractHashClass.SetMethod("Begin", &Nz::AbstractHash::Begin);

		abstractHashClass.SetMethod("End",
			[](Nz::LuaInstance& lua, Nz::AbstractHash& hash) -> int
			{
				Nz::ByteArray data(hash.End()); // Exceptions? What's the expected behavior of that method?

				lua.PushString(data.ToString());
				return 1;
			});

		abstractHashClass.SetMethod("GetDigestLength", &Nz::AbstractHash::GetDigestLength);
		abstractHashClass.SetMethod("GetHashName", 
			[](Nz::LuaInstance& lua, Nz::AbstractHash& hash) -> int
			{
				Nz::String hashName(hash.GetHashName());
				lua.PushString(hashName);
				return 1;
			});

		abstractHashClass.Register(instance);

		/********************************** Nz::HashMD5 **********************************/
		Nz::LuaClass<Nz::HashMD5> hashMD5Class("HashMD5");
		hashMD5Class.Inherit(abstractHashClass);

		hashMD5Class.SetConstructor(
			[](Nz::LuaInstance& lua) -> Nz::HashMD5*
		{
			if(std::min(lua.GetStackTop(), 1U) == 0)
				return new Nz::HashMD5();
			return nullptr;
		});

		hashMD5Class.Register(instance);

		/*********************************** Nz::Clock **********************************/
		Nz::LuaClass<Nz::Clock> clockClass("Clock");

		// Constructeur
		clockClass.SetConstructor([](Nz::LuaInstance& lua) -> Nz::Clock* {
			int index = 1;
			return new Nz::Clock(lua.Check<Nz::Int64>(&index, 0), lua.Check<bool>(&index, false));
		});

		clockClass.SetMethod("GetMicroseconds", &Nz::Clock::GetMicroseconds);
		clockClass.SetMethod("GetMilliseconds", &Nz::Clock::GetMilliseconds);
		clockClass.SetMethod("GetSeconds", &Nz::Clock::GetSeconds);
		clockClass.SetMethod("IsPaused", &Nz::Clock::IsPaused);
		clockClass.SetMethod("Pause", &Nz::Clock::Pause);
		clockClass.SetMethod("Restart", &Nz::Clock::Restart);
		clockClass.SetMethod("Unpause", &Nz::Clock::Unpause);

		// Nz::Clock::__tostring (Manual)
		clockClass.SetMethod("__tostring", [] (Nz::LuaInstance& lua, Nz::Clock& clock) -> int {
			Nz::StringStream stream("Clock(Elapsed: ");
			stream << clock.GetSeconds();
			stream << ", Paused: ";
			stream << clock.IsPaused();
			stream << ')';

			lua.PushString(stream);
			return 1;
		});


		clockClass.Register(instance);

		/********************************* Nz::Directory ********************************/
		Nz::LuaClass<Nz::Directory> directoryClass("Directory");

		// Constructeur
		directoryClass.SetConstructor([](Nz::LuaInstance& lua) -> Nz::Directory* {
			unsigned int argCount = std::min(lua.GetStackTop(), 1U);
			switch (argCount)
			{
				case 0:
				{
					return new Nz::Directory;
				}

				case 1:
				{
					int index = 1;
					return new Nz::Directory(lua.Check<Nz::String>(&index));
				}
			}

			return nullptr;
		});

		directoryClass.SetMethod("Close", &Nz::Directory::Close);
		directoryClass.SetMethod("Exists", &Nz::Directory::Exists);
		directoryClass.SetMethod("GetPath", &Nz::Directory::GetPath);
		directoryClass.SetMethod("GetPattern", &Nz::Directory::GetPattern);
		directoryClass.SetMethod("GetResultName", &Nz::Directory::GetResultName);
		directoryClass.SetMethod("GetResultPath", &Nz::Directory::GetResultPath);
		directoryClass.SetMethod("GetResultSize", &Nz::Directory::GetResultSize);
		directoryClass.SetMethod("IsOpen",  &Nz::Directory::IsOpen);
		directoryClass.SetMethod("IsResultDirectory",  &Nz::Directory::IsResultDirectory);
		directoryClass.SetMethod("NextResult", &Nz::Directory::NextResult, true);
		directoryClass.SetMethod("Open", &Nz::Directory::Open);
		directoryClass.SetMethod("SetPath", &Nz::Directory::SetPath);
		directoryClass.SetMethod("SetPattern", &Nz::Directory::SetPattern);

		directoryClass.SetStaticMethod("Copy", Nz::Directory::Copy);
		directoryClass.SetStaticMethod("Create", Nz::Directory::Create);
		directoryClass.SetStaticMethod("Exists", Nz::Directory::Exists);
		directoryClass.SetStaticMethod("GetCurrent", Nz::Directory::GetCurrent);
		directoryClass.SetStaticMethod("Remove", Nz::Directory::Remove);
		directoryClass.SetStaticMethod("SetCurrent", Nz::Directory::SetCurrent);

		// Nz::Directory::__tostring (Manual)
		directoryClass.SetMethod("__tostring", [] (Nz::LuaInstance& lua, Nz::Directory& directory) -> int {
			Nz::StringStream stream("Directory(");
			stream << directory.GetPath();
			stream << ')';

			lua.PushString(stream);
			return 1;
		});


		directoryClass.Register(instance);

		/*********************************** Nz::File ***********************************/
		Nz::LuaClass<Nz::File> fileClass("File");

		// Constructeur
		fileClass.SetConstructor([](Nz::LuaInstance& lua) -> Nz::File* {
			unsigned int argCount = std::min(lua.GetStackTop(), 2U);
			switch (argCount)
			{
				case 0:
				{
					return new Nz::File;
				}

				case 1:
				{
					Nz::String filePath(lua.CheckString(1));

					return new Nz::File(filePath);
				}

				case 2:
				{
					Nz::String filePath(lua.CheckString(1));
					unsigned long openMode(lua.CheckInteger(2));

					return new Nz::File(filePath, openMode);
				}
			}

			return nullptr;
		});

		fileClass.SetMethod("Close", &Nz::File::Close);
		fileClass.SetMethod("Copy", &Nz::File::Copy);
		fileClass.SetMethod("Delete", &Nz::File::Delete);
		fileClass.SetMethod("EndOfFile", &Nz::File::EndOfFile);
		fileClass.SetMethod("Exists", &Nz::File::Exists);
		fileClass.SetMethod("GetCreationTime", &Nz::File::GetCreationTime);
		fileClass.SetMethod("GetFileName", &Nz::File::GetFileName);
		fileClass.SetMethod("GetLastAccessTime", &Nz::File::GetLastAccessTime);
		fileClass.SetMethod("GetLastWriteTime", &Nz::File::GetLastWriteTime);
		fileClass.SetMethod("IsOpen", &Nz::File::IsOpen);
		fileClass.SetMethod("Rename", &Nz::File::GetLastWriteTime);
		fileClass.SetMethod("GetLastWriteTime", &Nz::File::GetLastWriteTime);
		fileClass.SetMethod("SetFile", &Nz::File::GetLastWriteTime);

		fileClass.SetMethod("Open", [] (Nz::LuaInstance& lua, Nz::File& file) -> int {
			unsigned int argCount = std::min(lua.GetStackTop(), 2U);
			switch (argCount)
			{
				case 0:
				{
					bool _ret = file.Open();

					lua.PushBoolean(_ret);
					return 1;
				}

				case 1:
				{
					if (lua.IsOfType(1, Nz::LuaType_Number))
					{
						unsigned long openMode(lua.ToInteger(1));

						bool _ret = file.Open(openMode);

						lua.PushBoolean(_ret);
						return 1;
					}
					else if (lua.IsOfType(1, Nz::LuaType_String))
					{
						Nz::String filePath(lua.ToString(1));

						bool _ret = file.Open(filePath);

						lua.PushBoolean(_ret);
						return 1;
					}
				}

				case 2:
				{
					Nz::String filePath(lua.CheckString(1));
					unsigned long openMode(lua.CheckInteger(2));

					bool _ret = file.Open(filePath, openMode);

					lua.PushBoolean(_ret);
					return 1;
				}
			}

			lua.Error("No matching overload for method Open");
			return 0;
		});

		fileClass.SetMethod("SetCursorPos", [] (Nz::LuaInstance& lua, Nz::File& file) -> int {
			unsigned int argCount = std::min(lua.GetStackTop(), 2U);
			switch (argCount)
			{
				case 1:
				{
					Nz::UInt64 offset(lua.CheckInteger(1));

					bool _ret = file.SetCursorPos(offset);

					lua.PushBoolean(_ret);
					return 1;
				}

				case 2:
				{
					Nz::CursorPosition pos(static_cast<Nz::CursorPosition>(lua.CheckInteger(1)));
					Nz::Int64 offset(lua.CheckInteger(2));

					bool _ret = file.SetCursorPos(pos, offset);

					lua.PushBoolean(_ret);
					return 1;
				}
			}

			lua.Error("No matching overload for method SetCursorPos");
			return 0;
		});

		// Nz::File::Read (Manual)
		fileClass.SetMethod("Read", [] (Nz::LuaInstance& lua, Nz::File& file) -> int {
			int length = lua.CheckInteger(1);
			lua.ArgCheck(length > 0, 1, "length must be positive");

			std::unique_ptr<char[]> buffer(new char[length]);
			std::size_t readLength = file.Read(buffer.get(), length);

			lua.PushString(Nz::String(buffer.get(), readLength));
			return 1;
		});

		// Nz::File::ReadLine (Manual)
		fileClass.SetMethod("ReadLine", [] (Nz::LuaInstance& lua, Nz::File& file) -> int {
			int length = lua.CheckInteger(1, 0);
			lua.PushString(file.ReadLine(length));
			return 1;
		});

		// Nz::File::__tostring (Manual)
		fileClass.SetMethod("__tostring", [] (Nz::LuaInstance& lua, Nz::File& file) -> int {
			Nz::StringStream stream("File(");
			if (file.IsOpen())
				stream << "Path: " << file.GetPath();

			stream << ')';

			lua.PushString(stream);
			return 1;
		});


		fileClass.Register(instance);

		// Énumérations de la classe Nz::File
		fileClass.PushGlobalTable(instance);

		// Nz::File::CursorPosition
		instance.SetField("AtBegin",   Nz::CursorPosition_AtBegin);
		instance.SetField("AtCurrent", Nz::CursorPosition_AtCurrent);
		instance.SetField("AtEnd",     Nz::CursorPosition_AtEnd);

		// Nz::File::OpenMode
		instance.SetField("Append",    Nz::OpenMode_Append);
		instance.SetField("NotOpen",   Nz::OpenMode_NotOpen);
		instance.SetField("Lock",      Nz::OpenMode_Lock);
		instance.SetField("ReadOnly",  Nz::OpenMode_ReadOnly);
		instance.SetField("ReadWrite", Nz::OpenMode_ReadWrite);
		instance.SetField("Text",      Nz::OpenMode_Text);
		instance.SetField("Truncate",  Nz::OpenMode_Truncate);
		instance.SetField("WriteOnly", Nz::OpenMode_WriteOnly);

		instance.Pop();
	}
}
