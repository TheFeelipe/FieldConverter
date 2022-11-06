#include "pch.hpp"

void CConverter::ReadField()
{
	std::ifstream file{ "FieldScene2.bin", std::ios::in | std::ios::binary };

	if (!file.good())
	{
		throw std::exception("FieldScene2.bin not found!");
	}

	std::ofstream oFile{ "FieldScene.txt" };

	while (file.read(reinterpret_cast<char*>(&m_nType), sizeof(int32_t)))
	{
		auto find_map = m_MapName.find(m_nType);
		if (find_map == m_MapName.end())
		{
			std::cout << std::format("TYPE {} NOT FOUND!", m_nType);
			continue;
		}

		switch (m_nType)
		{
		case CONTROL_TYPE::CTRL_TYPE_PANEL:
		{
			auto binPanelData = ReadData<BinPanel>(file);
			if (!binPanelData)
			{
				std::cout << "Error for read [PANEL]\n";
				break;
			}

			m_stHeader = binPanelData->stHeader;
			this->SetText(binPanelData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_GRID:
		{
			auto binGridData = ReadData<BinGrid>(file);
			if (!binGridData)
			{
				std::cout << "Error for read [GRID]\n";
				break;
			}

			m_stHeader = binGridData->stHeader;
			this->SetText(binGridData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_BUTTON:
		{
			auto binButtonData = ReadData<BinButton>(file);
			if (!binButtonData)
			{
				std::cout << "Error for read [BUTTON]\n";
				break;
			}

			m_stHeader = binButtonData->stHeader;
			this->SetText(binButtonData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_TEXT:
		{
			auto binTextData = ReadData<BinText>(file);
			if (!binTextData)
			{
				std::cout << "Error for read [TEXT]\n";
				break;
			}

			m_stHeader = binTextData->stHeader;
			this->SetText(binTextData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_EDITABLETEXT:
		{
			auto binEditData = ReadData<BinEdit>(file);
			if (!binEditData)
			{
				std::cout << "Error for read [EDIT]\n";
				break;
			}

			m_stHeader = binEditData->stHeader;
			this->SetText(binEditData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_PROGRESSBAR:
		{
			auto binProgressData = ReadData<BinProgress>(file);
			if (!binProgressData)
			{
				std::cout << "Error for read [PROGRESS]\n";
				break;
			}

			m_stHeader = binProgressData->stHeader;
			this->SetText(binProgressData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_LISTBOX:
		{
			auto binListBoxData = ReadData<BinListBox>(file);
			if (!binListBoxData)
			{
				std::cout << "Error for read [LISTBOX]\n";
				break;
			}

			m_stHeader = binListBoxData->stHeader;
			this->SetText(binListBoxData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_CHECKBOX:
		{
			auto binCheckBoxData = ReadData<BinCheckBox>(file);
			if (!binCheckBoxData)
			{
				std::cout << "Error for read [CHECKBOX]\n";
				break;
			}

			m_stHeader = binCheckBoxData->stHeader;
			this->SetText(binCheckBoxData->GetText());

		}break;
		case CONTROL_TYPE::CTRL_TYPE_3DOBJ:
		{
			auto bin3DObjData = ReadData<Bin3DObj>(file);
			if (!bin3DObjData)
			{
				std::cout << "Error for read [3DOBJ]\n";
				break;
			}

			m_stHeader = bin3DObjData->stHeader;
			this->SetText(bin3DObjData->GetText());

		}break;
		}

		oFile << find_map->second << std::endl;
		oFile << m_stHeader.nID << std::endl;
		oFile << m_stHeader.nParentID << std::endl;
		oFile << this->GetText() << std::endl << std::endl;
	}

	file.close();
}

void CConverter::WriteField()
{
	std::ifstream file{ "FieldScene.txt" };
	std::ofstream oFile{ "FieldScene2.bin", std::ios::out | std::ios::binary };

	std::string sLine, sType;

	std::vector<std::string> v_ValidString =
	{
		"[PANEL]", "[TEXT]", "[BUTTON]", "[LISTBOX]",
		"[EDIT]", "[GRID]", "[PROGRESS]", "[CHECKBOX]", "[3DOBJ]"
	};

	while (std::getline(file, sLine))
	{
		if (sLine.empty() || sLine[0] == '#')
			continue;

		auto findValid = std::find(v_ValidString.begin(), v_ValidString.end(), sLine);

		if (findValid != v_ValidString.end())
		{
			sType = sLine;

			for (size_t i = 0; i < 3; ++i)
			{
				std::getline(file, sLine);

				if (i == 0)
				{
					sscanf_s(sLine.c_str(), "%d", &m_stHeader.nID);
				}
				else if (i == 1)
				{
					sscanf_s(sLine.c_str(), "%d", &m_stHeader.nParentID);
				}
			}
		}

		if (sType.contains("PANEL"))
		{
			auto data = GetData<BinPanel>(CONTROL_TYPE::CTRL_TYPE_PANEL);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("TEXT"))
		{
			auto data = GetData<BinText>(CONTROL_TYPE::CTRL_TYPE_TEXT);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("BUTTON"))
		{
			auto data = GetData<BinButton>(CONTROL_TYPE::CTRL_TYPE_BUTTON);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("LISTBOX"))
		{
			auto data = GetData<BinListBox>(CONTROL_TYPE::CTRL_TYPE_LISTBOX);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("EDIT"))
		{
			auto data = GetData<BinEdit>(CONTROL_TYPE::CTRL_TYPE_EDITABLETEXT);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("GRID"))
		{
			auto data = GetData<BinGrid>(CONTROL_TYPE::CTRL_TYPE_GRID);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("PROGRESS"))
		{
			auto data = GetData<BinProgress>(CONTROL_TYPE::CTRL_TYPE_PROGRESSBAR);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("CHECKBOX"))
		{
			auto data = GetData<BinCheckBox>(CONTROL_TYPE::CTRL_TYPE_CHECKBOX);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}

		else if (sType.contains("3DOBJ"))
		{
			auto data = GetData<Bin3DObj>(CONTROL_TYPE::CTRL_TYPE_3DOBJ);

			data->MakeData(sLine, m_stHeader);
			WriteData(data.get(), oFile);
		}
	}

	file.close();
}

void CConverter::SetText(const std::string& sText)
{
	this->m_Str = sText;
}

std::string CConverter::GetText()
{
	return this->m_Str;
}

CConverter::CConverter()
{
	m_nType = -1;
	m_stHeader = STRUCT_HEADER{};
	m_Str.clear();
}

CConverter::~CConverter()
{
}

void CConverter::Start()
{
	std::string sType, sLast;

	auto ClearConsole = []()
	{
		std::cout << "\x1B[2J\x1B[H";
	};

	auto PrintConsole = [=](std::string& str)
	{
		ClearConsole();

		if (!str.empty())
			std::cout << "LAST CONVERTION: " << str << std::endl << std::endl;

		std::cout << "1: BIN -> TXT" << std::endl;
		std::cout << "2: TXT -> BIN" << std::endl;
		std::cout << "3: EXIT" << std::endl << std::endl;
	};

	while (true)
	{
		PrintConsole(sLast);

		std::cin >> sType;

		if (sType == "3")
			break;

		try
		{

			if (sType == "1")
			{
				CConverter::ReadField();
				sLast = "[BIN -> TXT]";
			}
			else if (sType == "2")
			{
				CConverter::WriteField();
				sLast = "[TXT -> BIN]";
			}
		}

		catch (std::exception& e)
		{
			ClearConsole();
			std::cout << e.what() << std::endl;
			break;
		}
	}
}