if not exist build\ ( md build )
cd build
cmake -G "Ninja" ..
cmake --build . --parallel
cd ..
