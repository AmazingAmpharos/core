#include <combo.h>

static const u16 kSwords[] = {
    ITEM_NONE,
    ITEM_MM_SWORD_KOKIRI,
    ITEM_MM_SWORD_RAZOR,
    ITEM_MM_SWORD_GILDED,
};

static void addSword(int index)
{
    gMmSave.itemEquips.buttonItems[0][0] = kSwords[index];
    gMmSave.itemEquips.sword = index;
}

static void addShield(int index)
{
    gMmSave.itemEquips.shield = index;
}

static void addBombBag(int index)
{
    gMmSave.inventory.items[ITS_MM_BOMBS] = ITEM_MM_BOMB;
    gMmSave.inventory.upgrades.bombBag = index;
    gMmSave.inventory.ammo[ITS_MM_BOMBS] = kMaxBombs[index];
}

static void addBowQuiver(int index)
{
    gMmSave.inventory.items[ITS_MM_BOW] = ITEM_MM_BOW;
    gMmSave.inventory.upgrades.quiver = index;
    gMmSave.inventory.ammo[ITS_MM_BOW] = kMaxArrows[index];
}

static void addBombs(int count)
{
    u16 max;

    max = kMaxBombs[gMmSave.inventory.upgrades.bombBag];
    gMmSave.inventory.items[ITS_MM_BOMBS] = ITEM_MM_BOMB;
    gMmSave.inventory.ammo[ITS_MM_BOMBS] += count;
    if (gMmSave.inventory.ammo[ITS_MM_BOMBS] > max)
        gMmSave.inventory.ammo[ITS_MM_BOMBS] = max;
}

static void addArrows(int count)
{
    u16 max;

    max = kMaxArrows[gMmSave.inventory.upgrades.quiver];
    gMmSave.inventory.items[ITS_MM_BOW] = ITEM_MM_BOW;
    gMmSave.inventory.ammo[ITS_MM_BOW] += count;
    if (gMmSave.inventory.ammo[ITS_MM_BOW] > max)
        gMmSave.inventory.ammo[ITS_MM_BOW] = max;
}

