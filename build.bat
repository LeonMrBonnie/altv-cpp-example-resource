@echo on

mkdir build
pushd build
cmake -G"Visual Studio 16" -A x64 ..
cmake --build . --config Release
popd

mkdir dist
copy build\Release\cpp-resource.dll dist
copy build\Release\cpp-resource.pdb dist