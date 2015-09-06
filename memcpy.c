void memcpy(void *pvTo, void *pvFrom, size_t size)
{
	void *pdTo = (byte *) pvTo;
	void *pbFrom = (byte *) pvFrom;
	assert(pvTo != NULL && pvFrom != NULL);
	while(size-- > 0)
		*pbTo++ = *pbFrom++;
	return (pvTo);
}