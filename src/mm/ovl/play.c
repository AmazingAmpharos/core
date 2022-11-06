#include <combo.h>

extern void Play_Init(GameState_Play*);

static void debugCheat(GameState_Play* play)
{
#if defined(DEBUG)
    /*if (play->gs.input[0].current.buttons & 0x20)*/
    {
        gSave.itemEquips.sword = 3;
        gSave.itemEquips.shield = 2;
        gSave.itemEquips.buttonItems[0][0] = ITEM_MM_SWORD_GILDED;
        gSave.inventory.items[ITS_MM_OCARINA] = ITEM_MM_OCARINA_OF_TIME;
        gSave.inventory.items[ITS_MM_MASK_DEKU] = ITEM_MM_MASK_DEKU;
        gSave.inventory.items[ITS_MM_MASK_ZORA] = ITEM_MM_MASK_ZORA;
        gSave.inventory.items[ITS_MM_BOW] = ITEM_MM_BOW;
        gSave.inventory.items[ITS_MM_LENS] = ITEM_MM_LENS_OF_TRUTH;
        gSave.inventory.upgrades.quiver = 3;
        gSave.inventory.upgrades.wallet = 2;
        gSave.inventory.upgrades.bombBag = 3;
        gSave.playerData.rupees = 500;
        gSave.inventory.questItems.songHealing = 1;
        gSave.inventory.questItems.songTime = 1;
        gSave.inventory.items[ITS_MM_BOTTLE + 0] = ITEM_MM_BOTTLED_GOLD_DUST;
        gSave.inventory.items[ITS_MM_BOTTLE + 1] = ITEM_MM_BOTTLED_SPRING_WATER_HOT;
        gSave.playerData.magic = 0x30;
        gMmSave.playerData.magicAcquired = 1;
        gSaveContext.magicTarget = 0x30;
        gSave.inventory.items[ITS_MM_MASK_GORON] = ITEM_MM_MASK_GORON;
        gSave.inventory.ammo[ITS_MM_BOW] = 50;
        gSave.inventory.items[ITS_MM_ARROW_FIRE] = ITEM_MM_ARROW_FIRE;
        gSave.inventory.questItems.songLullabyIntro = 1;

        gSave.inventory.items[ITS_MM_KEG] = ITEM_MM_POWDER_KEG;
        gSave.inventory.items[ITS_MM_MASK_CAPTAIN] = ITEM_MM_MASK_CAPTAIN;
        gSave.playerData.healthCapacity = 0x10 * 20;
        gSave.playerData.health = gSave.playerData.healthCapacity;

        gMmExtraTrade.trade1 = 0xffff;
        gMmExtraTrade.trade2 = 0xffff;
        gMmExtraTrade.trade3 = 0xffff;

        gSave.inventory.items[ITS_MM_TRADE1] = ITEM_MM_DEED_SWAMP;
        gSave.inventory.items[ITS_MM_TRADE2] = ITEM_MM_ROOM_KEY;
        gSave.inventory.items[ITS_MM_TRADE3] = ITEM_MM_PENDANT_OF_MEMORIES;

        gSave.inventory.items[ITS_MM_MASK_KAFEI] = ITEM_MM_MASK_KAFEI;
    }
#endif
}

void hookPlay_Init(GameState_Play* play)
{
    comboObjectsReset();
    debugCheat(play);

    /* Force alt beaver race */
    MM_SET_EVENT_WEEK(EV_MM_WEEK_BEAVER_RACE_ALT);

    /* Pre-feed the fish at the lab */
    MM_SET_EVENT_WEEK(MM_EV(81, 4));
    MM_SET_EVENT_WEEK(MM_EV(81, 5));
    MM_SET_EVENT_WEEK(MM_EV(81, 6));
    MM_SET_EVENT_WEEK(MM_EV(81, 7));
    MM_SET_EVENT_WEEK(MM_EV(82, 0));
    MM_SET_EVENT_WEEK(MM_EV(82, 1));

    Play_Init(play);

    if (gSave.entranceIndex == 0xc010)
    {
        gSave.isOwlSave = 1;
        PrepareSave(&play->sramCtx);
        comboGameSwitch();
        return;
    }
}
