#include "General.h"

static HMODULE ourModule;

std::string Utility::GetFilename( std::string filename )
{
	size_t lastIndex = filename.find_last_of("\\") + 1;
	return filename.substr(lastIndex, filename.length() - lastIndex);
}

std::string Utility::GetFilenameWithoutExtension( std::string filename )
{
	size_t lastIndex = filename.find_last_of(".");
	if (lastIndex == -1) {
		return filename;
	}

	return filename.substr(0, lastIndex);
}

std::string Utility::GetRunningExecutableFolder() {

	char fileName[MAX_PATH];
	GetModuleFileNameA( NULL, fileName, MAX_PATH );

	std::string currentPath = fileName;
	return currentPath.substr( 0, currentPath.find_last_of( "\\" ) );
}

std::string Utility::GetOurModuleFolder() {

	char fileName[MAX_PATH];
	GetModuleFileNameA( ourModule, fileName, MAX_PATH );

	std::string currentPath = fileName;
	return currentPath.substr( 0, currentPath.find_last_of( "\\" ) );
}

std::string Utility::GetModuleFullName(const HMODULE module) {

	char fileName[MAX_PATH];
	GetModuleFileNameA(module, fileName, MAX_PATH);
	return fileName;
}

std::string Utility::GetModuleName(const HMODULE module) {

	return GetFilename(GetModuleFullName(module));
}

std::string Utility::GetModuleNameWithoutExtension( const HMODULE module ) {

	const std::string fileNameWithExtension = GetModuleName(module);
	return GetFilenameWithoutExtension(fileNameWithExtension);
}

void Utility::SetOurModuleHandle( const HMODULE module ) {

	ourModule = module;
}

HMODULE Utility::GetOurModuleHandle() {

	return ourModule;
}

std::wstring Utility::str_to_wstr(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

std::string Utility::wstr_to_str(const std::wstring& wstr)
{
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string strTo(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}
