
#include "cbase.h"

#if defined( CLIENT_DLL )
class C_ViewModelArms : public C_BaseAnimating
{
public:
	DECLARE_CLASS(C_ViewModelArms, C_BaseAnimating);
	RenderGroup_t			GetRenderGroup() { return RENDER_GROUP_VIEW_MODEL_OPAQUE; }
	//	bool					IsViewModel() const {return true;};
};

LINK_ENTITY_TO_CLASS(viewmodelarms, C_ViewModelArms);

#endif