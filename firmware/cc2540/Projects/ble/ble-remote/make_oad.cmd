@echo off

for /F "usebackq tokens=1,2 delims==" %%i in (`wmic os get LocalDateTime /VALUE 2^>NUL`) do if '.%%i.'=='.LocalDateTime.' set ldt=%%j
set ldt=%ldt:~0,4%-%ldt:~4,2%-%ldt:~6,2%_%ldt:~8,2%.%ldt:~10,2%.%ldt:~12,6%
echo Local date is [%ldt%]

..\common\cc2540\cc254x_sim2bin.exe .\CC2540DB\CC2540-OAD-ImgA\Exe\SimpleBLEPeripheral.sim ble-telly-a-%ldt%.bin
..\common\cc2540\cc254x_sim2bin.exe .\CC2540DB\CC2540-OAD-ImgB\Exe\SimpleBLEPeripheral.sim ble-telly-b-%ldt%.bin
