#include "stdafx.h"
#include "FileWork.h"

void FileWork::ChangePath(LPCWCHAR str)
{
	path = str;
}

void FileWork::AddPathes()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	hFind = FindFirstFile(path, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			std::wstring tempPath = path;
			tempPath = tempPath.substr(0, tempPath.length() - 6);
			tempPath += FindFileData.cFileName;
			allFullPathes.push_back(tempPath);
		} while (FindNextFile(hFind, &FindFileData));
		FindClose(hFind);
	}
}

std::wstring FileWork::GetStrPathes()
{
	std::wstring df = L"";
	for (auto i : allFullPathes)
		df = df + i + L'\n';

	return df;
}

std::vector<std::wstring> FileWork::GetVectorOfPathes()
{
	return allFullPathes;
}

void FileWork::GetContent()
{
	int length;
	char *buffer;
	for (auto i : allFullPathes)
	{
		std::ifstream iFile(i);
		iFile.seekg(0, iFile.end);
		length = iFile.tellg();
		iFile.seekg(0, iFile.beg);

		// allocate memory:
		buffer = new char[length];

		// read data as a block:
		iFile.read(buffer, length);
		std::string s(buffer);
		std::wstring ws(s.begin(), s.end());
		allContent.push_back(ws);

		iFile.close();
	}
}

std::vector<std::wstring> FileWork::GetContentVector()
{
	return allContent;
}

FileWork::~FileWork()
{
	path = NULL;
}
