#include "Result.h"

//--------------------------------------------------------------------
#define X(name) const char Result::_EResult_##name[] PROGMEM = #name;
#include "CommonResults.h"
#include "CommonFailures.h"
#undef X

//--------------------------------------------------------------------
#define X(name) _EResult_##name,
const char* const Result::c_EnumNames_CommonResults[] PROGMEM =
{
  #include "CommonResults.h"
};
const char* const Result::c_EnumNames_CommonFailures[] PROGMEM =
{
  #include "CommonFailures.h"
};
#undef X

//--------------------------------------------------------------------
const __FlashStringHelper* Result::GetText (EResult i_Result)
{
  if (i_Result < EResult::Dummy_LastCommonResult)
    return (const __FlashStringHelper*)pgm_read_ptr(&c_EnumNames_CommonResults[(uint16_t)i_Result]);
  if (i_Result > EResult::Dummy_FirstCommonFailure
  &&  i_Result < EResult::Dummy_LastCommonFailure)
    return (const __FlashStringHelper*)pgm_read_ptr(&c_EnumNames_CommonFailures[(uint16_t)i_Result - (uint16_t)EResult::Dummy_FirstCommonFailure - 1]);
  return F("<invalid>");
}
