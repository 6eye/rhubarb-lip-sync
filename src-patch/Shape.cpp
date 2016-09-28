#include "Shape.h"

using std::string;

ShapeConverter& ShapeConverter::get() {
	static ShapeConverter converter;
	return converter;
}

string ShapeConverter::getTypeName() {
	return "Shape";
}

EnumConverter<Shape>::member_data ShapeConverter::getMemberData() {
	return member_data{
		{ Shape::AI, "AI" },
		{ Shape::O, "O" },
		{ Shape::E, "E" },
		{ Shape::U, "U" },
		{ Shape::etc, "etc" },
		{ Shape::L, "L" },
		{ Shape::WQ, "WQ" },
		{ Shape::MBP, "MBP" },
        { Shape::FV, "FV" },
        { Shape::rest, "rest" }
	};
}

std::ostream& operator<<(std::ostream& stream, Shape value) {
	return ShapeConverter::get().write(stream, value);
}

std::istream& operator>>(std::istream& stream, Shape& value) {
	return ShapeConverter::get().read(stream, value);
}
