#include <iostream>

using namespace std;

#include "json.hpp"

// for convenience
using json = nlohmann::json;

namespace ns {
	struct Address
	{
		std::string city;
		std::string street;

		bool operator == (const Address& rhs)
		{
			return city == rhs.city && street == rhs.street;
		}
	};

	void to_json(json& j, const Address& a) {
		j = json{{"city", a.city}, {"street", a.street}};
	}

	void from_json(const json& j, Address& p) {
		p.city = j.at("city").get<std::string>();
		p.street = j.at("street").get<std::string>();
	}

	// a simple struct to model a person
	struct Person {
		std::string name;
		Address address;
		int age;

		bool operator == (const Person& rhs)
		{
			return name == rhs.name 
			 && address == rhs.address 
				 && age == rhs.age;
		}
	};

	void to_json(json& j, const Person& p) {
		j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
	}

	void from_json(const json& j, Person& p) {
		p.name = j.at("name").get<std::string>();
		p.address = j.at("address").get<Address>();
		p.age = j.at("age").get<int>();
	}
} // namespace ns

int main(int argc, char *argv[])
{
	// create a Person
	ns::Person p {"Ivan Petrov", {"Spb", "Nevskiy"}, 60};

	// conversion: Person -> json
	json j = p;

	std::cout << j << std::endl;
	// {"address":{"city":"Spb","street":"Nevskiy"},"age":60,"name":"Ivan Petrov"}

	// conversion: json -> Person
	ns::Person p2 = j;

	// that's it
	assert(p == p2);

	return 0;
}
