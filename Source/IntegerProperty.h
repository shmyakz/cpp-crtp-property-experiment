#pragma once

#include "Property.h"

namespace FunkyProject {

class IntegerProperty : public PropertyCRTP<IntegerProperty> {
public:
	explicit IntegerProperty(const Map& map);

	int value() const;

	int maximum() const;

	int minimum() const;

	std::string units() const;

	std::string description() override;

private:
	int         value_;
	int         maximum_;
	int         minimum_;
	std::string units_;
};

} // namespace FunkyProject
