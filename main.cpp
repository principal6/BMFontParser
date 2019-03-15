#include "BMFontParser.h"

using namespace JWEngine;

int main()
{
	UNIQUE_PTR<BMFontParser> myParser = MAKE_UNIQUE(BMFontParser)();
	
	myParser->Parse(L"Asset\\minimal.fnt");
	
	const BMFont* myData = myParser->GetFontData();

	return 0;
}