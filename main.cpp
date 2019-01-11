#include "BMFontParser.h"

using namespace BMF;

int main()
{
	UNIQUE_PTR<BMFontParser> myParser = MAKE_UNIQUE(BMFontParser)();
	
	myParser->Parse("Asset\\minimal.fnt");
	
	const BMFontParser::BMFont* myData = myParser->GetFontData();
	
	system("pause");
	return 0;
}