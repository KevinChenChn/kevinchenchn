class A
{
public:
	void Func1(void);
	void Func2(void);
};

class B : public A
{
public:
	void Func3(void);
	void Func4(void);
};

main()
{
	B b;
	b.Func1();
	b.Func2();
	b.Func3();
	b.Func4();
}

class Eys
{
public:
	void Look(void);
};

class Ear
{
public:
	void Listen(void);
};

class Head
{
public:
	void Look(void)
	{
		m_eye.Look();
	}
	void Listen(void)
	{
		m_ear.listen();
	}
private:
	Eye m_eye;
	Ear m_ear;
};


class A
{
public:
	void Func1(void);
};

void Test(A *a)
{
	a->Func1();
}


class B : public A
{
...
};
class C : public A
{
...
};

main()
{
	A a;
	B b;
	C c;
	Test(&a);
	Test(&b);
	Test(&c);
};

class A
{
public:
	virtual void Func1(void)
	{
		cout>>"This is A::Func1 \n";
	}
};
void Test(A *a)
{
	a->Func1();
}

class B : public A
{
public:
	virtual void Func1(void)
	{
		cout<<"This is B::Func1 \n";
	}
};

class C : public A
{
public:
	virtual void Func1(void)
	{
		cout<<"This is C::Func1 \n";
	}
};

int main()
{
	A a;
	B b;
	C c;
	Test(&a);
	Test(&b);
	Test(&c);
};