zcc +msx -create-app -O3 -subtype=msxdos snapbak.c -bn SNAPBAK.COM
del SNAPBAK.img
move /y SNAPBAK.COM bin
cd bin
START /WAIT DISKMGR.exe -A -F -C SNAPBAK.DSK SNAPBAK.COM
cd ../
