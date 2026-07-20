#ifndef MOD_ASSISTANT_H
#define MOD_ASSISTANT_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum
{
    ASSISTANT_GOSSIP_HEIRLOOM        = 100,
    ASSISTANT_GOSSIP_GLYPH           = 200,
    ASSISTANT_GOSSIP_GEM             = 400,
    ASSISTANT_GOSSIP_ELIXIRS         = 500,
    ASSISTANT_GOSSIP_FOOD            = 600,
    ASSISTANT_GOSSIP_ENCHANTS        = 700,
    ASSISTANT_GOSSIP_CONTAINER       = 800,
    ASSISTANT_GOSSIP_FLIGHT_PATHS    = 900,
    ASSISTANT_GOSSIP_UTILITIES       = 1000,
    ASSISTANT_GOSSIP_PROFESSIONS     = 1100,
    ASSISTANT_GOSSIP_INSTANCES       = 1200,

    ASSISTANT_GOSSIP_TEXT            = 48,

    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR  = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER  = 9000002,
    ASSISTANT_VENDOR_GLYPH           = 9000003,
    ASSISTANT_VENDOR_GEM             = 9000023,
    ASSISTANT_VENDOR_ELIXIR          = 9000030,
    ASSISTANT_VENDOR_FOOD            = 9000033,
    ASSISTANT_VENDOR_ENCHANT         = 9000034,
    ASSISTANT_VENDOR_CONTAINER       = 9000045,

    PROFESSION_LEVEL_APPRENTICE      = 75,
    PROFESSION_LEVEL_JOURNEYMAN      = 150,
    PROFESSION_LEVEL_EXPERT          = 225,
    PROFESSION_LEVEL_ARTISAN         = 300,
    PROFESSION_LEVEL_MASTER          = 375,
    PROFESSION_LEVEL_GRAND_MASTER    = 450,

    INSTANCE_TYPE_HEROIC             = 0,
    INSTANCE_TYPE_RAID               = 1,

    GLYPH_WARRIOR                    = 0,
    GLYPH_PALADIN                    = 1,
    GLYPH_HUNTER                     = 2,
    GLYPH_ROGUE                      = 3,
    GLYPH_PRIEST                     = 4,
    GLYPH_DEATH_KNIGHT               = 5,
    GLYPH_SHAMAN                     = 6,
    GLYPH_MAGE                       = 7,
    GLYPH_WARLOCK                    = 8,
    GLYPH_DRUID                      = 9
};

#define GOSSIP_HEIRLOOMS "我想要传家宝"
#define GOSSIP_HEIRLOOMS_WEAPONS "我想要武器"
#define GOSSIP_HEIRLOOMS_ARMOR "我想要护甲"
#define GOSSIP_HEIRLOOMS_OTHER "我想要其他东西"

#define GOSSIP_GLYPHS "我想要雕文"
#define GOSSIP_GLYPHS_MAJOR "我想要一些大雕文"
#define GOSSIP_GLYPHS_MINOR "我想要一些小雕文"

#define GOSSIP_GEMS "我想要宝石"
#define GOSSIP_GEMS_META "我想要一些多彩宝石"
#define GOSSIP_GEMS_RED "我想要一些红色宝石"
#define GOSSIP_GEMS_BLUE "我想要一些蓝色宝石"
#define GOSSIP_GEMS_YELLOW "我想要一些黄色宝石"
#define GOSSIP_GEMS_PURPLE "我想要一些紫色宝石"
#define GOSSIP_GEMS_GREEN "我想要一些绿色宝石"
#define GOSSIP_GEMS_ORANGE "我想要一些橙色宝石"

#define GOSSIP_ELIXIRS "我想要药剂"
#define GOSSIP_ELIXIRS_BATTLE "我想要一些战斗药剂"
#define GOSSIP_ELIXIRS_GUARDIAN "我想要一些守护药剂"
#define GOSSIP_ELIXIRS_FLASK "我想要一些合剂"

#define GOSSIP_FOOD "我想要食物"

#define GOSSIP_ENCHANTS "我想要附魔"
#define GOSSIP_ENCHANTS_WEAPON "我想要武器附魔"
#define GOSSIP_ENCHANTS_HEAD "我想要头部附魔"
#define GOSSIP_ENCHANTS_SHOULDER "我想要肩部附魔"
#define GOSSIP_ENCHANTS_CHEST "我想要胸部附魔"
#define GOSSIP_ENCHANTS_BRACER "我想要护腕附魔"
#define GOSSIP_ENCHANTS_GLOVES "我想要手套附魔"
#define GOSSIP_ENCHANTS_WAIST "我想要腰带附魔"
#define GOSSIP_ENCHANTS_LEGS "我想要腿部附魔"
#define GOSSIP_ENCHANTS_FEET "我想要鞋子附魔"
#define GOSSIP_ENCHANTS_CLOAK "我想要披风附魔"
#define GOSSIP_ENCHANTS_SHIELD "我想要盾牌附魔"

#define GOSSIP_CONTAINERS "我想要容器(背包)"

#define GOSSIP_UTILITIES "我想要实用工具"
#define GOSSIP_UTILITIES_NAME "我想修改我的名字"
#define GOSSIP_UTILITIES_APPEARANCE "我想修改我的外貌"
#define GOSSIP_UTILITIES_RACE "我想修改我的种族"
#define GOSSIP_UTILITIES_FACTION "我想修改我的阵营"
#define GOSSIP_UTILITIES_IN_PROGRESS "您必须完成之前激活的功能，然后才能尝试执行另一项功能。"
#define GOSSIP_UTILITIES_DONE "您现在可以小退(登出)来继续使用已激活的功能。"

