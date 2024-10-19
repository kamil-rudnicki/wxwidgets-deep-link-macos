mkdir build
cd build
cmake ..

make
./DeepLinkTest.app/Contents/MacOS/DeepLinkTest
open "tc3://login/yourtoken"