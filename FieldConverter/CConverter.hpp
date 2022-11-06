#pragma once

#include "Structs.hpp"

class CConverter
{
private:
	static const inline std::map<int32_t, std::string> m_MapName =
	{
		{ CONTROL_TYPE::CTRL_TYPE_PANEL, "[PANEL]" },
		{ CONTROL_TYPE::CTRL_TYPE_GRID, "[GRID]" },
		{ CONTROL_TYPE::CTRL_TYPE_BUTTON, "[BUTTON]" },
		{ CONTROL_TYPE::CTRL_TYPE_TEXT, "[TEXT]" },
		{ CONTROL_TYPE::CTRL_TYPE_EDITABLETEXT, "[EDIT]" },
		{ CONTROL_TYPE::CTRL_TYPE_PROGRESSBAR, "[PROGRESS]" },
		{ CONTROL_TYPE::CTRL_TYPE_LISTBOX, "[LISTBOX]" },
		{ CONTROL_TYPE::CTRL_TYPE_CHECKBOX, "[CHECKBOX]" },
		{ CONTROL_TYPE::CTRL_TYPE_3DOBJ, "[3DOBJ]" }
	};

	std::string m_Str;
	int32_t m_nType;
	STRUCT_HEADER m_stHeader;

public:

	CConverter();
	~CConverter();

	void Start();
	void ReadField();
	void WriteField();
	void SetText(const std::string& sText);
	std::string GetText();

	template <typename T>
	std::unique_ptr<T> GetData(int32_t nType)
	{
		auto pData = std::make_unique<T>();

		m_nType = nType;
		return pData;
	}

	template <typename T>
	std::unique_ptr<T> ReadData(std::ifstream& file) const
	{
		auto data = std::make_unique<T>();

		if (!file.read(reinterpret_cast<char*>(data.get()), sizeof(T)))
		{
			data.release();
		}

		return data;
	}

	template <typename T>
	void WriteData(T data, std::ofstream& outFile)
	{
		outFile.write(reinterpret_cast<char*>(&m_nType), 4);
		outFile.write(reinterpret_cast<const char*>(data), sizeof(*data));
	}
};

