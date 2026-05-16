#include "Source/GroupProperty.h"
#include "Source/IntegerProperty.h"

#include <format>
#include <iostream>

std::unique_ptr<FunkyProject::Property> createProperty(const FunkyProject::Map& map)
{
	try {
		auto type = std::any_cast<FunkyProject::Property::Type>(map.at("type"));
		switch(type) {
		case FunkyProject::Property::Type::Integer:
			return FunkyProject::IntegerProperty::fromMap(map);
		case FunkyProject::Property::Type::Group:
			return FunkyProject::GroupProperty::fromMap(map);
		}
	}
	catch(...) {
		return nullptr;
	}
	return nullptr;
}

int main()
{
	// const auto& intProperty = FunkyProject::IntegerProperty::fromMap(
	//         FunkyProject::Map{
	//             {"type",    FunkyProject::IntegerProperty::Type::Integer   },
	//             {"name",    std::string("Int Property Name")               },
	//             {"state",   FunkyProject::IntegerProperty::State::Mandatory},
	//             {"value",   42	                                         },
	//             {"maximum", 42	                                         },
	//             {"minimum", 42	                                         },
	//             {"units",   std::string("meters")                          }
	// });
	//
	// const auto& groupProperty = FunkyProject::GroupProperty::fromMap(
	//      FunkyProject::Map{
	//          {"type",   FunkyProject::GroupProperty::Type::Group                                   },
	//          {"name",   std::string("Group Property Name")                                         },
	//          {"state",  FunkyProject::GroupProperty::State::Mandatory                              },
	//          {"values", FunkyProject::Map{{"value", std::string("This is Value in GroupProperty")}}}
	// });

	const auto& intProperty = createProperty(
	        FunkyProject::Map{
	            {"type",    FunkyProject::IntegerProperty::Type::Integer   },
	            {"name",    std::string("Int Property Name")               },
	            {"state",   FunkyProject::IntegerProperty::State::Mandatory},
	            {"value",   42	                                         },
	            {"maximum", 42	                                         },
	            {"minimum", 42	                                         },
	            {"units",   std::string("meters")                          }
    });

	const auto& groupProperty = createProperty(
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
		auto cast = intProperty->as<FunkyProject::IntegerProperty>();
		std::cout << std::format(
		        "IntegerProperty: value - {}, maximum - {}, minimum - {}, units - {}\n",
		        cast->value(),
		        cast->maximum(),
		        cast->minimum(),
		        cast->units());
		std::cout << std::format("IntegerProperty description - {}\n", cast->description());
	}
	if(not groupProperty) {
		std::cout << "Failed to create GroupProperty!\n";
	}
	else {
		auto cast = groupProperty->as<FunkyProject::GroupProperty>();
		std::cout << std::format(
		        "GroupProperty: name - {}, value with key `value` - {}\n",
		        cast->name(),
		        cast->string("value"));
		std::cout << std::format("GroupProperty description - {}\n", cast->description());
	}

	return 0;
}
