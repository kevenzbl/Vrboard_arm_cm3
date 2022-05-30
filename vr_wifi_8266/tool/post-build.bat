@@echo off
set version=%date:~0,4%%date:~5,2%%date:~8,2%
set axfPath=./obj/binocular.axf
set outbinname=binocular.bin
set outbin=%outbinname%
set b2bPath=.\b2b
set outBinWithCheckPath=d:/fw
@@echo on
fromelf --bin --output=%outbin% %axfPath%

@@echo off
echo Completed !!!

@exit /b 0