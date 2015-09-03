
#include "cbase.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#ifdef SMMOD

class C_ViewModelArms : public C_BaseAnimating
{
public:
	DECLARE_CLASS(C_ViewModelArms, C_BaseAnimating);
	DECLARE_CLIENTCLASS();
	RenderGroup_t			GetRenderGroup() { return RENDER_GROUP_VIEW_MODEL_OPAQUE; }
	//	bool					IsViewModel() const {return true;};
};

IMPLEMENT_CLIENTCLASS_DT(C_ViewModelArms, DT_ViewModelArms, CViewModelArms)
END_RECV_TABLE()

//Commented out until further notice
/*
class C_ViewModelLeg : public C_BaseAnimating
{
public:
	DECLARE_CLASS(C_ViewModelLeg, C_BaseAnimating);
	DECLARE_CLIENTCLASS();
	RenderGroup_t			GetRenderGroup() { return RENDER_GROUP_VIEW_MODEL_OPAQUE; }
	//	bool					IsViewModel() const {return true;};
};

IMPLEMENT_CLIENTCLASS_DT(C_ViewModelLeg, DT_ViewModelLeg, CViewModelLeg)
END_RECV_TABLE()
*/
#endif