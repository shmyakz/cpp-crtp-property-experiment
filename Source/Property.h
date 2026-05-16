#pragma once

#include <any>
#include <format>
#include <map>
#include <memory>

namespace FunkyProject {

using Map = std::map<std::string, std::any>;

class Property {
public:
	enum class Type {
		Default,
		String,
		Group,
		Integer,
		Enum,
	};

	enum class State {
		Mandatory,
		Enabled,
		Disabled
	};

	template<typename T>
	T* as()
	{
		static_assert(std::is_base_of_v<Property, T>, "T must be a subclass of Property");
		return static_cast<T*>(this);
	}
};

template<typename Derived>
class PropertyCRTP : public Property {
public:
	using TypeValue = Derived;
	using Ptr       = std::unique_ptr<Derived>;

	PropertyCRTP() = delete;

	PropertyCRTP(const PropertyCRTP&)            = default;
	PropertyCRTP& operator=(const PropertyCRTP&) = default;
	PropertyCRTP(PropertyCRTP&&)                 = default;
	PropertyCRTP& operator=(PropertyCRTP&&)      = default;

	explicit PropertyCRTP(const Map& map)
	{
		name_  = std::any_cast<std::string>(map.at("name"));
		type_  = std::any_cast<Type>(map.at("type"));
		state_ = std::any_cast<State>(map.at("state"));
	}

	virtual ~PropertyCRTP() = default;

	Type type()
	{
		return type_;
	}

	State state()
	{
		return state_;
	};

	virtual std::string name()
	{
		return name_;
	};

	virtual std::string description() = 0;

	virtual Map toMap()
	{
		Map result;
		result["name"]  = name();
		result["type"]  = static_cast<int>(type());
		result["state"] = static_cast<int>(state());
		return result;
	};

	/**
	 * Constructs Property::Ptr from provided field's map
	 * @note Shouldn't pass compilation if Property doesn't provide constructor from `const Map&`
	 * @param map Property field map
	 * @return unique_ptr with Derived type on success, nullptr on any exception or failure to create a unique_ptr
	 */
	static Ptr fromMap(const Map& map)
	{
		static_assert(
		        std::is_constructible_v<Derived, const Map&>,
		        "Derived class must provide a constructor taking `const Map&`");
		try {
			return std::make_unique<Derived>(map);
		}
		catch(...) {
			return nullptr;
		}
	}

private:
	std::string name_{"Default"};
	Type        type_{Type::Default};
	State       state_{State::Mandatory};
};

} // namespace FunkyProject
