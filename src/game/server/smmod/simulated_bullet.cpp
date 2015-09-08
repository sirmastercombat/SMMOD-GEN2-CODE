
#include "cbase.h"
#include "simulated_bullet.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"


LINK_ENTITY_TO_CLASS(simulated_bullet, CBullet);

BEGIN_DATADESC(CBullet)
// Function Pointers
DEFINE_FUNCTION(BulletTouch),

END_DATADESC()

IMPLEMENT_SERVERCLASS_ST(CBullet, DT_Bullet)
END_SEND_TABLE()

CBullet *CBullet::BulletCreate(const Vector &vecOrigin, const QAngle &angAngles, CBaseEntity *pentOwner)
{
	// Create a new entity with CCrossbowBolt private data
	CBullet *pBullet = (CBullet *)CreateEntityByName("(simulated_bullet");
	UTIL_SetOrigin(pBullet, vecOrigin);
	pBullet->SetAbsAngles(angAngles);
	pBullet->Spawn();
	pBullet->SetOwnerEntity(pentOwner);

	return pBullet;
}


unsigned int CBullet::PhysicsSolidMaskForEntity() const
{
	return (BaseClass::PhysicsSolidMaskForEntity() | CONTENTS_HITBOX) & ~CONTENTS_GRATE;
}

void CBullet::BulletTouch(CBaseEntity *pOther)
{
	this->Remove();
}
void CBullet::Spawn(void)
{
	Precache();
	PrecacheModel("models/crossbow_bolt.mdl");
	SetModel("models/crossbow_bolt.mdl");
	SetMoveType(MOVETYPE_FLYGRAVITY, MOVECOLLIDE_FLY_CUSTOM);
	//UTIL_SetSize(this, -Vector(0.3f, 0.3f, 0.3f), Vector(0.3f, 0.3f, 0.3f));
	SetSolid(SOLID_BBOX);
	SetGravity(0.05f);

	// Make sure we're updated if we're underwater
	UpdateWaterState();

	SetTouch(&CBullet::BulletTouch);

	//SetThink(&CCrossbowBolt::BubbleThink);
	//SetNextThink(gpGlobals->curtime + 0.1f);

	//CreateSprites();

	// Make us glow until we've hit the wall
	//m_nSkin = BOLT_SKIN_GLOW;
}

//extern ConVar *host_timescale;

//Just a test command and placeholder
void BulletTime_f(const CCommand &args)
{
	//ConVar *sv_cheats = cvar->FindVar("sv_cheats");
	//sv_cheats>SetValue(1.0f);
	engine->ServerCommand("sv_cheats 1\n");
	ConVar *host_timescale = cvar->FindVar("host_timescale");
	if (host_timescale->GetFloat() != 1.0f)
	{
		host_timescale->SetValue(1.0f);
	}
	else
	{
		host_timescale->SetValue(0.2f);
	}
}

ConCommand BulletTime("bullettime", BulletTime_f);
