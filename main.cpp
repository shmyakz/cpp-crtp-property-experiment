#include "Source/GroupProperty.h"
#include "Source/IntegerProperty.h"

#include <format>
#include <iostream>

int main()
{
	const auto& intProperty = FunkyProject::IntegerProperty::fromMap(
	        FunkyProject::Map{
	            {"type",    FunkyProject::IntegerProperty::Type::Integer   },
	            {"name",    std::string("Int Property Name")               },
	            {"state",   FunkyProject::IntegerProperty::State::Mandatory},
	            {"value",   42	                                         },
	            {"maximum", 42	                                         },
	            {"minimum", 42	                                         },
	            {"units",   std::string("meters")                          }
    });

	const auto& groupProperty = FunkyProject::GroupProperty::fromMap(
	        FunkyProject::Map{
	            {"type",   FunkyProject::GroupProperty::Type::Group                                   },
	            {"name",   std::string("Group Property Name")                                         },
	            {"state",  FunkyProject::GroupProperty::State::Mandatory                              },
	            {"values", FunkyProject::Map{{"value", std::string("This is Value in GroupProperty")}}}
    });

	if(not intProperty) {
		std::cout << "Failed to create IntegerProperty!\n";
	}
	else {
		std::cout << std::format(
		        "IntegerProperty: value - {}, maximum - {}, minimum - {}, units - {}\n",
		        intProperty->value(),
		        intProperty->maximum(),
		        intProperty->minimum(),
		        intProperty->units());
		std::cout << std::format("IntegerProperty description - {}\n", intProperty->description());
	}
	if(not groupProperty) {
		std::cout << "Failed to create GroupProperty!\n";
	}
	else {
		std::cout << std::format(
		        "GroupProperty: name - {}, value with key `value` - {}\n",
		        groupProperty->name(),
		        groupProperty->string("value"));
		std::cout << std::format("GroupProperty description - {}\n", groupProperty->description());
	}

	return 0;
}
