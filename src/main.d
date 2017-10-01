import std.stdio;
import asdf;

struct Address
{
	string city;
	string street;
}

// a simple struct to model a person
struct Person {
	string name;
	Address address;
	int age;
}

void main()
{
	// create a Person
	Person p = {"Ivan Petrov", {"Spb", "Nevskiy"}, 60};

	// conversion: Person -> json
	auto j = serializeToAsdf(p);

	writeln(j);
	// {"name":"Ivan Petrov","address":{"city":"Spb","street":"Nevskiy"},"age":60}

	// conversion: json -> Person
	auto p2 = deserialize!Person(j);

	// that's it
	assert(p == p2);
}