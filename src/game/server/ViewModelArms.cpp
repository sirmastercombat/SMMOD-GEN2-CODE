#include "cbase.h"
#include "hl2_player.h"
// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#ifdef SMMOD

class CViewModelArms : public CBaseAnimating
{
	DECLARE_CLASS(CViewModelArms, CBaseAnimating);
	DECLARE_SERVERCLASS();
public:
	CViewModelArms(){ EnableDynamicModels(); }
};
LINK_ENTITY_TO_CLASS(viewmodelarms, CViewModelArms);
IMPLEMENT_SERVERCLASS_ST(CViewModelArms, DT_ViewModelArms)
END_SEND_TABLE()

//Commented out until further notice
/*
class CViewModelLeg : public CBaseAnimating
{
	DECLARE_CLASS(CViewModelLeg, CBaseAnimating);
	DECLARE_SERVERCLASS();
public:
	virtual void HandleAnimEvent(animevent_t *pEvent);
};
void CViewModelLeg::HandleAnimEvent(animevent_t *pEvent)
{
	switch(pEvent->event)
	{
	case EVENT_WEAPON_MELEE_HIT:
		Msg("FOOT ACTIVATED!");
		return;
	}
	//Pass it through as normal for now...
	BaseClass::HandleAnimEvent(pEvent);
}
LINK_ENTITY_TO_CLASS(viewmodelleg, CViewModelLeg);
IMPLEMENT_SERVERCLASS_ST(CViewModelLeg, DT_ViewModelLeg)
END_SEND_TABLE()
*/
void ChangeArms_f(const CCommand &args)
{
	CHL2_Player *local_player = (CHL2_Player*) UTIL_GetCommandClient();
	
	if (engine->PrecacheModel(args.Arg(1), true) == 1 || engine->IsModelPrecached(args.Arg(1)))
	{
		local_player->m_ViewModelArm->SetModel(args.Arg(1));;//Set the current model now
	}
	else
	{
		Warning("Error: Unable to load model!");
	}

}

ConCommand ChangeArms("changearms", ChangeArms_f);

#endif