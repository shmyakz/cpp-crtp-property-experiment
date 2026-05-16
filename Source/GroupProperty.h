#pragma once

#include "Property.h"

namespace FunkyProject {

class GroupProperty : public PropertyCRTP<GroupProperty> {
public:
	explicit GroupProperty(const Map& map);

	std::any value(const std::string& key) const;

	std::string string(const std::string& key) const;

	std::string description() override;

private:
	Map values;
};

} // namespace FunkyProject
