#ifndef Result_h
#define Result_h

#include <Arduino.h>

#define X(name) name,
enum class EResult : uint16_t
{
  #include "CommonResults.h"
  Dummy_LastCommonResult,
  Dummy_FirstCommonFailure = 0x100,
  #include "CommonFailures.h"
  Dummy_LastCommonFailure,
  Dummy_FirstClassFailure = 0x1000,
};
#undef X


class Result
{  
  #define X(name) static const char _EResult_##name[] PROGMEM;
  #include "CommonResults.h"
  #include "CommonFailures.h"
  #undef X

  static const char* const c_EnumNames_CommonResults[] PROGMEM;
  static const char* const c_EnumNames_CommonFailures[] PROGMEM;

public:
  static const __FlashStringHelper* GetText (EResult i_Result);
};

#endif
