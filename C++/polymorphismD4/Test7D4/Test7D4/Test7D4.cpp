#include <iostream>
using namespace std;
#include "MyString.h"


//interface , leading edge 
class videostatus // abstact base class
{
public: 
	virtual int GetRentalPrice() const =0;
	
	virtual const char *GetvideostatusName() const =0; //pure virtual
	virtual videostatus * copy() const =0;
};

class newvideo: public videostatus
{
public: 
	virtual int GetRentalPrice() const
	{
		return 20000;
	}
	virtual const char *GetvideostatusName() const
	{
		return "New";
	}
	virtual videostatus * copy() const
	{
		return new newvideo;
	}

};

class normalvideo: public videostatus
{
public: 
	virtual int GetRentalPrice() const
	{
		return 10000;
	}
	virtual const char *GetvideostatusName() const
	{
		return "Normal";
	}
	virtual videostatus * copy() const
	{
		return new normalvideo;
	}
};

class oldvideo: public videostatus
{
public: 
	virtual int GetRentalPrice() const
	{
		return 5000;
	}
	virtual const char *GetvideostatusName() const
	{
		return "old";
	}
	virtual videostatus * copy() const
	{
		return new oldvideo;
	}
};
class realvideo: public videostatus
{
public: 
	virtual int GetRentalPrice() const
	{
		return 15000;
	}
	virtual const char *GetvideostatusName() const
	{
		return "realvideo";
	}
	virtual videostatus * copy() const
	{
		return new realvideo;
	}
};

class videostatuspointerarray
{
public:
	videostatuspointerarray(int iMaxArray =10)
	{
		m_iIndex =0;
		m_iMaxArray = iMaxArray;
		m_pData =new videostatus *[m_iMaxArray];
	}
	~videostatuspointerarray()
	{
		while(deleteat(m_iIndex-1));
	}
	bool deleteat(int iIndex)
	{
		if(m_iIndex ==0)
			return false;
		memcpy(&m_pData[iIndex],&m_pData[iIndex +1],sizeof(videostatus*)*(m_iIndex -iIndex -1));
		--m_iIndex;
		return true;
	}
	int GetCount() const
	{
		return m_iIndex;
	}
	videostatus * operator[](int iIndex)const
	{
		return m_pData[iIndex];
	}
	bool InsertData(videostatus * pvideo)
	{
		if(m_iIndex>= m_iMaxArray)
			return false;
		m_pData[m_iIndex] = pvideo;
		++m_iIndex;
		return true;

	}
private:
	videostatus ** m_pData;
	int m_iIndex;
	int m_iMaxArray;
};
class videostatusinput
{
protected:
	videostatuspointerarray m_videostatusarray;
public:
	videostatusinput()
	{
		m_videostatusarray.InsertData(new newvideo);
		m_videostatusarray.InsertData(new normalvideo);
		m_videostatusarray.InsertData(new oldvideo);
		m_videostatusarray.InsertData(new realvideo);
	}

	virtual void displaymenu()
	{

	}
	 videostatus * Getvideostatusinput()
	{
		//cout<<"[Status "<<endl;
		/*cout<<"[[[Status]]] "<<endl;
		for(int i=0; i< m_videostatusarray.GetCount(); ++i)
		{
			cout <<i+1<<"."<<m_videostatusarray[i]->GetvideostatusName()<<" "<<endl;
		}*/
		//cout<<"]: ";
		displaymenu();
		int status;
		cin>>status;
		cin.ignore(1);
		if(status >=1 && status<=m_videostatusarray.GetCount())
		{
			return m_videostatusarray[status-1]->copy();
		}
		return m_videostatusarray[0]->copy();
	}
};
class videostatusinputrow  : public videostatusinput
{
public:
	virtual void displaymenu()
	{
		cout<<"[[[Status]]] "<<endl;
		for(int i=0; i< m_videostatusarray.GetCount(); ++i)
		{
			cout <<i+1<<"."<<m_videostatusarray[i]->GetvideostatusName()<<" "<<endl;
		}
	}
};

class videostatusinputcol  : public videostatusinput
{
public:
	virtual void displaymenu()
	{
		cout<<"Status: [ ";
		for(int i=0; i< m_videostatusarray.GetCount(); ++i)
		{
			cout <<i+1<<"."<<m_videostatusarray[i]->GetvideostatusName()<<" ";
		}
		cout<<"]";
	}
};
class Video
{
private:
	MyString m_Title;
	MyString m_Actor;
	MyString m_Director;
	int m_Price;
	videostatus *m_pvideostatus;
public:
	void Input(videostatusinput &vinput)
	{
		cout<<"Title: ";
		cin>>m_Title;
		cout<<"Actor: ";
		cin>>m_Actor;
		cout<<"Director:";
		cin>>m_Director;
		//videostatusinput vinput;
		m_pvideostatus = vinput.Getvideostatusinput();
	}
	void Print()
	{
		cout<<"Title: "<<m_Title<<endl;
		cout<<"Actor: "<<m_Actor<<endl;
		cout<<"Director:"<<m_Director<<endl;
		cout<<"Rental Price: "<<
		m_pvideostatus->GetRentalPrice()<<endl;

		cout<<"Status:"<<
		m_pvideostatus->GetvideostatusName()<<endl;

	}
};
void main()
{
	Video v;	
	videostatusinputrow r;
	v.Input(r);
	v.Print();

	videostatusinputcol c;
	v.Input(c);
	v.Print();
}
//gol design pattern  rethinking desing patterns
//refectoring  improving the design   very martin fowler
//


