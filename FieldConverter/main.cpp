#include "pch.hpp"

void InitializeModuleDir()
{
	char String[256];
	GetModuleFileName(NULL, String, 256);

	size_t len = strlen(String) - 1;
	for (size_t i = len; i > 0; --i)
	{
		if (String[i] == '\\')
		{
			String[i] = 0;
			break;
		}
	}

	SetCurrentDirectory(String);
}

int main()
{
	InitializeModuleDir();

	auto pConverter = std::make_unique<CConverter>();
	pConverter->Start();

	return 1;
}
