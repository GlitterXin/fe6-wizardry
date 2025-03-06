#include "unit.h"

#include "msg.h"
#include "item.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "faction.h"
#include "unitsprite.h"
#include "support.h"
#include "battle.h"
#include "trap.h"
#include "action.h"
#include "ai_utility.h"
#include "gamedata.h"
#include "save_stats.h"

#include "constants/terrains.h"
#include "constants/iids.h"
#include "constants/unitsprites.h"
#include "constants/icons.h"
#include "constants/faces.h"

#include "common-chax.h"

extern u8 ItemID;

LYN_REPLACE_CHECK(GetUnitDefense);
int GetUnitDefense(struct Unit * unit)
{
	int CurDef = unit->def;
	CurDef += GetItemDefBonus(GetUnitEquippedWeapon(unit));

	for (int i = 0; i < 5; ++i) {
		if (GetItemIid(unit->items[i]) == ItemID){
			CurDef += 1;
		}
	}
	return CurDef;
}