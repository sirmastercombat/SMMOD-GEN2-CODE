
#include "cbase.h"

//#define CBullet C_Bullet

class C_Bullet : public C_BaseCombatCharacter
{
	DECLARE_CLASS(C_Bullet, C_BaseCombatCharacter);
	DECLARE_CLIENTCLASS();
public:

	C_Bullet(void) {}

private:

	C_Bullet(const C_Bullet &); // not defined, not accessible
};

IMPLEMENT_CLIENTCLASS_DT(C_Bullet, DT_Bullet, CBullet)
END_RECV_TABLE()
