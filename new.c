void Test(Void)
{
	float *p;
	p = new float[100];
	if(p == NULL) return;
	...//action
	delete p;
	p = NULL;
	p = new float[500];
	if(p == NULL) return;
	...//action
	delete p;
	p = NULL;
}