void comboAddItemMm(u16 itemId)
{
    switch (itemId)
    {
    case ITEM_MM_OCARINA_OF_TIME:
        gMmSave.inventory.items[ITS_MM_OCARINA] = ITEM_MM_OCARINA_OF_TIME;
        break;
    case ITEM_MM_ARROW_FIRE:
        gMmSave.inventory.items[ITS_MM_ARROW_FIRE] = ITEM_MM_ARROW_FIRE;
        break;
    case ITEM_MM_ARROW_ICE:
        gMmSave.inventory.items[ITS_MM_ARROW_ICE] = ITEM_MM_ARROW_ICE;
        break;
    case ITEM_MM_ARROW_LIGHT:
        gMmSave.inventory.items[ITS_MM_ARROW_LIGHT] = ITEM_MM_ARROW_LIGHT;
        break;
    case ITEM_MM_MAGIC_BEAN:
        gMmSave.inventory.items[ITS_MM_BEANS] = ITEM_MM_MAGIC_BEAN;
        gMmSave.inventory.ammo[ITS_MM_BEANS]++;
        break;
    case ITEM_MM_POWDER_KEG:
        gMmSave.inventory.items[ITS_MM_KEG] = ITEM_MM_POWDER_KEG;
        gMmSave.inventory.ammo[ITS_MM_KEG] = 1;
        break;
    case ITEM_MM_PICTOGRAPH_BOX:
        gMmSave.inventory.items[ITS_MM_PICTOBOX] = ITEM_MM_PICTOGRAPH_BOX;
        break;
    case ITEM_MM_LENS_OF_TRUTH:
        gMmSave.inventory.items[ITS_MM_LENS] = ITEM_MM_LENS_OF_TRUTH;
        break;
    case ITEM_MM_LONGSHOT:
        gMmSave.inventory.items[ITS_MM_LONGSHOT] = ITEM_MM_LONGSHOT;
        break;
    case ITEM_MM_GREAT_FAIRY_SWORD:
        gMmSave.inventory.items[ITS_MM_GREAT_FAIRY_SWORD] = ITEM_MM_GREAT_FAIRY_SWORD;
        break;
    case ITEM_MM_BOMB:
        addBombs(1);
        break;
    case ITEM_MM_BOMBS_5:
        addBombs(5);
        break;
    case ITEM_MM_BOMBS_10:
        addBombs(10);
        break;
    case ITEM_MM_BOMBS_20:
        addBombs(20);
        break;
    case ITEM_MM_BOMBS_30:
        addBombs(30);
        break;
    case ITEM_MM_ARROWS_10:
        addArrows(10);
        break;
    case ITEM_MM_ARROWS_30:
        addArrows(30);
        break;
    case ITEM_MM_ARROWS_40:
        addArrows(40);
        break;
    case ITEM_MM_MASK_POSTMAN:
        gMmSave.inventory.items[ITS_MM_MASK_POSTMAN] = ITEM_MM_MASK_POSTMAN;
        break;
    case ITEM_MM_MASK_ALL_NIGHT:
        gMmSave.inventory.items[ITS_MM_MASK_ALL_NIGHT] = ITEM_MM_MASK_ALL_NIGHT;
        break;
    case ITEM_MM_MASK_BLAST:
        gMmSave.inventory.items[ITS_MM_MASK_BLAST] = ITEM_MM_MASK_BLAST;
        break;
    case ITEM_MM_MASK_STONE:
        gMmSave.inventory.items[ITS_MM_MASK_STONE] = ITEM_MM_MASK_STONE;
        break;
    case ITEM_MM_MASK_GREAT_FAIRY:
        gMmSave.inventory.items[ITS_MM_MASK_GREAT_FAIRY] = ITEM_MM_MASK_GREAT_FAIRY;
        break;
    case ITEM_MM_MASK_DEKU:
        gMmSave.inventory.items[ITS_MM_MASK_DEKU] = ITEM_MM_MASK_DEKU;
        break;
    case ITEM_MM_MASK_KEATON:
        gMmSave.inventory.items[ITS_MM_MASK_KEATON] = ITEM_MM_MASK_KEATON;
        break;
    case ITEM_MM_MASK_BREMEN:
        gMmSave.inventory.items[ITS_MM_MASK_BREMEN] = ITEM_MM_MASK_BREMEN;
        break;
    case ITEM_MM_MASK_BUNNY:
        gMmSave.inventory.items[ITS_MM_MASK_BUNNY] = ITEM_MM_MASK_BUNNY;
        break;
    case ITEM_MM_MASK_DON_GERO:
        gMmSave.inventory.items[ITS_MM_MASK_DON_GERO] = ITEM_MM_MASK_DON_GERO;
        break;
    case ITEM_MM_MASK_SCENTS:
        gMmSave.inventory.items[ITS_MM_MASK_SCENTS] = ITEM_MM_MASK_SCENTS;
        break;
    case ITEM_MM_MASK_GORON:
        gMmSave.inventory.items[ITS_MM_MASK_GORON] = ITEM_MM_MASK_GORON;
        break;
    case ITEM_MM_MASK_ROMANI:
        gMmSave.inventory.items[ITS_MM_MASK_ROMANI] = ITEM_MM_MASK_ROMANI;
        break;
    case ITEM_MM_MASK_CIRCUS:
        gMmSave.inventory.items[ITS_MM_MASK_CIRCUS] = ITEM_MM_MASK_CIRCUS;
        break;
    case ITEM_MM_MASK_KAFEI:
        gMmSave.inventory.items[ITS_MM_MASK_KAFEI] = ITEM_MM_MASK_KAFEI;
        break;
    case ITEM_MM_MASK_COUPLE:
        gMmSave.inventory.items[ITS_MM_MASK_COUPLE] = ITEM_MM_MASK_COUPLE;
        break;
    case ITEM_MM_MASK_TRUTH:
        gMmSave.inventory.items[ITS_MM_MASK_TRUTH] = ITEM_MM_MASK_TRUTH;
        break;
    case ITEM_MM_MASK_ZORA:
        gMmSave.inventory.items[ITS_MM_MASK_ZORA] = ITEM_MM_MASK_ZORA;
        break;
    case ITEM_MM_MASK_KAMARO:
        gMmSave.inventory.items[ITS_MM_MASK_KAMARO] = ITEM_MM_MASK_KAMARO;
        break;
    case ITEM_MM_MASK_GIBDO:
        gMmSave.inventory.items[ITS_MM_MASK_GIBDO] = ITEM_MM_MASK_GIBDO;
        break;
    case ITEM_MM_MASK_GARO:
        gMmSave.inventory.items[ITS_MM_MASK_GARO] = ITEM_MM_MASK_GARO;
        break;
    case ITEM_MM_MASK_CAPTAIN:
        gMmSave.inventory.items[ITS_MM_MASK_CAPTAIN] = ITEM_MM_MASK_CAPTAIN;
        break;
    case ITEM_MM_MASK_GIANT:
        gMmSave.inventory.items[ITS_MM_MASK_GIANT] = ITEM_MM_MASK_GIANT;
        break;
    case ITEM_MM_MASK_FIERCE_DEITY:
        gMmSave.inventory.items[ITS_MM_MASK_FIERCE_DEITY] = ITEM_MM_MASK_FIERCE_DEITY;
        break;
    case ITEM_MM_MAGIC_UPGRADE:
        gMmSave.playerData.magicAcquired = 1;
#if defined(GAME_MM)
        gSave.playerData.magicLevel = 0;
        gSave.playerData.magic = 0x30;
        gSaveContext.magicTarget = 0x30;
#else
        gMmSave.playerData.magicLevel = 1;
        gMmSave.playerData.magic = 0x30;
#endif
        break;
    case ITEM_MM_MAGIC_UPGRADE2:
        gMmSave.playerData.doubleMagic = 1;
#if defined(GAME_MM)
        gSave.playerData.magicLevel = 0;
        gSave.playerData.magic = 0x60;
        gSaveContext.magicTarget = 0x60;
#else
        gMmSave.playerData.magicLevel = 2;
        gMmSave.playerData.magic = 0x60;
#endif
        break;
    case ITEM_MM_SWORD_KOKIRI:
        addSword(1);
        break;
    case ITEM_MM_SWORD_RAZOR:
        addSword(2);
        break;
    case ITEM_MM_SWORD_GILDED:
        addSword(3);
        break;
    case ITEM_MM_SHIELD_HERO:
        addShield(1);
        break;
    case ITEM_MM_SHIELD_MIRROR:
        addShield(2);
        break;
    case ITEM_MM_BOMB_BAG:
        addBombBag(1);
        break;
    case ITEM_MM_BOMB_BAG2:
        addBombBag(2);
        break;
    case ITEM_MM_BOMB_BAG3:
        addBombBag(3);
        break;
    case ITEM_MM_BOW:
    case ITEM_MM_QUIVER:
        addBowQuiver(1);
        break;
    case ITEM_MM_QUIVER2:
        addBowQuiver(2);
        break;
    case ITEM_MM_QUIVER3:
        addBowQuiver(3);
        break;
    case ITEM_MM_WALLET2:
        gMmSave.inventory.upgrades.wallet = 1;
        break;
    case ITEM_MM_WALLET3:
        gMmSave.inventory.upgrades.wallet = 2;
        break;
    case ITEM_MM_SONG_AWAKENING:
        gMmSave.inventory.questItems.songAwakening = 1;
        break;
    case ITEM_MM_SONG_GORON:
        gMmSave.inventory.questItems.songLullaby = 1;
        break;
    case ITEM_MM_SONG_ZORA:
        gMmSave.inventory.questItems.songNewWave = 1;
        break;
    case ITEM_MM_SOMG_EMPTINESS:
        gMmSave.inventory.questItems.songEmpty = 1;
        break;
    case ITEM_MM_SONG_ORDER:
        gMmSave.inventory.questItems.songOrder = 1;
        break;
    case ITEM_MM_SONG_TIME:
        gMmSave.inventory.questItems.songTime = 1;
        break;
    case ITEM_MM_SONG_HEALING:
        gMmSave.inventory.questItems.songHealing = 1;
        break;
    case ITEM_MM_SONG_EPONA:
        gMmSave.inventory.questItems.songEpona = 1;
        break;
    case ITEM_MM_SONG_SOARING:
        gMmSave.inventory.questItems.songSoaring = 1;
        break;
    case ITEM_MM_SONG_STORMS:
        gMmSave.inventory.questItems.songStorms = 1;
        break;
    case ITEM_MM_SONG_GORON_HALF:
        gMmSave.inventory.questItems.songLullabyIntro = 1;
        break;
    }
}
