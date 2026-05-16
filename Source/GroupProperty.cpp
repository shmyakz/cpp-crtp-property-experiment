#include "GroupProperty.h"

namespace FunkyProject {

GroupProperty::GroupProperty(const Map& map) :
    PropertyCRTP(map)
{
	values = std::any_cast<const Map&>(map.at("values"));
}

std::any GroupProperty::value(const std::string& key) const
{
	return values.at(key);
}

std::string GroupProperty::string(const std::string& key) const
{
	return std::any_cast<std::string>(values.at(key));
}

std::string GroupProperty::description()
{
	return "This is GroupProperty description";
}

} // namespace FunkyProject
