class Stack
{
public:
	void push(int elem);
	void pop(void);
	int Count(void) const;//const类型的函数
private:
	int num;
	int data[100];
};

int Stack::Count(void) const
{
	++ num;//编译错误，num值发生改变
	pop（）；//编译错误，pop将改变成员变量的值
	return num；
}