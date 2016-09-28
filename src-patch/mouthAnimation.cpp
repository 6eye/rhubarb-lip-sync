#include "mouthAnimation.h"
#include "logging.h"

using std::map;

Shape getShape(Phone phone) {
	switch (phone) {
        case Phone::AA:
        case Phone::AE:
        case Phone::AH:
        case Phone::AY:
        case Phone::IH:
            return Shape::AI;
            
        case Phone::AO:
        case Phone::AW:
        case Phone::OW:
            return Shape::O;
            
        case Phone::EH:
        case Phone::ER:
        case Phone::EY:
        case Phone::IY:
            return Shape::E;
            
        case Phone::UH:
        case Phone::UW:
            return Shape::U;
            
		case Phone::Unknown:
        case Phone::CH:
        case Phone::D:
        case Phone::DH:
        case Phone::G:
        case Phone::HH:
        case Phone::JH:
        case Phone::K:
        case Phone::N:
        case Phone::NG:
        case Phone::R:
        case Phone::S:
        case Phone::SH:
        case Phone::T:
        case Phone::TH:
        case Phone::Y:
        case Phone::Z:
        case Phone::ZH:
			return Shape::etc;

        case Phone::L:
            return Shape::L;
            
        case Phone::OY:
        case Phone::W:
            return Shape::WQ;
            
        case Phone::P:
        case Phone::B:
        case Phone::M:
            return Shape::MBP;
            
		case Phone::F:
		case Phone::V:
			return Shape::FV;

        case Phone::None:
            return Shape::rest;
            
		default:
			throw std::runtime_error("Unexpected Phone value.");
	}
}

Timeline<Shape> animate(const Timeline<Phone> &phones) {
	Timeline<Shape> shapes(phones.getRange());
	for (auto& timedPhone : phones) {
		Timed<Shape> timedShape(static_cast<TimeRange>(timedPhone), getShape(timedPhone.getValue()));
		shapes.set(timedShape);
		logging::logTimedEvent("shape", timedShape);
	}

	return shapes;
}
