#include "IntegerProperty.h"

namespace FunkyProject {

IntegerProperty::IntegerProperty(const Map& map) :
    Property{map}
{
	value_   = std::any_cast<int>(map.at("value"));
	minimum_ = std::any_cast<int>(map.at("minimum"));
	maximum_ = std::any_cast<int>(map.at("maximum"));
	units_   = std::any_cast<std::string>(map.at("units"));
}

int IntegerProperty::value() const
{
	return value_;
}

int IntegerProperty::maximum() const
{
	return maximum_;
}

int IntegerProperty::minimum() const
{
	return minimum_;
}

std::string IntegerProperty::units() const
{
	return units_;
}

std::string IntegerProperty::description()
{
	return "This is IntegerProperty description";
}

} // namespace FunkyProject
