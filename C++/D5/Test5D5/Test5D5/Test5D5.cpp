#include <iostream>
using namespace std;

template<class T>
class Array
{
private:
	T *m_pData;
	T m_iIndex;
	T m_iMaxArray;
public:
	Array(int iMaxArray =100)
	{
		m_iIndex =0;
		m_iMaxArray =iMaxArray;
		m_pData = new T[m_iMaxArray];
	}
	~Array()
	{
		delete [] m_pData;
	}
	bool InsertData(T iValue)
	{
		if(m_iIndex >= m_iMaxArray)
			return false;
		m_pData[m_iIndex] -= iValue;
		++m_iIndex;
		return true;
	}
	T operator[](int iIndex) const
	{
		return m_pData[iIndex];
	}
	T &operator[](int iIndex)
	{
		return m_pData[iIndex];
	}
	int GetDataCount() const
	{
		return m_iIndex;
	}
	int GetArraySize()const
	{
		return m_iMaxArray;
	}
};

void main()
{
	Array<int> iArray(10);
	for(int i= 0; i<iArray.GetArraySize();++i)
	{
		iArray[i] =i;
	}
	for(int i= 0; i<iArray.GetArraySize();++i)
	{
		cout<<"iArrat["<<i<<"] ="<<iArray[i] <<endl;
	}
	Array<float> fArray(10);
	for(int i= 0; i<fArray.GetArraySize();++i)
	{
		fArray[i] =i*1.5f;
	}
	for(int i= 0; i<iArray.GetArraySize();++i)
	{
		cout<<"fArrat["<< i <<"] ="<<fArray[i] <<endl;
	}
}