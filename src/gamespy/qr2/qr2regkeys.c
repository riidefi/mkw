
#include "qr2regkeys.h"

#include "../common/gsDebug.h"
#include "../common/gsStringUtil.h"

#ifdef __MWERKS__ // CodeWarrior requires prototypes
void qr2_register_keyW(int keyid, const unsigned short* key);
void qr2_register_keyA(int keyid, const char* key);
#endif

const char* qr2_registered_key_list[MAX_REGISTERED_KEYS] = {
    "",              // 0 is reserved
    "hostname",      // 1
    "gamename",      // 2
    "gamever",       // 3
    "hostport",      // 4
    "mapname",       // 5
    "gametype",      // 6
    "gamevariant",   // 7
    "numplayers",    // 8
    "numteams",      // 9
    "maxplayers",    // 10
    "gamemode",      // 11
    "teamplay",      // 12
    "fraglimit",     // 13
    "teamfraglimit", // 14
    "timeelapsed",   // 15
    "timelimit",     // 16
    "roundtime",     // 17
    "roundelapsed",  // 18
    "password",      // 19
    "groupid",       // 20
    "player_",       // 21
    "score_",        // 22
    "skill_",        // 23
    "ping_",         // 24
    "team_",         // 25
    "deaths_",       // 26
    "pid_",          // 27
    "team_t",        // 28
    "score_t",       // 29
    "nn_groupid",    // 30

    // Query From Master Only keys
    "country", // 31
    "region"   // 32
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

gsi_bool qr2_internal_is_master_only_key(const char* keyname) {
  if (strcmp(keyname, qr2_registered_key_list[COUNTRY_KEY]) == 0 ||
      strcmp(keyname, qr2_registered_key_list[REGION_KEY]) == 0)
    return gsi_true;

  return gsi_false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void qr2_register_keyA(int keyid, const char* key) {
  gsDebugFormat(GSIDebugCat_QR2, GSIDebugType_Misc, GSIDebugLevel_StackTrace,
                "qr2_register_keyA()\r\n");

  // Verify the key range
  if (keyid < NUM_RESERVED_KEYS || keyid > MAX_REGISTERED_KEYS) {
    gsDebugFormat(GSIDebugCat_QR2, GSIDebugType_Misc, GSIDebugLevel_WarmError,
                  "Attempted to register invalid key %d - %s\r\n", keyid, key);
    return;
  }

  gsDebugFormat(GSIDebugCat_QR2, GSIDebugType_Misc, GSIDebugLevel_Comment,
                "Registered key %d - %s\r\n", keyid, key);

  qr2_registered_key_list[keyid] = key;
}
