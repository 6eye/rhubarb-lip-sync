#pragma once

#include <iostream>
#include "EnumConverter.h"

// The classic Hanna-Barbera mouth shapes A-F phus the common supplements G-H
// For reference, see http://sunewatts.dk/lipsync/lipsync/article_02.php
// For visual examples, see https://flic.kr/s/aHsj86KR4J. Their shapes "BMP".."L" map to A..H.
enum class Shape {
	Invalid = -1,
	AI,
	O,
	E,
	U,
	etc,
	L,
	WQ,
	MBP,
    FV,
    rest
};

class ShapeConverter : public EnumConverter<Shape> {
public:
	static ShapeConverter& get();
protected:
	std::string getTypeName() override;
	member_data getMemberData() override;
};

std::ostream& operator<<(std::ostream& stream, Shape value);

std::istream& operator>>(std::istream& stream, Shape& value);
