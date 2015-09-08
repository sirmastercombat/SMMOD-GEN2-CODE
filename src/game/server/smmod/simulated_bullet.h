
#ifndef SIMBULLET_H
#define SIMBULLET_H

#include "cbase.h"


class CBullet : public CBaseCombatCharacter
{
	DECLARE_CLASS(CBullet, CBaseCombatCharacter);

public:
	static const int EXPLOSION_RADIUS = 200;

	CBullet() {};
	~CBullet() {};

	Class_T Classify(void) { return CLASS_NONE; }


	void	Spawn(void);
	void	BulletTouch(CBaseEntity *pOther);

	bool	CreateVPhysics(void)
	{
		// Create the object in the physics system
		VPhysicsInitNormal(SOLID_BBOX, FSOLID_NOT_STANDABLE, false);

		return true;
	}
	unsigned int PhysicsSolidMaskForEntity() const;

	static CBullet *BulletCreate(const Vector &vecOrigin, const QAngle &angAngles, CBaseEntity *pentOwner = NULL);
protected:
	DECLARE_DATADESC();
	DECLARE_SERVERCLASS();
private:
};

#endif	//SIMBULLET