void f(String s); // pass by value
void g(String &s); // pass by referance
void h(String *s); // pass by pointer
main()
{
	String name=“Dog”;
	f(name); // name 的值不会改变
	g(name); // name 的值可能改变
	h(name); // name 的值可能改变
}

void g(const String &s);
void h(const String *s);