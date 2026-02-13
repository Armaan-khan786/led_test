*** Settings ***
Library    serial_lib.py

*** Test Cases ***

Boot Test
    ${data}=    Send Command    PING
    Should Contain    ${data}    RUNNING

LED ON Test
    ${data}=    Send Command    LED_ON
    Should Contain    ${data}    LED_IS_ON

Fail Case Test
    ${data}=    Send Command    BAD_CMD
    Should Contain    ${data}    SUCCESS