#include "utility.hpp"
#include <string>

TEST_CASE("Stack construction")
{
	const std::string first;
	const std::string second{ "Hello World!" };

	rapid_string s1;
	rs_init(&s1);

	CMP_STR(&s1, first);

	rapid_string s2;
	rs_init(&s2);

	CMP_STR(&s2, first);

	rapid_string s3;
	rs_init_w(&s3, second.c_str());
	
	CMP_STR(&s3, second);

	rs_free(&s1);
	rs_free(&s2);
	rs_free(&s3);
}

TEST_CASE("Heap construction")
{
	const std::string first{ "A long string to get around SSO!" };

	rapid_string s;
	rs_init_w(&s, first.c_str());
	
	CMP_STR(&s, first);

	rs_free(&s);
}

