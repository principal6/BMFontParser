#pragma once

#include <string>
#include <vector>
#include <Windows.h>
#include "Dependency/tinyxml2.h"

#ifndef CONVENIENT_STD
#define CONVENIENT_STD
	using STRING = std::string;

	template <typename T>
	using VECTOR = std::vector<T>;

	template <typename T>
	using UNIQUE_PTR = std::unique_ptr<T>;

	#define MAKE_UNIQUE(T) std::make_unique<T>
#endif

namespace BMF
{
	using BOOL = bool;

	class BMFontParser
	{
	public:
		struct BMFont
		{
			struct BMInfo;
			struct BMCommon;
			struct BMPage;
			struct BMChar;
			struct BMKerning;

			struct BMInfo
			{
				struct BMPadding;
				struct BMSpacing;

				struct BMPadding
				{
					// The order of the paddings is the following
					UINT Up;
					UINT Right;
					UINT Down;
					UINT Left;
				};

				struct BMSpacing
				{
					// The order of the spacings is the following
					UINT Horz;
					UINT Vert;
				};

				STRING Face;
				UINT Size;
				BOOL bBold;
				BOOL bItalic;
				STRING Charset;
				BOOL bUnicode;
				UINT StretchH;
				BOOL bSmooth;
				BOOL bAA;
				BMPadding Padding;
				BMSpacing Spacing;
				BOOL bOutline;
			};

			struct BMCommon
			{
				UINT LineHeight;
				UINT Base;
				UINT ScaleW;
				UINT ScaleH;
				UINT Pages;
				BOOL bPacked;
				UINT AlphaChnl;
				UINT RedChnl;
				UINT GreenChnl;
				UINT BlueChnl;
			};

			struct BMPage
			{
				UINT ID;
				STRING File;
			};

			struct BMChar
			{
				UINT ID;
				UINT X;
				UINT Y;
				UINT Width;
				UINT Height;
				INT XOffset;
				INT YOffset;
				UINT XAdvance;
				UINT Page;
				UINT Chnl;
			};

			struct BMKerning
			{
				UINT First;
				UINT Second;
				INT Amount;
			};

			BMInfo Info;
			BMCommon Common;
			VECTOR<BMPage> Pages;
			VECTOR<BMChar> Chars;
			VECTOR<BMKerning> Kernings;
		};

	private:
		static BMFont m_FontData;

	protected:
		inline UINT ParseComma(STRING Data, UINT ID);

	public:
		BMFontParser() {};
		virtual ~BMFontParser() {};

		auto Parse(STRING FileName)->bool;
		auto GetFontData()->const BMFont* const;
	};
};