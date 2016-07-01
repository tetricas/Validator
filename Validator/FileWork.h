#pragma once

class FileWork
{
	LPCWCHAR path;
	std::vector<std::wstring > allFullPathes, allContent;

public:
	FileWork() {};
	void ChangePath(LPCWCHAR);
	void AddPathes();
	std::wstring GetStrPathes();
	std::vector<std::wstring > GetVectorOfPathes();
	void GetContent();
	std::vector<std::wstring > GetContentVector();
	~FileWork();
};