#define GOSSIP_FLIGHT_PATHS "我想要解锁飞行点"
#define GOSSIP_FLIGHT_PATHS_KALIMDOR_EASTERN_KINGDOMS "卡利姆多 ＆ 东部王国"
#define GOSSIP_FLIGHT_PATHS_OUTLAND "外域"
#define GOSSIP_FLIGHT_PATHS_NORTHREND "诺森德"

#define GOSSIP_PROFESSIONS "我需要专业技能方面的帮助"
#define GOSSIP_PROFESSIONS_CHOOSE "我需要提升这项技能："
#define GOSSIP_PROFESSIONS_FIRST_AID "急救"
#define GOSSIP_PROFESSIONS_BLACKSMITHING "锻造"
#define GOSSIP_PROFESSIONS_LEATHERWORKING "制皮"
#define GOSSIP_PROFESSIONS_ALCHEMY "炼金术"
#define GOSSIP_PROFESSIONS_HERBALISM "草药学"
#define GOSSIP_PROFESSIONS_COOKING "烹饪"
#define GOSSIP_PROFESSIONS_MINING "采矿"
#define GOSSIP_PROFESSIONS_TAILORING "裁缝"
#define GOSSIP_PROFESSIONS_ENGINEERING "工程学"
#define GOSSIP_PROFESSIONS_ENCHANTING "附魔"
#define GOSSIP_PROFESSIONS_FISHING "钓鱼"
#define GOSSIP_PROFESSIONS_SKINNING "剥皮"
#define GOSSIP_PROFESSIONS_INSCRIPTION "铭文"
#define GOSSIP_PROFESSIONS_JEWELCRAFTING "珠宝加工"

#define GOSSIP_INSTANCES "我想要重置副本"
#define GOSSIP_INSTANCES_HEROIC "我想要重置英雄地下城"
#define GOSSIP_INSTANCES_RAID "我想要重置团队副本"
#define GOSSIP_INSTANCES_PLAYER "仅针对我自己"
#define GOSSIP_INSTANCES_GROUP "针对我整个队伍/团队"
#define GOSSIP_INSTANCES_HEROIC_RESET "所有英雄地下城已重置。"
#define GOSSIP_INSTANCES_HEROIC_GROUP_RESET "你队伍的所有英雄地下城已重置。"
#define GOSSIP_INSTANCES_RAID_RESET "所有团队副本已重置。"
#define GOSSIP_INSTANCES_RAID_GROUP_RESET "你队伍的所有团队副本已重置。"

#define GOSSIP_CONTINUE_TRANSACTION "你想继续这次交易吗？"
#define GOSSIP_PREVIOUS_PAGE "上一页"

class Assistant : public CreatureScript, WorldScript
{
public:
    Assistant();

    // CreatureScript
    bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) override;
    bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override;

    // WorldScript
    void OnAfterConfigLoad(bool /*reload*/) override;

private:
    bool HeirloomsEnabled;
    bool GlyphsEnabled;
    bool GemsEnabled;
    bool ElixirsEnabled;
    bool FoodEnabled;
    bool EnchantsEnabled;
    bool ContainersEnabled;

    uint32 GetGlyphId(uint32 /*id*/, bool /*major*/);

    // Utilities
    bool UtilitiesEnabled;
    uint32 NameChangeCost;
    uint32 CustomizeCost;
    uint32 RaceChangeCost;
    uint32 FactionChangeCost;

    bool HasLoginFlag(Player* /*player*/);
    void SetLoginFlag(Player* /*player*/, AtLoginFlags /*flag*/, uint32 /*cost*/);

    // Flight Paths
    bool FlightPathsEnabled[EXPANSION_WRATH_OF_THE_LICH_KING + 1];
    uint32 FlightPathsRequiredLevel[EXPANSION_WRATH_OF_THE_LICH_KING + 1];
    uint32 FlightPathsCost[EXPANSION_WRATH_OF_THE_LICH_KING + 1];

    bool CanUnlockFlightPaths(Player* /*player*/);
    std::vector<int> GetAvailableFlightPaths(Player* /*player*/, uint8 /*expansion*/);
    bool HasAvailableFlightPaths(Player* /*player*/, uint8 /*expansion*/);
    void UnlockFlightPaths(Player* /*player*/, uint8 /*expansion*/);

    // Professions
    bool ApprenticeProfessionEnabled;
    uint32 ApprenticeProfessionCost;
    bool JourneymanProfessionEnabled;
    uint32 JourneymanProfessionCost;
    bool ExpertProfessionEnabled;
    uint32 ExpertProfessionCost;
    bool ArtisanProfessionEnabled;
    uint32 ArtisanProfessionCost;
    bool MasterProfessionEnabled;
    uint32 MasterProfessionCost;
    bool GrandMasterProfessionEnabled;
    uint32 GrandMasterProfessionCost;

    void ListProfession(Player* /*player*/, uint32 /*id*/);
    void SetProfession(Player* /*player*/, uint32 /*id*/);
    bool HasValidProfession(Player* /*player*/);
    bool IsValidProfession(Player* /*player*/, uint32 /*id*/);
    uint32 GetProfessionCost(Player* /*player*/, uint32 /*id*/);

    // Instances
    bool HeroicInstanceEnabled;
    uint32 HeroicInstanceCost;
    bool RaidInstanceEnabled;
    uint32 RaidInstanceCost;

    bool CanResetInstances(Player* /*player*/);
    bool HasSavedInstances(Player* /*player*/, uint8 /*type*/);
    void ResetInstances(Player* /*player*/, uint8 /*type*/);
};

#endif
