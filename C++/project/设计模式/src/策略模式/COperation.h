#ifndef __COPERATION_H__
#define __COPERATION_H__

class COperation
{
public:

	COperation();

public:
	virtual double GetResult()const;

	virtual void SetArg(int first, int second);
protected:
	int m_nFirst;
	int m_nSecond;
private:
};


#endif // __COPERATION_H__
