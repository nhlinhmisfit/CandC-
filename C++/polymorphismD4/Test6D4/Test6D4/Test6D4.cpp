#include<iostream>
using namespace std;

//delegation
class Weapon
{
public: 
	virtual void Attack()const 
	{

	}
	virtual Weapon *copy() const
	{
		return NULL;
	}
};
class Sword: public Weapon
{
public:
	virtual void Attack() const
	{
		cout<<"Sword Attack"<<endl;
	}
	virtual Weapon * copy()const
	{
		return new Sword;
	}
};
class MachineGun : public Weapon
{
public:
	virtual void Attack() const
	{
		cout<<"machine gun attack"<<endl;
	}
	virtual Weapon * copy() const
	{
		return new MachineGun;
	}
};
class Missile : public Weapon
{
public: 
	virtual void Attack() const
	{
		cout<<"Missile Attack"<<endl;
	}
	virtual Weapon * copy()const
	{
		return new Missile;
	}
};
class Robot
{
private:
	Weapon * m_pWeapon;
public:
	Robot(Weapon * pWeapon): m_pWeapon(pWeapon)
	{

	}
	~Robot()
	{
		delete m_pWeapon;
	}
	Robot (const Robot & r)//-> shallow copy
	{
		m_pWeapon = r.m_pWeapon->copy();   //shallow copy  //deep copy
	}
	Robot & operator=(const Robot & r)
	{
		if( this ==&r)
			return*this;
		delete m_pWeapon;
		m_pWeapon = r.m_pWeapon->copy();
		return *this;
	}

	void Attack() const 
	{
		m_pWeapon->Attack();

	}
	void SetWeapon(Weapon *pWeapon)
	{
		delete m_pWeapon;
		m_pWeapon = pWeapon;
	}
};
void main()
{
	Robot r1(new Sword); 
	r1.Attack();
	r1.SetWeapon(new MachineGun);
	r1.Attack();
}








