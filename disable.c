class A
{
public:
	void Func(void)
	{
		...//action
	}
};
void Test(void)
{
	A *p;
	{
		A a;
		p = &a;
	}
	p->Func();
}