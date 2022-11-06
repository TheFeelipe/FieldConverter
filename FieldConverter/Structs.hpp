#pragma once

enum CONTROL_TYPE : int32_t
{
	CTRL_TYPE_NONE = -1,
	CTRL_TYPE_CURSOR = 0,
	CTRL_TYPE_PANEL = 1,
	CTRL_TYPE_BUTTON = 2,
	CTRL_TYPE_CHECKBOX = 3,
	CTRL_TYPE_RADIOBUTTON = 4,
	CTRL_TYPE_RADIOBUTTONSET = 5,
	CTRL_TYPE_LISTBOX = 6,
	CTRL_TYPE_LISTBOXITEM = 7,
	CTRL_TYPE_MESSAGEBOX = 8,
	CTRL_TYPE_MESSAGEPANEL = 9,
	CTRL_TYPE_PROGRESSBAR = 10,
	CTRL_TYPE_SCROLLBAR = 11,
	CTRL_TYPE_TEXT = 12,
	CTRL_TYPE_EDITABLETEXT = 13,
	CTRL_TYPE_DIALOG = 14,
	CTRL_TYPE_3DOBJ = 15,
	CTRL_TYPE_GRID = 16,
};

struct STRUCT_HEADER
{
	int32_t nID;
	int32_t nParentID;
};

struct BinCheckBox
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nColor;

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{:X}",
			nTextureSetIndex,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			(unsigned)nColor);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%x",
			&nTextureSetIndex, &nStartX, &nStartY, &nWidth, &nHeight, &nColor);
	}
};

struct BinListBox
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nMaxCount;
	int32_t nVisibleCount;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nColor;
	int32_t nFillType;
	int32_t nSelect;
	int32_t nScroll;

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{},{},{:X},{},{},{}",
			nTextureSetIndex,
			nMaxCount,
			nVisibleCount,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			(unsigned)nColor,
			nFillType,
			nSelect,
			nScroll);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%d,%d,%x,%d,%d,%d",
			&nTextureSetIndex, &nMaxCount, &nVisibleCount, &nStartX, &nStartY,
			&nWidth, &nHeight, &nColor, &nFillType, &nSelect, &nScroll);
	}
};

struct BinGrid
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nRowCount;
	int32_t nColumnCount;
	int32_t nType;

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{},{},{}",
			nTextureSetIndex,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			nRowCount,
			nColumnCount,
			nType);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d",
			&nTextureSetIndex, &nStartX, &nStartY, &nWidth, &nHeight,
			&nRowCount, &nColumnCount, &nType);
	}
};

struct BinPanel
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nColor;
	int32_t nFillType;
	int32_t nPickable;

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{:X},{},{}",
			nTextureSetIndex,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			(unsigned)nColor,
			nFillType,
			nPickable);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%x,%d,%d,",
			&nTextureSetIndex, &nStartX, &nStartY, &nWidth, &nHeight, &nColor, &nFillType, &nPickable);
	}
};

struct Bin3DObj
{
	STRUCT_HEADER stHeader;
	int32_t n3DObjIndex;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;

	std::string GetText()
	{
		return std::format("{},{},{},{},{}",
			n3DObjIndex,
			nStartX,
			nStartY,
			nWidth,
			nHeight);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER &header)
	{
		stHeader = header;

		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d",
			&n3DObjIndex, &nStartX, &nStartY, &nWidth, &nHeight);
	}
};

struct BinButton
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nColor;
	int32_t nSound;
	int32_t nStringIndex;

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{:X},{},{}",
			nTextureSetIndex,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			(unsigned)nColor,
			nSound,
			nStringIndex);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%x,%d,%d",
			&nTextureSetIndex, &nStartX, &nStartY, &nWidth, &nHeight,
			&nColor, &nSound, &nStringIndex);
	}
};

struct BinText
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nFontColor;
	int32_t nBorder;
	int32_t nBorderColor;
	int32_t nTextType;
	int32_t nAlignType;
	int32_t nStringIndex;

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{:X},{},{:X},{},{},{}",
			nTextureSetIndex,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			(unsigned)nFontColor,
			nBorder,
			(unsigned)nBorderColor,
			nTextType,
			nAlignType,
			nStringIndex);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%x,%d,%x,%d,%d,%d",
			&nTextureSetIndex, &nStartX, &nStartY, &nWidth, &nHeight,
			&nFontColor, &nBorder, &nBorderColor,
			&nTextType, &nAlignType, &nStringIndex);
	}
};

struct BinEdit
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nFontColor;
	int32_t nBorder;
	int32_t nBorderColor;
	int32_t nTextType;
	int32_t nAlignType;
	int32_t nMaxStringLength;
	int32_t nPassword;
	char szString[128];

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{:X},{},{:X},{},{},{},{},{}",
			nTextureSetIndex,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			(unsigned)nFontColor,
			nBorder,
			(unsigned)nBorderColor,
			nTextType,
			nAlignType,
			nMaxStringLength,
			nPassword,
			szString);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%x,%d,%x,%d,%d,%d,%d,%s",
			&nTextureSetIndex, &nStartX, &nStartY, &nWidth, &nHeight,
			&nFontColor, &nBorder, &nBorderColor, &nTextType, &nAlignType,
			&nMaxStringLength, &nPassword, &szString, 128);
	}
};

struct BinProgress
{
	STRUCT_HEADER stHeader;
	int32_t nTextureSetIndex;
	int32_t nCurrent;
	int32_t nMaxValue;
	int32_t nStartX;
	int32_t nStartY;
	int32_t nWidth;
	int32_t nHeight;
	int32_t nProgressColor;
	int32_t nColor;
	int32_t nStyle;

	std::string GetText()
	{
		return std::format("{},{},{},{},{},{},{},{:X},{:X},{}",
			nTextureSetIndex,
			nCurrent,
			nMaxValue,
			nStartX,
			nStartY,
			nWidth,
			nHeight,
			(unsigned)nProgressColor,
			(unsigned)nColor,
			nStyle);
	}

	void MakeData(const std::string& szText, const STRUCT_HEADER& header)
	{
		stHeader = header;
		sscanf_s(szText.c_str(), "%d,%d,%d,%d,%d,%d,%d,%x,%x,%d",
			&nTextureSetIndex, &nCurrent, &nMaxValue, &nStartX, &nStartY,
			&nWidth, &nHeight, &nProgressColor, &nColor, &nStyle);
	}
};