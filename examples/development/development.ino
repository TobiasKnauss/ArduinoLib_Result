#include <Streaming.h>
#include <Result.h>

void setup()
{
  Serial.begin (9600);

  Serial.println (Result::GetText (EResult::None));
  Serial.println (Result::GetText (EResult::SUCCESS));
  Serial.println (Result::GetText (EResult::InProgress));
  Serial.println (Result::GetText ((EResult)44));
  Serial.println (Result::GetText (EResult::FAIL_Buffer_GetBytes));
  Serial.println (Result::GetText (EResult::FAIL_Buffer_Overlap));
  Serial.println (Result::GetText ((EResult)333));

  for (uint16_t index = 0; index < (uint16_t)EResult::Dummy_LastCommonFailure; index++)
    Serial << _HEX4(index) << " : " << Result::GetText ((EResult)index) << endl;
}

void loop ()
{
}
